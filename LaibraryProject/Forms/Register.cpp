#include "Register.h"

namespace LaibraryProject {
	System::Void Register::RegisterBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ name = NameText->Text->Trim();
		String^ password = PasswordText->Text->Trim();
		String^ confirm = PasswordConfirmText->Text->Trim();

		// Basic validation
		if (String::IsNullOrWhiteSpace(name)) {
			MessageBox::Show("Name is required.");
			return;
		}
		if (password->Length < 6) {
			MessageBox::Show("Password must be at least 6 characters.");
			return;
		}
		if (password != confirm) {
			MessageBox::Show("Passwords do not match.");
			return;
		}

		try {
			// 1. Register via controller
// In Register form
			LaibraryProject::UsersController^ userController = gcnew LaibraryProject::UsersController();
			auto user = userController->Register(name, password);
			if (user == nullptr) {
				MessageBox::Show("Registration failed.");
				return;
			}

			// 2. Navigate to Home with user's ID
			this->Hide();
			LaibraryProject::Home^ home = gcnew LaibraryProject::Home(user);
			home->Show();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error: " + ex->Message);
		}
	}
	System::Void Register::NavToLoginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	LaibraryProject::Login^ login = gcnew LaibraryProject::Login();
	this->Hide();
	login->Show();
}

}