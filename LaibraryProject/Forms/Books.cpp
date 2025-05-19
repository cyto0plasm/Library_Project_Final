#include "Books.h"



LaibraryProject::Books::Books(UserModel^ user)
{
	if (user == nullptr) {
		throw gcnew ArgumentNullException("User cannot be null");
	}
	currentUser = user;
	InitializeComponent();
	LoadBooksForUser();

}




//CRUDS OPERATIONS
System::Void LaibraryProject::Books::AddBookBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrWhiteSpace(BookNameText->Text)) {
		MessageBox::Show("Book name is required.");
		return;
	}

	// Create new book model
	auto book = gcnew LaibraryProject::BookModel();
	book->Name = BookNameText->Text;
	book->Author = AuthorText->Text;
	book->Description = DescreptionText->Text;
	book->UserId = currentUser->Id;  // assume you have this variable available
	book->LoanId = Nullable<int>(); // no loan initially

	// Insert into DB
	auto controller = gcnew LaibraryProject::BooksController();
	controller->Create(book);

	LoadBooksForUser();
}

System::Void LaibraryProject::Books::EditBookBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (BooksTable->SelectedRows->Count == 0) {
		MessageBox::Show("Please select a book to edit.");
		return;
	}

	auto selectedRow = BooksTable->SelectedRows[0];
	int bookId = Convert::ToInt32(selectedRow->Cells["Id"]->Value);

	auto controller = gcnew LaibraryProject::BooksController();
	auto book = controller->GetById(bookId);
	if (book == nullptr) {
		MessageBox::Show("Selected book not found.");
		return;
	}

	// Update book properties from text boxes
	book->Name = BookNameText->Text;
	book->Author = AuthorText->Text;
	book->Description = DescreptionText->Text;
	// UserId should not change here
	// LoanId stays the same or update as needed

	if (controller->Update(book)) {
		MessageBox::Show("Book updated successfully.");
		LoadBooksForUser();
	}
	else {
		MessageBox::Show("Failed to update book.");
	}
}

System::Void LaibraryProject::Books::DeleteBookBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (BooksTable->SelectedRows->Count == 0) {
		MessageBox::Show("Please select a book to delete.");
		return;
	}

	auto selectedRow = BooksTable->SelectedRows[0];
	int bookId = Convert::ToInt32(selectedRow->Cells["Id"]->Value);

	auto controller = gcnew LaibraryProject::BooksController();
	if (controller->Delete(bookId)) {
		MessageBox::Show("Book deleted successfully.");
		LoadBooksForUser();
	}
	else {
		MessageBox::Show("Failed to delete book.");
	}
}
//LOAD THE BOOKS DATA
void LaibraryProject::Books::LoadBooksForUser() {
	BooksTable->Rows->Clear();
	auto controller = gcnew LaibraryProject::BooksController();
	auto books = controller->GetByUserId(currentUser->Id);

	for each (LaibraryProject::BookModel ^ b in books) {
		BooksTable->Rows->Add(b->Id, b->Name, b->Author, b->Description);
	}
}


//MOVE DATA FROM TABLE TO FORM
System::Void LaibraryProject::Books::BooksTable_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
	if (e->RowIndex < 0) return;

	if (e->Button == System::Windows::Forms::MouseButtons::Left) {
		// Fill form from row
		auto map = gcnew Dictionary<String^, TextBox^>();
		map->Add("BookName", BookNameText);
		map->Add("Author", AuthorText);
		map->Add("Descreption", DescreptionText);

		LaibraryProject::UIHelper::FillControlsFromSelectedRow(BooksTable, map);
	}
	else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
		// Print full row
		LaibraryProject::UIHelper::PrintRow(e, BooksTable);
	}
}


//SEARCH FOR STUDENTS
System::Void LaibraryProject::Books::SearchText_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::FilterDataGridView(BooksTable, SearchText->Text);

}
//PRINT AND EXPORT
System::Void LaibraryProject::Books::excelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::ExportTableToCsv(BooksTable);
}
System::Void LaibraryProject::Books::printBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::PrintTable(BooksTable);
}
