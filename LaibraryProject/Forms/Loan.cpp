#include "Loan.h"
#include "../HelperMethods/UIHelper.h"

//LOAN CONSTRUCTOR
LaibraryProject::Loan::Loan(UserModel^ user)
{
	if (user == nullptr) {
		throw gcnew ArgumentNullException("User cannot be null");
	}
	currentUser = user;

	InitializeComponent();
	LoadLoansForUser(currentUser->Id);
}
//LOAD LOAN TABLE DATA FOR THE USER
void LaibraryProject::Loan::LoadLoansForUser(int userId) {
	auto loanController = gcnew LoanController();
	auto studentController = gcnew StudentsController();
	auto bookController = gcnew BooksController();

	// Get all students for this user
	auto students = studentController->GetByUserId(userId);
	if (students == nullptr || students->Count == 0) return;

	LoanTable->Rows->Clear();

	for each (auto student in students) {
		auto loans = loanController->GetByStudentId(student->Id);

		for each (LoanModel ^ loan in loans) {
			auto book = bookController->GetById(loan->BookId);
			String^ bookName = (book != nullptr) ? book->Name : "Unknown";

			array<Object^>^ row = gcnew array<Object^>{
				loan->Id,
					student->Name, // display student's name
					bookName,
					loan->Status,
					loan->LoanDate.ToString("yyyy-MM-dd"),
					loan->ReturnDate.ToString("yyyy-MM-dd")
			};

			LoanTable->Rows->Add(row);
		}
	}
}
//SEARCH LOAN TABLE
System::Void LaibraryProject::Loan::SearchLoansText_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::FilterDataGridView(LoanTable, SearchLoansText->Text);
}
//SEARCH STUDENTS LIST
System::Void LaibraryProject::Loan::SearchForStudentsText_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	String^ searchText = SearchForStudentsText->Text->Trim();
	resultListStudents->Items->Clear();

	if (String::IsNullOrEmpty(searchText) || searchText->Length < 1) return;

	auto controller = gcnew LoanController();
	auto students = controller->SearchStudents(searchText, currentUser->Id);

	for each (auto student in students) {
		String^ displayText = String::Format("{0,-5} | {1,-15} | {2,-10}", student->Id, student->Name, student->SeatNumber);
		resultListStudents->Items->Add(displayText);
	}
	//MessageBox::Show("Students found: " + students->Count.ToString());

}
//SEARCH BOOK LIST 
System::Void LaibraryProject::Loan::SearchSForBooksText_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	String^ searchText = SearchSForBooksText->Text->Trim();
	resultListBooks->Items->Clear();

	if (String::IsNullOrEmpty(searchText) || searchText->Length < 1) return;

	auto controller = gcnew LoanController();
	auto books = controller->SearchBooks(searchText);

	for each (auto book in books) {
		String^ author = String::IsNullOrEmpty(book->Author) ? "Unknown" : book->Author;
		String^ displayText = String::Format("{0,-5} | {1,-15} | {2,-30}", book->Id, book->Name, author);
		resultListBooks->Items->Add(displayText);
	}
	//MessageBox::Show("Books found: " + books->Count.ToString());

}
//LOAN BUTTON TO MAKE A NEW LOAN
System::Void LaibraryProject::Loan::LoanBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// Check selections
	if (resultListStudents->SelectedItem == nullptr) {
		MessageBox::Show("Please select a student.");
		return;
	}
	if (resultListBooks->SelectedItem == nullptr) {
		MessageBox::Show("Please select a book.");
		return;
	}
	if (ReturnDatePicker->Value <= DateTime::Now.Date) {
		MessageBox::Show("Return date must be in the future.");
		return;
	}

	// Parse selected student ID
	String^ studentText = safe_cast<String^>(resultListStudents->SelectedItem);
	auto studentIdStr = studentText->Split('|')[0];
	int studentId = Convert::ToInt32(studentIdStr);

	// Parse selected book ID
	String^ bookText = safe_cast<String^>(resultListBooks->SelectedItem);
	auto bookIdStr = bookText->Split('|')[0];
	int bookId = Convert::ToInt32(bookIdStr);

	// Prepare the loan model
	auto loan = gcnew LoanModel();
	loan->StudentId = studentId;
	loan->BookId = bookId;
	loan->LoanDate = DateTime::Now;
	loan->ReturnDate = ReturnDatePicker->Value.Date;
	loan->Status = "loaned";
	loan->UserId = currentUser->Id;

	// Create the loan via controller
	auto loanController = gcnew LoanController();
	auto createdLoan = loanController->Create(loan);

	if (createdLoan != nullptr && createdLoan->Id > 0) {
		MessageBox::Show("Loan created successfully with ID: " + createdLoan->Id);
		// Optionally refresh UI, clear selections, etc.
		LoadLoansForUser(currentUser->Id);

		resultListStudents->ClearSelected();
		resultListBooks->ClearSelected();

	}
	else {
		MessageBox::Show("Failed to create loan.");
	}
}
//UPDATE STATUS BUTTON OF THE LOAN 
System::Void LaibraryProject::Loan::updateStatusBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	CreateAndShowStatusDialog();

}
System::Void LaibraryProject::Loan::delBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// Check if a row is selected
	if (LoanTable->SelectedRows->Count == 0) {
		MessageBox::Show("Please select a loan to delete.");
		return;
	}

	// Get the selected row
	auto selectedRow = LoanTable->SelectedRows[0];
	int loanId = Convert::ToInt32(selectedRow->Cells[0]->Value); // Assuming ID is in column 0

	// Confirm deletion
	auto result = MessageBox::Show("Are you sure you want to delete this loan?", "Confirm Deletion",
		MessageBoxButtons::YesNo, MessageBoxIcon::Warning);

	if (result == System::Windows::Forms::DialogResult::Yes) {
		// Delete the loan
		auto controller = gcnew LoanController();
		bool success = controller->Delete(loanId);

		if (success) {
			MessageBox::Show("Loan deleted successfully.");
			LoadLoansForUser(currentUser->Id); // Refresh the table
		}
		else {
			MessageBox::Show("Failed to delete the loan.");
		}
	}
}

//LOAN TABLE - STATUS FORMATING 
System::Void LaibraryProject::Loan::LoanTable_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e)
{
	String^ status = e->Value != nullptr ? e->Value->ToString() : "";

	if (status == "Loaned") {
		e->CellStyle->ForeColor = System::Drawing::Color::DarkOrange;
	}
	else if (status == "Returned") {
		e->CellStyle->ForeColor = System::Drawing::Color::ForestGreen;
	}
	else if (status == "Exceeded Return Time") {
		e->CellStyle->ForeColor = System::Drawing::Color::Crimson;
	}
}

// Implementation of the dialog creation and display method of status button
void LaibraryProject::Loan::CreateAndShowStatusDialog() {
	// Create the dialog form
	statusDialog = gcnew System::Windows::Forms::Form();
	statusDialog->Text = L"Update Book Status";
	statusDialog->Size = System::Drawing::Size(350, 250);
	statusDialog->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
	statusDialog->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
	statusDialog->MaximizeBox = false;
	statusDialog->MinimizeBox = false;
	statusDialog->ShowInTaskbar = false;
	statusDialog->Font = gcnew System::Drawing::Font(L"Segoe UI", 9);

	// Create the status label
	statusDialogLabel = gcnew System::Windows::Forms::Label();
	statusDialogLabel->Text = L"Please select the new status for this book:";
	statusDialogLabel->Location = System::Drawing::Point(20, 20);
	statusDialogLabel->Size = System::Drawing::Size(300, 20);
	statusDialogLabel->AutoSize = true;

	// Create radio buttons for status options
	returnedRadioBtn = gcnew System::Windows::Forms::RadioButton();
	returnedRadioBtn->Text = L"Returned";
	returnedRadioBtn->Location = System::Drawing::Point(30, 50);
	returnedRadioBtn->Size = System::Drawing::Size(200, 24);
	returnedRadioBtn->Checked = true; // Default selection

	loanedRadioBtn = gcnew System::Windows::Forms::RadioButton();
	loanedRadioBtn->Text = L"Loaned";
	loanedRadioBtn->Location = System::Drawing::Point(30, 80);
	loanedRadioBtn->Size = System::Drawing::Size(200, 24);

	exceededRadioBtn = gcnew System::Windows::Forms::RadioButton();
	exceededRadioBtn->Text = L"Exceeded Return Time";
	exceededRadioBtn->Location = System::Drawing::Point(30, 110);
	exceededRadioBtn->Size = System::Drawing::Size(200, 24);

	// Create buttons
	confirmStatusBtn = gcnew System::Windows::Forms::Button();
	confirmStatusBtn->Text = L"Confirm";
	confirmStatusBtn->DialogResult = System::Windows::Forms::DialogResult::OK;
	confirmStatusBtn->Location = System::Drawing::Point(70, 150);
	confirmStatusBtn->Size = System::Drawing::Size(100, 30);
	confirmStatusBtn->Click += gcnew System::EventHandler(this, &LaibraryProject::Loan::confirmStatusBtn_Click);

	cancelStatusBtn = gcnew System::Windows::Forms::Button();
	cancelStatusBtn->Text = L"Cancel";
	cancelStatusBtn->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	cancelStatusBtn->Location = System::Drawing::Point(180, 150);
	cancelStatusBtn->Size = System::Drawing::Size(100, 30);

	// Add controls to the dialog
	statusDialog->Controls->Add(statusDialogLabel);
	statusDialog->Controls->Add(returnedRadioBtn);
	statusDialog->Controls->Add(loanedRadioBtn);
	statusDialog->Controls->Add(exceededRadioBtn);
	statusDialog->Controls->Add(confirmStatusBtn);
	statusDialog->Controls->Add(cancelStatusBtn);

	// Set the accept and cancel buttons for the form
	statusDialog->AcceptButton = confirmStatusBtn;
	statusDialog->CancelButton = cancelStatusBtn;

	// Show the dialog
	statusDialog->ShowDialog(this);
}
// Handle the confirm button click
System::Void LaibraryProject::Loan::confirmStatusBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	// Get the selected status
	String^ newStatus = "";

	if (returnedRadioBtn->Checked) {
		newStatus = "Returned";
	}
	else if (loanedRadioBtn->Checked) {
		newStatus = "Loaned";
	}
	else if (exceededRadioBtn->Checked) {
		newStatus = "Exceeded Return Time";
	}

	auto loanController = gcnew LaibraryProject::LoanController();
	int loanId = Convert::ToInt32(LoanTable->SelectedRows[0]->Cells["IdCol"]->Value);
	auto loan = loanController->GetById(loanId);

	if (loan != nullptr) {
		// Update the loan status
		loan->Status = newStatus;

		// Save changes to database
		bool success = loanController->Update(loan);
		LoadLoansForUser(currentUser->Id);

		// Show confirmation message
		System::Windows::Forms::MessageBox::Show(
			"Book status has been updated to: " + newStatus,
			"Status Updated",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Information);

		// Close the dialog
		statusDialog->Close();
	}
}

//PRINT AND EXPORT TABLE
System::Void LaibraryProject::Loan::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	UIHelper::PrintTable(LoanTable);

}
System::Void LaibraryProject::Loan::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	UIHelper::ExportTableToCsv(LoanTable);

}

//WINDOW CONTROLS
System::Void LaibraryProject::Loan::closeBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
System::Void LaibraryProject::Loan::miniBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (this->WindowState == System::Windows::Forms::FormWindowState::Normal) {
		this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
	}
	else {
		this->WindowState = System::Windows::Forms::FormWindowState::Normal;

	}
}


//SELECTED BOOK FROM THE BOOK SCREEN
  void LaibraryProject::Loan::SelectBookFromExternal(String^ bookId, String^ bookName, String^ author) {
	String^ authorDisplay = String::IsNullOrEmpty(author) ? "Unknown" : author;
	String^ displayText = String::Format("{0,-5} | {1,-15} | {2,-30}", bookId, bookName, authorDisplay);

	// Clear current selection and re-add only this
	resultListBooks->Items->Clear();
	resultListBooks->Items->Add(displayText);
	resultListBooks->SelectedIndex = 0; // Auto-select it
}
