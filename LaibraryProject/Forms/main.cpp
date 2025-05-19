#include "../Forms/BookSuggestions.h"
#include "../Forms/Student.h"
#include "../Forms/Home.h"
#include "../Forms/Register.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main(array<String^>^ args)
{
	
	try
	{
		auto testConn = DBConnection::GetConnection();  // now returns SQLiteConnection^
		testConn->Open();                               // will throw if bad
		// enable foreign keys if you rely on FKs
		{
			auto fkCmd = gcnew SQLiteCommand("PRAGMA foreign_keys = ON;", testConn);
			fkCmd->ExecuteNonQuery();
		}
		testConn->Close();
		MessageBox::Show(
			"SQLite database connection successful!"+testConn,
			"Connection Test",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);
	}
	catch (Exception^ ex)
	{
		MessageBox::Show(
			"Database connection FAILED:\n" + ex->Message,
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error
		);
		return -1;  // abort launch
	}
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	LaibraryProject::Login form;
	Application::Run(% form);
	return 0;
}