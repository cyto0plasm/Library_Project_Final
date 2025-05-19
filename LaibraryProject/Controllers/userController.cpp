#include "userController.h"

#include "../Database/DBConnection.h"
using namespace System::Windows::Forms;

namespace LaibraryProject {

    UserModel^ UsersController::Create(UserModel^ user) {
        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand(
            "INSERT INTO user (name, password, created_at, updated_at) VALUES (@n, @p, @c, @u); "
            "SELECT last_insert_rowid();",
            conn);

        cmd->Parameters->AddWithValue("@n", user->Name);
        cmd->Parameters->AddWithValue("@p", user->Password);
        cmd->Parameters->AddWithValue("@c", user->Created_At);
        cmd->Parameters->AddWithValue("@u", user->Updated_At);

        int id = Convert::ToInt32(cmd->ExecuteScalar());
        conn->Close();

        user->Id = id;
        return user;
    }
   
    UserModel^ UsersController::Login(String^ name, String^ password) {
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand(
                "SELECT id, name, password, created_at, updated_at FROM user WHERE name = @n;", conn);
            cmd->Parameters->AddWithValue("@n", name);

            reader = cmd->ExecuteReader();
            if (reader->Read()) {
                String^ storedPassword = reader->GetString(2);
                if (storedPassword->Equals(password)) {  
                    auto user = gcnew UserModel();
                    user->Id = reader->GetInt32(0);
                    user->Name = reader->GetString(1);
                    user->Password = storedPassword;
                    user->Created_At = reader->GetDateTime(3);
                    user->Updated_At = reader->GetDateTime(4);
                    return user;
                }
            }
            return nullptr;
        }catch(SQLiteException^ ex){
            MessageBox::Show("Database error While Login: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Unexpected error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
        return nullptr;
    }
    UserModel^ UsersController::Register(String^ name, String^ password) {
        if (String::IsNullOrWhiteSpace(name))
            throw gcnew ArgumentException("Name cannot be empty.");
        if (String::IsNullOrWhiteSpace(password) || password->Length < 6)
            throw gcnew ArgumentException("Password must be at least 6 characters.");

        // Check for duplicate user name
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();
        try {
            auto checkCmd = gcnew SQLiteCommand("SELECT COUNT(*) FROM user WHERE name = @n;", conn);
            checkCmd->Parameters->AddWithValue("@n", name);
            int count = Convert::ToInt32(checkCmd->ExecuteScalar());

            if (count > 0)
                throw gcnew InvalidOperationException("User already exists.");

            auto user = gcnew UserModel();
            user->Name = name;
            user->Password = password;
            user->Created_At = DateTime::Now;
            user->Updated_At = DateTime::Now;

            return Create(user);
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
    }


    UserModel^ UsersController::GetById(int id) {
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand("SELECT id, name, password, created_at, updated_at FROM user WHERE id = @id;", conn);
            cmd->Parameters->AddWithValue("@id", id);

            reader = cmd->ExecuteReader();
            if (reader->Read()) {
                auto user = gcnew UserModel();
                user->Id = reader->GetInt32(0);
                user->Name = reader->GetString(1);
                user->Password = reader->GetString(2);
                user->Created_At = reader->GetDateTime(3);
                user->Updated_At = reader->GetDateTime(4);
                return user;
            }
            return nullptr;
        }
        catch (SQLiteException^ ex) {
            MessageBox::Show("Database error While Register: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Unexpected error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }
    }

    List<UserModel^>^ UsersController::GetAll() {
        auto list = gcnew List<UserModel^>();
        SQLiteDataReader^ reader = nullptr;
        auto conn = DBConnection::GetConnection();
        conn->Open();

        try {
            auto cmd = gcnew SQLiteCommand("SELECT id, name, password, created_at, updated_at FROM user;", conn);
            reader = cmd->ExecuteReader();

            while (reader->Read()) {
                auto user = gcnew UserModel();
                user->Id = reader->GetInt32(0);
                user->Name = reader->GetString(1);
                user->Password = reader->GetString(2);
                user->Created_At = reader->GetDateTime(3);
                user->Updated_At = reader->GetDateTime(4);
                list->Add(user);
            }
        }
        catch (SQLiteException^ ex) {
            MessageBox::Show("Database error While Fetching Data: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Unexpected error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        finally {
            if (reader) reader->Close();
            conn->Close();
        }

        return list;
    }

   bool UsersController::Update(UserModel^ user) {
    user->Updated_At = DateTime::Now;
    SQLiteConnection^ conn = nullptr;
    int rows = 0;

    try {
        conn = DBConnection::GetConnection();

        if (!DBConnection::IsConnectionOpen(conn)) {
            MessageBox::Show("Database connection failed.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return false;
        }

        auto cmd = gcnew SQLiteCommand(
            "UPDATE user SET name = @n, password = @p, updated_at = @u WHERE id = @id;", conn);

        cmd->Parameters->AddWithValue("@n", user->Name);
        cmd->Parameters->AddWithValue("@p", user->Password);
        cmd->Parameters->AddWithValue("@u", user->Updated_At);
        cmd->Parameters->AddWithValue("@id", user->Id);

        rows = cmd->ExecuteNonQuery();
    }
    catch (SQLiteException^ ex) {
        MessageBox::Show("Database error while updating user: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    catch (Exception^ ex) {
        MessageBox::Show("Unexpected error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        if (DBConnection::IsConnectionOpen(conn))
            conn->Close();
    }

    return rows > 0;
}


    bool UsersController::Delete(int id) {
        if (id <= 0) return false;

        auto conn = DBConnection::GetConnection();
        conn->Open();

        auto cmd = gcnew SQLiteCommand("DELETE FROM user WHERE id = @id;", conn);
        cmd->Parameters->AddWithValue("@id", id);

        int rows = cmd->ExecuteNonQuery();
        conn->Close();
        return rows > 0;
    }
}
