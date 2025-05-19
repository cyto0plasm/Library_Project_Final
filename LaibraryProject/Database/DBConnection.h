
#pragma once

using namespace System;
using namespace System::Data::SQLite;

ref class DBConnection
{
private:
    //static String^ connectionString = "Data Source=pharmacy_management_system.db;Version=3;";
    static String^ connectionString = "Data Source=C:\\vs_Projects\\LaibraryProject\\lib.db;Version=3;Foreign Keys=True;";
public:
    static SQLiteConnection^ GetConnection();
    static bool DBConnection::IsConnectionOpen(SQLiteConnection^ conn);
    
};

















//#pragma once
//
//using namespace System;
//using namespace MySql::Data::MySqlClient;
//
//ref class DBConnection
//{
//private:
//    static String^ connectionString = "server=localhost;port=3306;user=root;password=;database=pharmacy_management_system;";
//public:
//    static MySqlConnection^ GetConnection();
//};