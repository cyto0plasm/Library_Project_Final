#include "Student.h"
#include "../Models/userModel.h"
using namespace System::Text::RegularExpressions;

namespace LaibraryProject {
	//Parameterized Constructor
	Student::Student(UserModel^ user) {

		if (user == nullptr) {
			throw gcnew ArgumentNullException("User cannot be null");
		}
		currentUser = user;
		InitializeComponent();
		LoadStudentsForUser();
	}
	//Load Studen Table with it Data
	void Student::LoadStudentsForUser() {
		StudentsTable->Rows->Clear();
		auto controller = gcnew StudentsController();
		auto students = controller->GetByUserId(currentUser->Id);

		for each (StudentModel ^ s in students) {
			StudentsTable->Rows->Add(s->Id, s->Name, s->SeatNumber, s->Department, s->Email);
		}
	}
	//CRUDS
	System::Void Student::AddStudentBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		auto controller = gcnew StudentsController();
		auto student = gcnew StudentModel();

		if (String::IsNullOrWhiteSpace(StudentNameText->Text) ||
			String::IsNullOrWhiteSpace(StidentIdText->Text) ||
			String::IsNullOrWhiteSpace(EmailText->Text)) {
			MessageBox::Show("Name, Seat Number, and Email are required.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (!Regex::IsMatch(StidentIdText->Text, "^[0-9]{6}$")) {
			MessageBox::Show("Seat Number must be exactly 6 digits.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (!Regex::IsMatch(EmailText->Text,
			"^([\\w\\.-]+)@([\\w\\.-]+)\\.([a-zA-Z]{2,6})$")) {
			MessageBox::Show("Invalid Email format.", "Validation Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		student->Name = StudentNameText->Text;
		student->SeatNumber = Convert::ToInt32(StidentIdText->Text);
		student->Department = DepartmentText->Text;
		student->Email = EmailText->Text;
		student->UserId = currentUser->Id;
		student->Created_At = DateTime::Now;
		student->Updated_At = DateTime::Now;

		controller->Create(student);
		LoadStudentsForUser();
	}
	System::Void Student::EditStudentBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (StudentsTable->SelectedRows->Count == 0) return;

		int id = Convert::ToInt32(StudentsTable->SelectedRows[0]->Cells["IdCol"]->Value);
		auto controller = gcnew StudentsController();
		auto student = controller->GetById(id);
		if (student == nullptr) return;

		student->Name = StudentNameText->Text;
		student->SeatNumber = Convert::ToInt32(StidentIdText->Text);
		student->Department = DepartmentText->Text;
		student->Email = EmailText->Text;

		controller->Update(student);
		LoadStudentsForUser();
	}
	System::Void Student::DeleteStudentBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (StudentsTable->SelectedRows->Count == 0) return;

		int id = Convert::ToInt32(StudentsTable->SelectedRows[0]->Cells["IdCol"]->Value);
		auto controller = gcnew StudentsController();
		controller->Delete(id);

		LoadStudentsForUser();
	}
	//Clear Student Form
	void Student::ClearForm() {
		StudentNameText->Clear();
		StidentIdText->Clear();
		DepartmentText->Clear();
		EmailText->Clear();
	}
	//Print or extract
	System::Void Student::PrintTablePtn_Click(System::Object^ sender, System::EventArgs^ e) {
		//UIHelper::PrintTable(StudentsTable);
		UIHelper::ExportTableToCsv(StudentsTable);

	}
	//Search
	System::Void Student::SearchText_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		UIHelper::FilterDataGridView(StudentsTable, SearchText->Text);

	}
	//Table Events
	//System::Void Student::StudentsTable_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	//	auto map = gcnew Dictionary<String^, TextBox^>();
	//	map->Add("NameCol", StudentNameText);
	//	map->Add("SeatnumberCol", StidentIdText);
	//	map->Add("DepartmentCol", DepartmentText);
	//	map->Add("EmailCol", EmailText);

	//	LaibraryProject::UIHelper::FillControlsFromSelectedRow(StudentsTable, map);
	//}
	System::Void Student::StudentsTable_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
		if (e->RowIndex < 0) return;

		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			// Fill form from row
			auto map = gcnew Dictionary<String^, TextBox^>();
			map->Add("NameCol", StudentNameText);
			map->Add("SeatnumberCol", StidentIdText);
			map->Add("DepartmentCol", DepartmentText);
			map->Add("EmailCol", EmailText);

			LaibraryProject::UIHelper::FillControlsFromSelectedRow(StudentsTable, map);
		}
		else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			// Print full row
			LaibraryProject::UIHelper::PrintRow(e, StudentsTable);
		}
	}


};
