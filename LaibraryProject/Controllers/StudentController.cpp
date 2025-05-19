#include "StudentController.h"
#include "../Database/DBConnection.h"
using namespace System::Windows::Forms;

using namespace System::Data::SQLite;

namespace LaibraryProject {

    StudentModel^ StudentsController::Create(StudentModel^ student) {
        auto conn = DBConnection::GetConnection();
        try{
            conn->Open();

            auto cmd = gcnew SQLiteCommand(
                "INSERT INTO student (name, seatNumber, department, email, user_id, suggests_id, loan_id, created_at, updated_at) "
                "VALUES (@n, @s, @d, @e, @uid, @sid, @lid, @c, @u); SELECT last_insert_rowid();", conn);

            cmd->Parameters->AddWithValue("@n", student->Name);
            cmd->Parameters->AddWithValue("@s", student->SeatNumber);
            cmd->Parameters->AddWithValue("@d", student->Department);
            cmd->Parameters->AddWithValue("@e", student->Email);
            cmd->Parameters->AddWithValue("@uid", student->UserId.HasValue ? safe_cast<Object^>(student->UserId.Value) : DBNull::Value);
            cmd->Parameters->AddWithValue("@sid", student->SuggestsId.HasValue ? safe_cast<Object^>(student->SuggestsId.Value) : DBNull::Value);
            cmd->Parameters->AddWithValue("@lid", student->LoanId.HasValue ? safe_cast<Object^>(student->LoanId.Value) : DBNull::Value);
            cmd->Parameters->AddWithValue("@c", student->Created_At);
            cmd->Parameters->AddWithValue("@u", student->Updated_At);

            int id = Convert::ToInt32(cmd->ExecuteScalar());
            student->Id = id;
            return student;
        }
        catch (SQLiteException^ ex) {
            if (ex->Message->Contains("UNIQUE constraint failed")) {
                MessageBox::Show("A student with this email or seat number already exists.", "Duplicate Entry", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
            else {
                MessageBox::Show("Database error while creating student: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Unexpected error while creating student: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (DBConnection::IsConnectionOpen(conn)) conn->Close();
        }
       

       
    }

    StudentModel^ StudentsController::GetById(int id) {
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT id, name, seatNumber, department, email, user_id, suggests_id, loan_id, created_at, updated_at FROM student WHERE id = @id;", conn);
            cmd->Parameters->AddWithValue("@id", id);

            reader = cmd->ExecuteReader();
            if (reader->Read()) {
                auto student = gcnew StudentModel();
                student->Id = reader->GetInt32(0);
                student->Name = reader->GetString(1);
                student->SeatNumber = reader->GetInt32(2);
                student->Department = reader->GetString(3);
                student->Email = reader->GetString(4);
                student->UserId = reader->IsDBNull(5) ? Nullable<int>() : reader->GetInt32(5);
                student->SuggestsId = reader->IsDBNull(6) ? Nullable<int>() : reader->GetInt32(6);
                student->LoanId = reader->IsDBNull(7) ? Nullable<int>() : reader->GetInt32(7);
                student->Created_At = reader->GetDateTime(8);
                student->Updated_At = reader->GetDateTime(9);
                return student;
            }
            return nullptr;
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
    }

    List<StudentModel^>^ StudentsController::GetAll() {
        auto list = gcnew List<StudentModel^>();
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand("SELECT id, name, seatNumber, department, email, user_id, suggests_id, loan_id, created_at, updated_at FROM student;", conn);
            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                auto student = gcnew StudentModel();
                student->Id = reader->GetInt32(0);
                student->Name = reader->GetString(1);
                student->SeatNumber = reader->GetInt32(2);
                student->Department = reader->GetString(3);
                student->Email = reader->GetString(4);
                student->UserId = reader->IsDBNull(5) ? Nullable<int>() : reader->GetInt32(5);
                student->SuggestsId = reader->IsDBNull(6) ? Nullable<int>() : reader->GetInt32(6);
                student->LoanId = reader->IsDBNull(7) ? Nullable<int>() : reader->GetInt32(7);
                student->Created_At = reader->GetDateTime(8);
                student->Updated_At = reader->GetDateTime(9);
                list->Add(student);
            }
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }

        return list;
    }

    List<StudentModel^>^ StudentsController::GetByUserId(int userId) {
        auto list = gcnew List<StudentModel^>();
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT id, name, seatNumber, department, email, user_id, suggests_id, loan_id, created_at, updated_at "
                "FROM student WHERE user_id = @uid;", conn);
            cmd->Parameters->AddWithValue("@uid", userId);
            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                auto student = gcnew StudentModel();
                student->Id = reader->GetInt32(0);
                student->Name = reader->GetString(1);
                student->SeatNumber = reader->GetInt32(2);
                student->Department = reader->GetString(3);
                student->Email = reader->GetString(4);
                student->UserId = reader->IsDBNull(5) ? Nullable<int>() : reader->GetInt32(5);
                student->SuggestsId = reader->IsDBNull(6) ? Nullable<int>() : reader->GetInt32(6);
                student->LoanId = reader->IsDBNull(7) ? Nullable<int>() : reader->GetInt32(7);
                student->Created_At = reader->GetDateTime(8);
                student->Updated_At = reader->GetDateTime(9);
                list->Add(student);
            }
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }

        return list;
    }

    bool StudentsController::Update(StudentModel^ student) {
        student->Updated_At = DateTime::Now;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand(
            "UPDATE student SET name = @n, seatNumber = @s, department = @d, email = @e, "
            "user_id = @uid, suggests_id = @sid, loan_id = @lid, updated_at = @u WHERE id = @id;", conn);

        cmd->Parameters->AddWithValue("@n", student->Name);
        cmd->Parameters->AddWithValue("@s", student->SeatNumber);
        cmd->Parameters->AddWithValue("@d", student->Department);
        cmd->Parameters->AddWithValue("@e", student->Email);
        cmd->Parameters->AddWithValue("@uid", student->UserId.HasValue ? safe_cast<Object^>(student->UserId.Value) : DBNull::Value);
        cmd->Parameters->AddWithValue("@sid", student->SuggestsId.HasValue ? safe_cast<Object^>(student->SuggestsId.Value) : DBNull::Value);
        cmd->Parameters->AddWithValue("@lid", student->LoanId.HasValue ? safe_cast<Object^>(student->LoanId.Value) : DBNull::Value);
        cmd->Parameters->AddWithValue("@u", student->Updated_At);
        cmd->Parameters->AddWithValue("@id", student->Id);

        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }

    bool StudentsController::Delete(int id) {
        if (id <= 0) return false;

        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand("DELETE FROM student WHERE id = @id;", conn);
        cmd->Parameters->AddWithValue("@id", id);

        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }

}
