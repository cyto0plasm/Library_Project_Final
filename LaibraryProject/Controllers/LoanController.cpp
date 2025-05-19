#include "../Models/LoanModel.h"
#include "../Controllers/BookController.h"
#include "../Models/StudentModel.h"
#include "../Models/Book.h" 
#include "../Database/DBConnection.h"
#include "LoanController.h"

using namespace System::Data::SQLite;

namespace LaibraryProject {


    LoanModel^ LoanController::Create(LoanModel^ loan) {
        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand(
            "INSERT INTO loan (student_id, book_id, loan_date, return_date, status, user_id) "
            "VALUES (@student_id, @book_id, @loan_date, @return_date, @status, @user_id); "
            "SELECT last_insert_rowid();", conn);

        cmd->Parameters->AddWithValue("@student_id", loan->StudentId);
        cmd->Parameters->AddWithValue("@book_id", loan->BookId);
        cmd->Parameters->AddWithValue("@loan_date", loan->LoanDate.ToString("yyyy-MM-dd"));
        cmd->Parameters->AddWithValue("@return_date", loan->ReturnDate.ToString("yyyy-MM-dd"));
        cmd->Parameters->AddWithValue("@status", loan->Status);
        cmd->Parameters->AddWithValue("@user_id", loan->UserId.HasValue ? safe_cast<Object^>(loan->UserId.Value) : DBNull::Value);

        int id = Convert::ToInt32(cmd->ExecuteScalar());
        conn->Close();

        if (id > 0) {
            auto bookController = gcnew BooksController();
            auto book = bookController->GetById(loan->BookId);
            if (book != nullptr) {
                book->LoanId = id;
                bookController->Update(book);
            }
        }

        loan->Id = id;
        return loan;
    }

    LoanModel^ LoanController::GetById(int id) {
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT id, student_id, book_id, loan_date, return_date, status, created_at, updated_at, user_id "
                "FROM loan WHERE id = @id;", conn);
            cmd->Parameters->AddWithValue("@id", id);

            reader = cmd->ExecuteReader();
            if (reader->Read()) {
                auto loan = gcnew LoanModel();
                loan->Id = reader->GetInt32(0);
                loan->StudentId = reader->GetInt32(1);
                loan->BookId = reader->GetInt32(2);
                loan->LoanDate = DateTime::Parse(reader->GetString(3));
                loan->ReturnDate = DateTime::Parse(reader->GetString(4));
                loan->Status = reader->GetString(5);
                loan->CreatedAt = DateTime::Parse(reader->GetString(6));
                loan->UpdatedAt = DateTime::Parse(reader->GetString(7));
                loan->UserId = reader->IsDBNull(8) ? Nullable<int>() : reader->GetInt32(8);
                return loan;
            }
            return nullptr;
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
    }

    List<LoanModel^>^ LoanController::GetAll() {
        auto list = gcnew List<LoanModel^>();
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT id, student_id, book_id, loan_date, return_date, status, created_at, updated_at, user_id "
                "FROM loan;", conn);
            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                auto loan = gcnew LoanModel();
                loan->Id = reader->GetInt32(0);
                loan->StudentId = reader->GetInt32(1);
                loan->BookId = reader->GetInt32(2);
                loan->LoanDate = DateTime::Parse(reader->GetString(3));
                loan->ReturnDate = DateTime::Parse(reader->GetString(4));
                loan->Status = reader->GetString(5);
                loan->CreatedAt = DateTime::Parse(reader->GetString(6));
                loan->UpdatedAt = DateTime::Parse(reader->GetString(7));
                loan->UserId = reader->IsDBNull(8) ? Nullable<int>() : reader->GetInt32(8);
                list->Add(loan);
            }
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
        return list;
    }

    bool LoanController::Update(LoanModel^ loan) {
        loan->UpdatedAt = DateTime::Now;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand(
            "UPDATE loan SET student_id = @student_id, book_id = @book_id, "
            "loan_date = @loan_date, return_date = @return_date, status = @status, "
            "updated_at = @updated_at, user_id = @user_id WHERE id = @id;", conn);

        cmd->Parameters->AddWithValue("@student_id", loan->StudentId);
        cmd->Parameters->AddWithValue("@book_id", loan->BookId);
        cmd->Parameters->AddWithValue("@loan_date", loan->LoanDate.ToString("yyyy-MM-dd"));
        cmd->Parameters->AddWithValue("@return_date", loan->ReturnDate.ToString("yyyy-MM-dd"));
        cmd->Parameters->AddWithValue("@status", loan->Status);
        cmd->Parameters->AddWithValue("@updated_at", loan->UpdatedAt.ToString("yyyy-MM-dd HH:mm:ss"));
        cmd->Parameters->AddWithValue("@user_id", loan->UserId.HasValue ? safe_cast<Object^>(loan->UserId.Value) : DBNull::Value);
        cmd->Parameters->AddWithValue("@id", loan->Id);

        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }

    bool LoanController::Delete(int id) {
        if (id <= 0) return false;

        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto loan = GetById(id);
        if (loan != nullptr) {
            auto bookController = gcnew BooksController();
            auto book = bookController->GetById(loan->BookId);
            if (book != nullptr && book->LoanId.HasValue && book->LoanId.Value == id) {
                book->LoanId = Nullable<int>();
                bookController->Update(book);
            }
        }

        auto cmd = gcnew SQLiteCommand("DELETE FROM loan WHERE id = @id;", conn);
        cmd->Parameters->AddWithValue("@id", id);

        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }

    List<LoanModel^>^ LoanController::GetByStudentId(int studentId) {
        auto list = gcnew List<LoanModel^>();
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT id, student_id, book_id, loan_date, return_date, status, created_at, updated_at, user_id "
                "FROM loan WHERE student_id = @student_id;", conn);
            cmd->Parameters->AddWithValue("@student_id", studentId);
            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                auto loan = gcnew LoanModel();
                loan->Id = reader->GetInt32(0);
                loan->StudentId = reader->GetInt32(1);
                loan->BookId = reader->GetInt32(2);
                loan->LoanDate = DateTime::Parse(reader->GetString(3));
                loan->ReturnDate = DateTime::Parse(reader->GetString(4));
                loan->Status = reader->GetString(5);
                loan->CreatedAt = DateTime::Parse(reader->GetString(6));
                loan->UpdatedAt = DateTime::Parse(reader->GetString(7));
                loan->UserId = reader->IsDBNull(8) ? Nullable<int>() : reader->GetInt32(8);
                list->Add(loan);
            }
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
        return list;
    }

    List<LoanModel^>^ LoanController::GetByBookId(int bookId) {
        auto list = gcnew List<LoanModel^>();
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT id, student_id, book_id, loan_date, return_date, status, created_at, updated_at, user_id "
                "FROM loan WHERE book_id = @book_id;", conn);
            cmd->Parameters->AddWithValue("@book_id", bookId);
            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                auto loan = gcnew LoanModel();
                loan->Id = reader->GetInt32(0);
                loan->StudentId = reader->GetInt32(1);
                loan->BookId = reader->GetInt32(2);
                loan->LoanDate = DateTime::Parse(reader->GetString(3));
                loan->ReturnDate = DateTime::Parse(reader->GetString(4));
                loan->Status = reader->GetString(5);
                loan->CreatedAt = DateTime::Parse(reader->GetString(6));
                loan->UpdatedAt = DateTime::Parse(reader->GetString(7));
                loan->UserId = reader->IsDBNull(8) ? Nullable<int>() : reader->GetInt32(8);
                list->Add(loan);
            }
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
        return list;
    }

    List<LoanModel^>^ LoanController::GetActiveLoans() {
        auto list = gcnew List<LoanModel^>();
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT id, student_id, book_id, loan_date, return_date, status, created_at, updated_at, user_id "
                "FROM loan WHERE status = 'active';", conn);
            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                auto loan = gcnew LoanModel();
                loan->Id = reader->GetInt32(0);
                loan->StudentId = reader->GetInt32(1);
                loan->BookId = reader->GetInt32(2);
                loan->LoanDate = DateTime::Parse(reader->GetString(3));
                loan->ReturnDate = DateTime::Parse(reader->GetString(4));
                loan->Status = reader->GetString(5);
                loan->CreatedAt = DateTime::Parse(reader->GetString(6));
                loan->UpdatedAt = DateTime::Parse(reader->GetString(7));
                loan->UserId = reader->IsDBNull(8) ? Nullable<int>() : reader->GetInt32(8);
                list->Add(loan);
            }
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
        return list;
    }

    List<StudentModel^>^ LoanController::SearchStudents(System::String^ searchTerm, int userId)
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


    List<BookModel^>^ LoanController::SearchBooks(System::String^ searchTerm) {
        auto list = gcnew List<BookModel^>();
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT id, name, author FROM book "
                "WHERE (name LIKE @search OR author LIKE @search) "
                "AND (loan_id IS NULL OR loan_id = '');",
                conn);

            cmd->Parameters->AddWithValue("@search", "%" + searchTerm + "%");
            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                auto book = gcnew BookModel();
                book->Id = reader->GetInt32(0);
                book->Name = reader->GetString(1);
                book->Author = reader->IsDBNull(2) ? nullptr : reader->GetString(2);
                list->Add(book);
            }
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
        return list;
    }

}