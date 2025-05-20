#include "DBConnection.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data::SQLite;

SQLiteConnection^ DBConnection::GetConnection()
{
    SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);
    conn->Open();

    // Enable foreign keys
    auto pragmaCmd = gcnew SQLiteCommand("PRAGMA foreign_keys = ON;", conn);
    pragmaCmd->ExecuteNonQuery();
  

    /*auto cmdUser = gcnew SQLiteCommand(
            "  INSERT INTO book(name) VALUES('test'););", conn);
        cmdUser->ExecuteNonQuery();*/

    // Create 'user' table
    //auto cmdUser = gcnew SQLiteCommand(
    //    "CREATE TABLE IF NOT EXISTS user ("
    //    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
    //    "name TEXT NOT NULL, "
    //    "password TEXT NOT NULL, "
    //    "created_at TEXT DEFAULT CURRENT_TIMESTAMP, "
    //    "updated_at TEXT DEFAULT CURRENT_TIMESTAMP"
    //    ");", conn);
    //cmdUser->ExecuteNonQuery();

    //// Create 'loan' table
    //auto cmdLoan = gcnew SQLiteCommand(
    //    "CREATE TABLE IF NOT EXISTS loan ("
    //    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
    //    "user_id INTEGER NOT NULL, "
    //    "loan_date TEXT DEFAULT CURRENT_TIMESTAMP, "
    //    "return_date TEXT, "
    //    "created_at TEXT DEFAULT CURRENT_TIMESTAMP, "
    //    "updated_at TEXT DEFAULT CURRENT_TIMESTAMP, "
    //    "FOREIGN KEY(user_id) REFERENCES user(id) ON DELETE CASCADE"
    //    ");", conn);
    //cmdLoan->ExecuteNonQuery();

    //// Create 'book' table
    //auto cmdBook = gcnew SQLiteCommand(
    //    "CREATE TABLE IF NOT EXISTS book ("
    //    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
    //    "user_id INTEGER NOT NULL, "
    //    "name TEXT NOT NULL, "
    //    "author TEXT, "
    //    "description TEXT, "
    //    "loan_id INTEGER, "
    //    "created_at TEXT DEFAULT CURRENT_TIMESTAMP, "
    //    "updated_at TEXT DEFAULT CURRENT_TIMESTAMP, "
    //    "FOREIGN KEY(user_id) REFERENCES user(id) ON DELETE CASCADE, "
    //    "FOREIGN KEY(loan_id) REFERENCES loan(id) ON DELETE SET NULL"
    //    ");", conn);
    //cmdBook->ExecuteNonQuery();

    // Get list of tables
    //String^ tableList = "";
    //auto cmd = gcnew SQLiteCommand("SELECT name FROM sqlite_master WHERE type='table';", conn);
    //auto reader = cmd->ExecuteReader();
    //while (reader->Read()) {
    //    tableList += "- " + reader->GetString(0) + "\n";
    //}
    //reader->Close();

    //// Show MessageBox
    //String^ dbFile = conn->DataSource;
    //MessageBox::Show(
    //    "Connected to SQLite database at:\n" + dbFile + "\n\nTables found:\n" + tableList,
    //    "Database Connection Successful",
    //    MessageBoxButtons::OK,
    //    MessageBoxIcon::Information
    //);

    conn->Close();  // connection returned closed
    return conn;
}
bool DBConnection::IsConnectionOpen(SQLiteConnection^ conn)
{
    return conn != nullptr && conn->State == System::Data::ConnectionState::Open;
}

//DANGER ---- DELETE AND RESET THE DATABASE 
void DBConnection::ResetDatabase()
{
    SQLiteConnection^ conn = GetOpenConnection();
    try {
        if (!IsConnectionOpen(conn)) {
            MessageBox::Show("Failed to open database connection.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        // Use transaction to maintain data integrity
        SQLiteTransaction^ transaction = conn->BeginTransaction();

        // List your tables here
        array<String^>^ tables = gcnew array<String^> {
            "book_suggestion", // child
                "book",            // child of user, loan
                "loan",            // child of user
                "student",         // child of loan or suggestion
                "user"             // parent
        };
        for each (String ^ table in tables) {
            // Delete data
            auto deleteCmd = gcnew SQLiteCommand("DELETE FROM " + table + ";", conn, transaction);
            deleteCmd->ExecuteNonQuery();

            // Reset auto-increment (SQLite keeps this in sqlite_sequence table)
            auto resetCmd = gcnew SQLiteCommand("DELETE FROM sqlite_sequence WHERE name = '" + table + "';", conn, transaction);
            resetCmd->ExecuteNonQuery();
        }

        transaction->Commit();

        MessageBox::Show("All data deleted and IDs reset successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
    catch (Exception^ ex) {
        MessageBox::Show("Reset failed: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    finally {
        conn->Close();
    }
}

SQLiteConnection^ DBConnection::GetOpenConnection()
{
    SQLiteConnection^ conn = gcnew SQLiteConnection(connectionString);
    conn->Open();

    auto pragmaCmd = gcnew SQLiteCommand("PRAGMA foreign_keys = ON;", conn);
    pragmaCmd->ExecuteNonQuery();

    return conn; // Leave it open
}
