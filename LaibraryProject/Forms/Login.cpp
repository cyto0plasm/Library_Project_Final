#include "Login.h"
namespace LaibraryProject {
 System::Void Login::NavToRegisterBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	LaibraryProject::Register^ r = gcnew LaibraryProject::Register();
	this->Hide();
	r->Show();
}

 System::Void Login::LoginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	 String^ username = NameText->Text->Trim();
	 String^ password = PasswordText->Text->Trim();

	 if (String::IsNullOrEmpty(username) || String::IsNullOrEmpty(password)) {
		 MessageBox::Show("Please enter both username and password.", "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		 return;
	 }

	 try {
		 // 1. Try login via Library controller
		 auto userController = gcnew LaibraryProject::UsersController();
		 auto user = userController->Login(username, password);
		 if (user == nullptr) {
			 MessageBox::Show("Invalid username or password.", "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 return;
		 }

		 // 2. Success – go to Home with user's ID
		 this->Hide();
		 LaibraryProject::Home^ home = gcnew LaibraryProject::Home(user);
		 home->Show();
	 }
	 catch (Exception^ ex) {
		 MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	 }
 }


}
