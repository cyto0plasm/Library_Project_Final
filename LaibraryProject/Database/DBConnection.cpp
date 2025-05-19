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

