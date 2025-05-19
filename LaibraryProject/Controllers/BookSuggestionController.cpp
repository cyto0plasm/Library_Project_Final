#include "BookSuggestionController.h"
#include "../Database/DBConnection.h"

using namespace System::Data::SQLite;

namespace LaibraryProject {

	BookSuggestionModel^ BookSuggestionController::Create(BookSuggestionModel^ suggestion) {
		auto conn = DBConnection::GetConnection();
		conn->Open();

		auto cmd = gcnew SQLiteCommand(
			"INSERT INTO book_Suggestion (user_id, student_id, suggestion) "
			"VALUES (@user_id, @student_id, @suggestion); "
			"SELECT last_insert_rowid();", conn);

		cmd->Parameters->AddWithValue("@user_id", suggestion->UserId.HasValue ? safe_cast<Object^>(suggestion->UserId.Value) : DBNull::Value);
		cmd->Parameters->AddWithValue("@student_id", suggestion->StudentId);
		cmd->Parameters->AddWithValue("@suggestion", suggestion->Suggestion);

		int id = Convert::ToInt32(cmd->ExecuteScalar());
		conn->Close();

		suggestion->Id = id;
		return suggestion;
	}

	BookSuggestionModel^ BookSuggestionController::GetById(int id) {
		SQLiteDataReader^ reader = nullptr;
		auto conn = DBConnection::GetConnection();
		conn->Open();

		try {
			auto cmd = gcnew SQLiteCommand(
				"SELECT id, user_id, student_id, suggestion, created_at, updated_at "
				"FROM book_Suggestion WHERE id = @id;", conn);
			cmd->Parameters->AddWithValue("@id", id);

			reader = cmd->ExecuteReader();
			if (reader->Read()) {
				auto suggestion = gcnew BookSuggestionModel();
				suggestion->Id = reader->GetInt32(0);
				suggestion->UserId = reader->IsDBNull(1) ? Nullable<int>() : reader->GetInt32(1);
				suggestion->StudentId = reader->GetInt32(2);
				suggestion->Suggestion = reader->GetString(3);
				suggestion->CreatedAt = DateTime::Parse(reader->GetString(4));
				suggestion->UpdatedAt = DateTime::Parse(reader->GetString(5));
				return suggestion;
			}
			return nullptr;
		}
		finally {
			if (reader) reader->Close();
			conn->Close();
		}
	}

	List<BookSuggestionModel^>^ BookSuggestionController::GetAll() {
		auto list = gcnew List<BookSuggestionModel^>();
		SQLiteDataReader^ reader = nullptr;
		auto conn = DBConnection::GetConnection();
		conn->Open();

		try {
			auto cmd = gcnew SQLiteCommand(
				"SELECT id, user_id, student_id, suggestion, created_at, updated_at "
				"FROM book_Suggestion;", conn);
			reader = cmd->ExecuteReader();

			while (reader->Read()) {
				auto suggestion = gcnew BookSuggestionModel();
				suggestion->Id = reader->GetInt32(0);
				suggestion->UserId = reader->IsDBNull(1) ? Nullable<int>() : reader->GetInt32(1);
				suggestion->StudentId = reader->GetInt32(2);
				suggestion->Suggestion = reader->GetString(3);
				suggestion->CreatedAt = DateTime::Parse(reader->GetString(4));
				suggestion->UpdatedAt = DateTime::Parse(reader->GetString(5));
				list->Add(suggestion);
			}
		}
		finally {
			if (reader) reader->Close();
			conn->Close();
		}
		return list;
	}

	bool BookSuggestionController::Update(BookSuggestionModel^ suggestion) {
		suggestion->UpdatedAt = DateTime::Now;
		auto conn = DBConnection::GetConnection();
		conn->Open();

		auto cmd = gcnew SQLiteCommand(
			"UPDATE book_Suggestion SET user_id = @user_id, student_id = @student_id, "
			"suggestion = @suggestion, updated_at = @updated_at WHERE id = @id;", conn);

		cmd->Parameters->AddWithValue("@user_id", suggestion->UserId.HasValue ? safe_cast<Object^>(suggestion->UserId.Value) : DBNull::Value);
		cmd->Parameters->AddWithValue("@student_id", suggestion->StudentId);
		cmd->Parameters->AddWithValue("@suggestion", suggestion->Suggestion);
		cmd->Parameters->AddWithValue("@updated_at", suggestion->UpdatedAt.ToString("yyyy-MM-dd HH:mm:ss"));
		cmd->Parameters->AddWithValue("@id", suggestion->Id);

		int rows = cmd->ExecuteNonQuery();
		conn->Close();
		return rows > 0;
	}

	bool BookSuggestionController::Delete(int id) {
		if (id <= 0) return false;

		auto conn = DBConnection::GetConnection();
		conn->Open();

		auto cmd = gcnew SQLiteCommand("DELETE FROM book_Suggestion WHERE id = @id;", conn);
		cmd->Parameters->AddWithValue("@id", id);

		int rows = cmd->ExecuteNonQuery();
		conn->Close();
		return rows > 0;
	}

	List<StudentModel^>^ BookSuggestionController::SearchStudentsWithSuggestions(System::String^ searchTerm, int userId)
	{
		auto list = gcnew List<StudentModel^>();
		SQLiteDataReader^ reader = nullptr;
		auto conn = DBConnection::GetConnection();
		conn->Open();

		try {
			auto cmd = gcnew SQLiteCommand(
				"SELECT id, name, seatNumber, department, email FROM student "
				"WHERE user_id = @uid AND (name LIKE @search OR seatNumber LIKE @search OR email LIKE @search) "
				"AND id IN (SELECT DISTINCT student_id FROM book_Suggestion WHERE user_id = @uid);",
				conn);

			// Set parameters BEFORE executing the reader
			cmd->Parameters->AddWithValue("@uid", userId);
			cmd->Parameters->AddWithValue("@search", "%" + searchTerm + "%");

			reader = cmd->ExecuteReader();

			while (reader->Read()) {
				auto student = gcnew StudentModel();
				student->Id = reader->GetInt32(0);
				student->Name = reader->GetString(1);
				student->SeatNumber = reader->GetInt32(2);
				student->Department = reader->GetString(3);
				student->Email = reader->GetString(4);

				list->Add(student);
			}
		}
		finally {
			if (reader) reader->Close();
			conn->Close();
		}

		return list;
	}
	List<StudentModel^>^ BookSuggestionController::SearchStudents(System::String^ searchTerm, int userId)
	{
		auto list = gcnew List<StudentModel^>();
		SQLiteDataReader^ reader = nullptr;
		auto conn = DBConnection::GetConnection();
		conn->Open();

		try {
			auto cmd = gcnew SQLiteCommand(
				"SELECT id, name, seatNumber, department, email FROM student "
				"WHERE user_id = @uid AND (name LIKE @search OR seatNumber LIKE @search OR email LIKE @search);",
				conn);

			// ✅ Set parameters BEFORE executing the reader
			cmd->Parameters->AddWithValue("@uid", userId);
			cmd->Parameters->AddWithValue("@search", "%" + searchTerm + "%");

			reader = cmd->ExecuteReader();

			while (reader->Read()) {
				auto student = gcnew StudentModel();
				student->Id = reader->GetInt32(0);
				student->Name = reader->GetString(1);
				student->SeatNumber = reader->GetInt32(2);
				student->Department = reader->GetString(3);
				student->Email = reader->GetString(4);

				list->Add(student);
			}
		}
		finally {
			if (reader) reader->Close();
			conn->Close();
		}

		return list;
	}

	List<BookSuggestionModel^>^ BookSuggestionController::GetByStudentId(int studentId) {
		auto list = gcnew List<BookSuggestionModel^>();
		SQLiteDataReader^ reader = nullptr;
		auto conn = DBConnection::GetConnection();
		conn->Open();

		try {
			auto cmd = gcnew SQLiteCommand(
				"SELECT id, user_id, student_id, suggestion, created_at, updated_at "
				"FROM book_Suggestion WHERE student_id = @student_id;", conn);
			cmd->Parameters->AddWithValue("@student_id", studentId);
			reader = cmd->ExecuteReader();

			while (reader->Read()) {
				auto suggestion = gcnew BookSuggestionModel();
				suggestion->Id = reader->GetInt32(0);
				suggestion->UserId = reader->IsDBNull(1) ? Nullable<int>() : reader->GetInt32(1);
				suggestion->StudentId = reader->GetInt32(2);
				suggestion->Suggestion = reader->GetString(3);
				suggestion->CreatedAt = DateTime::Parse(reader->GetString(4));
				suggestion->UpdatedAt = DateTime::Parse(reader->GetString(5));
				list->Add(suggestion);
			}
		}
		finally {
			if (reader) reader->Close();
			conn->Close();
		}
		return list;
	}

	List<BookSuggestionModel^>^ BookSuggestionController::GetByUserId(int userId) {
		auto list = gcnew List<BookSuggestionModel^>();
		SQLiteDataReader^ reader = nullptr;
		auto conn = DBConnection::GetConnection();
		conn->Open();

		try {
			auto cmd = gcnew SQLiteCommand(
				"SELECT id, user_id, student_id, suggestion, created_at, updated_at "
				"FROM book_Suggestion WHERE user_id = @user_id;", conn);
			cmd->Parameters->AddWithValue("@user_id", userId);
			reader = cmd->ExecuteReader();

			while (reader->Read()) {
				auto suggestion = gcnew BookSuggestionModel();
				suggestion->Id = reader->GetInt32(0);
				suggestion->UserId = reader->IsDBNull(1) ? Nullable<int>() : reader->GetInt32(1);
				suggestion->StudentId = reader->GetInt32(2);
				suggestion->Suggestion = reader->GetString(3);
				suggestion->CreatedAt = DateTime::Parse(reader->GetString(4));
				suggestion->UpdatedAt = DateTime::Parse(reader->GetString(5));
				list->Add(suggestion);
			}
		}
		finally {
			if (reader) reader->Close();
			conn->Close();
		}
		return list;
	}
}