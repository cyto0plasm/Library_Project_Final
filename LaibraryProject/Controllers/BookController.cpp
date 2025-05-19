#include "BookController.h"

namespace LaibraryProject {

    BookModel^ BooksController::Create(BookModel^ book) {
        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand(
            "INSERT INTO book (user_id, name, author, description, loan_id) "
            "VALUES (@user_id, @name, @author, @desc, @loan); "
            "SELECT last_insert_rowid();", conn);

        cmd->Parameters->AddWithValue("@user_id", book->UserId);
        cmd->Parameters->AddWithValue("@name", book->Name);
        cmd->Parameters->AddWithValue("@author", book->Author == nullptr ? DBNull::Value : safe_cast<Object^>(book->Author));
        cmd->Parameters->AddWithValue("@desc", book->Description == nullptr ? DBNull::Value : safe_cast<Object^>(book->Description));
        cmd->Parameters->AddWithValue("@loan", book->LoanId.HasValue ? safe_cast<Object^>(book->LoanId.Value) : DBNull::Value);

        int id = Convert::ToInt32(cmd->ExecuteScalar());
        conn->Close();

        book->Id = id;
        return book;
    }

    BookModel^ BooksController::GetById(int id) {
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT id, user_id, name, author, description, loan_id FROM book WHERE id = @id;", conn);
            cmd->Parameters->AddWithValue("@id", id);

            reader = cmd->ExecuteReader();
            if (reader->Read()) {
                auto book = gcnew BookModel();
                book->Id = reader->GetInt32(0);
                book->UserId = reader->GetInt32(1);
                book->Name = reader->GetString(2);
                book->Author = reader->IsDBNull(3) ? nullptr : reader->GetString(3);
                book->Description = reader->IsDBNull(4) ? nullptr : reader->GetString(4);
                book->LoanId = reader->IsDBNull(5) ? Nullable<int>() : reader->GetInt32(5);
                return book;
            }
            return nullptr;
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
    }

    List<BookModel^>^ BooksController::GetAll() {
        auto list = gcnew List<BookModel^>();
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand("SELECT id, user_id, name, author, description, loan_id FROM book;", conn);
            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                auto book = gcnew BookModel();
                book->Id = reader->GetInt32(0);
                book->UserId = reader->GetInt32(1);
                book->Name = reader->GetString(2);
                book->Author = reader->IsDBNull(3) ? nullptr : reader->GetString(3);
                book->Description = reader->IsDBNull(4) ? nullptr : reader->GetString(4);
                book->LoanId = reader->IsDBNull(5) ? Nullable<int>() : reader->GetInt32(5);
                list->Add(book);
            }
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
        return list;
    }

    List<BookModel^>^ BooksController::GetByUserId(int userId) {
        auto list = gcnew List<BookModel^>();
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT id, user_id, name, author, description, loan_id FROM book WHERE user_id = @user_id;", conn);
            cmd->Parameters->AddWithValue("@user_id", userId);
            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                auto book = gcnew BookModel();
                book->Id = reader->GetInt32(0);
                book->UserId = reader->GetInt32(1);
                book->Name = reader->GetString(2);
                book->Author = reader->IsDBNull(3) ? nullptr : reader->GetString(3);
                book->Description = reader->IsDBNull(4) ? nullptr : reader->GetString(4);
                book->LoanId = reader->IsDBNull(5) ? Nullable<int>() : reader->GetInt32(5);
                list->Add(book);
            }
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
        return list;
    }

    bool BooksController::Update(BookModel^ book) {
        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand(
            "UPDATE book SET user_id = @user_id, name = @name, author = @author, description = @desc, loan_id = @loan WHERE id = @id;", conn);

        cmd->Parameters->AddWithValue("@user_id", book->UserId);
        cmd->Parameters->AddWithValue("@name", book->Name);
        cmd->Parameters->AddWithValue("@author", book->Author == nullptr ? DBNull::Value : safe_cast<Object^>(book->Author));
        cmd->Parameters->AddWithValue("@desc", book->Description == nullptr ? DBNull::Value : safe_cast<Object^>(book->Description));
        cmd->Parameters->AddWithValue("@loan", book->LoanId.HasValue ? safe_cast<Object^>(book->LoanId.Value) : DBNull::Value);
        cmd->Parameters->AddWithValue("@id", book->Id);

        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }

    bool BooksController::Delete(int id) {
        if (id <= 0) return false;

        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand("DELETE FROM book WHERE id = @id;", conn);
        cmd->Parameters->AddWithValue("@id", id);

        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }
}
