#include "Home.h"  
namespace LaibraryProject {

	Home::Home(UserModel^ user) {

		if (user == nullptr) {
			throw gcnew ArgumentNullException("User cannot be null");
		}
		currentUser = user;
		InitializeComponent();
		LoadUserData();

	}

	
	System::Void Home::Home_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
		// Take a copy of open forms so we don't modify the collection during iteration
		auto openFormsCopy = gcnew List<Form^>();

		for each (Form ^ f in Application::OpenForms) {
			if (f != this) {
				openFormsCopy->Add(f);
			}
		}

		for each (Form ^ f in openFormsCopy) {
			f->Close();
		}
	}


}

	





