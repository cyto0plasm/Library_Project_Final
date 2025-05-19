#pragma once
#include "../Controllers/LoanController.h"
#include "../Models/userModel.h"
#include "../Controllers/BookController.h"
#include "../Controllers/StudentController.h"
namespace LaibraryProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Loan
	/// </summary>
	public ref class Loan : public System::Windows::Forms::Form
	{
	public:
		Loan(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::Panel^ panel1;
	public:
	private: System::Windows::Forms::ListBox^ resultListBooks;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::ListBox^ resultListStudents;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ closeBtn;
	private: System::Windows::Forms::Button^ miniBtn;
	private: System::Windows::Forms::Label^ Logo;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ StudentCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BookCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ statusCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ LoanDateCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ returnDateCol;
	private: System::Windows::Forms::Button^ delBtn;
		   UserModel^ currentUser;
	public:Loan(UserModel^ user);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Loan()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::FlowLayoutPanel^ BContainer;
	private: System::Windows::Forms::Panel^ SearchForStudentPanel;
	protected:

	private: System::Windows::Forms::Panel^ SearchHeaderPanel;
	private: System::Windows::Forms::Label^ SearchHeaderLabel;




	public: System::Windows::Forms::Form^ statusDialog;
	private: System::Windows::Forms::RadioButton^ returnedRadioBtn;
	private: System::Windows::Forms::RadioButton^ loanedRadioBtn;
	private: System::Windows::Forms::RadioButton^ exceededRadioBtn;
	private: System::Windows::Forms::Button^ confirmStatusBtn;
	private: System::Windows::Forms::Button^ cancelStatusBtn;
	private: System::Windows::Forms::Label^ statusDialogLabel;












	private: System::Windows::Forms::Panel^ SuggestTabelPanel;
	private: System::Windows::Forms::DataGridView^ LoanTable;





	private: System::Windows::Forms::Panel^ LoanTableHeaderPanel;
	private: System::Windows::Forms::Panel^ SearchLoanPanel;


	private: System::Windows::Forms::TextBox^ SearchLoansText;

	private: System::Windows::Forms::Label^ LoanHeaderLabel;
	private: System::Windows::Forms::Panel^ SearchForStudentsTextPanel;



	private: System::Windows::Forms::Panel^ SearchFormBookPanel;
	private: System::Windows::Forms::Panel^ SearchForBookTextPanel;
	private: System::Windows::Forms::Panel^ SearchForBookHeaderPanel;
	private: System::Windows::Forms::Label^ SearchForBookHeaderLabel;




	private: System::Windows::Forms::Panel^ LoanFormPanel;

	private: System::Windows::Forms::TextBox^ SearchForStudentsText;
	private: System::Windows::Forms::TextBox^ SearchSForBooksText;








	private: System::Windows::Forms::DateTimePicker^ ReturnDatePicker;
	private: System::Windows::Forms::Button^ LoanBtn;
	private: System::Windows::Forms::Button^ updateStatusBtn;
		   protected: virtual void WndProc(System::Windows::Forms::Message% m) override {
			   const int WM_NCHITTEST = 0x84;
			   const int HTCLIENT = 1;
			   const int HTCAPTION = 2;

			   Form::WndProc(m);

			   if (m.Msg == WM_NCHITTEST && (int)m.Result == HTCLIENT) {
				   m.Result = (System::IntPtr)HTCAPTION;
			   }
		   }

		   //LOAD LOAN TABLE DATA FOR THE USER
	private: void LoadLoansForUser(int userId);

		   //SEARCH LOAN TABLE
	private: System::Void SearchLoansText_TextChanged(System::Object^ sender, System::EventArgs^ e);
		   //SEARCH STUDENTS LIST
	private: System::Void SearchForStudentsText_TextChanged_1(System::Object^ sender, System::EventArgs^ e);
		   //SEARCH BOOK LIST 
	private: System::Void SearchSForBooksText_TextChanged_1(System::Object^ sender, System::EventArgs^ e);
		   //LOAN BUTTON TO MAKE A NEW LOAN
	private: System::Void LoanBtn_Click(System::Object^ sender, System::EventArgs^ e);
		   //UPDATE STATUS BUTTON OF THE LOAN 
	private: System::Void updateStatusBtn_Click(System::Object^ sender, System::EventArgs^ e);
		   // Implementation of the dialog creation and display method
	private: void CreateAndShowStatusDialog();
	private:System::Void confirmStatusBtn_Click(System::Object^ sender, System::EventArgs^ e);
			private: System::Void LoanTable_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e);

		   //WINDOW CONTROLS
	private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void miniBtn_Click(System::Object^ sender, System::EventArgs^ e);
		   //PRINT AND EXPORT TABLE
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);

		   public: void SelectBookFromExternal(String^ bookId, String^ bookName, String^ author);


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Loan::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->BContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->Logo = (gcnew System::Windows::Forms::Label());
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->miniBtn = (gcnew System::Windows::Forms::Button());
			this->SearchForStudentPanel = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->resultListStudents = (gcnew System::Windows::Forms::ListBox());
			this->SearchForStudentsTextPanel = (gcnew System::Windows::Forms::Panel());
			this->SearchForStudentsText = (gcnew System::Windows::Forms::TextBox());
			this->SearchHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->SearchHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->SearchFormBookPanel = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->resultListBooks = (gcnew System::Windows::Forms::ListBox());
			this->SearchForBookTextPanel = (gcnew System::Windows::Forms::Panel());
			this->SearchSForBooksText = (gcnew System::Windows::Forms::TextBox());
			this->SearchForBookHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->SearchForBookHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->LoanFormPanel = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->updateStatusBtn = (gcnew System::Windows::Forms::Button());
			this->delBtn = (gcnew System::Windows::Forms::Button());
			this->LoanBtn = (gcnew System::Windows::Forms::Button());
			this->ReturnDatePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuggestTabelPanel = (gcnew System::Windows::Forms::Panel());
			this->LoanTable = (gcnew System::Windows::Forms::DataGridView());
			this->IdCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StudentCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->BookCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->statusCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LoanDateCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->returnDateCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LoanTableHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SearchLoanPanel = (gcnew System::Windows::Forms::Panel());
			this->SearchLoansText = (gcnew System::Windows::Forms::TextBox());
			this->LoanHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->BContainer->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SearchForStudentPanel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SearchForStudentsTextPanel->SuspendLayout();
			this->SearchHeaderPanel->SuspendLayout();
			this->SearchFormBookPanel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SearchForBookTextPanel->SuspendLayout();
			this->SearchForBookHeaderPanel->SuspendLayout();
			this->LoanFormPanel->SuspendLayout();
			this->SuggestTabelPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoanTable))->BeginInit();
			this->LoanTableHeaderPanel->SuspendLayout();
			this->SearchLoanPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// BContainer
			// 
			this->BContainer->Controls->Add(this->panel3);
			this->BContainer->Controls->Add(this->SearchForStudentPanel);
			this->BContainer->Controls->Add(this->SearchFormBookPanel);
			this->BContainer->Controls->Add(this->LoanFormPanel);
			this->BContainer->Controls->Add(this->SuggestTabelPanel);
			this->BContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->BContainer->Location = System::Drawing::Point(0, 0);
			this->BContainer->Name = L"BContainer";
			this->BContainer->Size = System::Drawing::Size(882, 976);
			this->BContainer->TabIndex = 19;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->Logo);
			this->panel3->Controls->Add(this->closeBtn);
			this->panel3->Controls->Add(this->miniBtn);
			this->panel3->Location = System::Drawing::Point(3, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(879, 89);
			this->panel3->TabIndex = 24;
			// 
			// Logo
			// 
			this->Logo->AutoSize = true;
			this->Logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Logo.Image")));
			this->Logo->Location = System::Drawing::Point(11, 2);
			this->Logo->MinimumSize = System::Drawing::Size(100, 90);
			this->Logo->Name = L"Logo";
			this->Logo->Size = System::Drawing::Size(100, 90);
			this->Logo->TabIndex = 24;
			// 
			// closeBtn
			// 
			this->closeBtn->AccessibleName = L"closeBtn";
			this->closeBtn->FlatAppearance->BorderSize = 0;
			this->closeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeBtn.Image")));
			this->closeBtn->Location = System::Drawing::Point(772, 4);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(87, 74);
			this->closeBtn->TabIndex = 23;
			this->closeBtn->UseVisualStyleBackColor = true;
			this->closeBtn->Click += gcnew System::EventHandler(this, &Loan::closeBtn_Click);
			// 
			// miniBtn
			// 
			this->miniBtn->AccessibleName = L"miniBtn";
			this->miniBtn->FlatAppearance->BorderSize = 0;
			this->miniBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->miniBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"miniBtn.Image")));
			this->miniBtn->Location = System::Drawing::Point(677, 23);
			this->miniBtn->Name = L"miniBtn";
			this->miniBtn->Size = System::Drawing::Size(75, 36);
			this->miniBtn->TabIndex = 22;
			this->miniBtn->UseVisualStyleBackColor = true;
			this->miniBtn->Click += gcnew System::EventHandler(this, &Loan::miniBtn_Click);
			// 
			// SearchForStudentPanel
			// 
			this->SearchForStudentPanel->AccessibleName = L"SearchPanel";
			this->SearchForStudentPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SearchForStudentPanel->Controls->Add(this->panel2);
			this->SearchForStudentPanel->Controls->Add(this->SearchForStudentsTextPanel);
			this->SearchForStudentPanel->Controls->Add(this->SearchHeaderPanel);
			this->SearchForStudentPanel->Location = System::Drawing::Point(6, 101);
			this->SearchForStudentPanel->Margin = System::Windows::Forms::Padding(6);
			this->SearchForStudentPanel->Name = L"SearchForStudentPanel";
			this->SearchForStudentPanel->Size = System::Drawing::Size(426, 330);
			this->SearchForStudentPanel->TabIndex = 19;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->resultListStudents);
			this->panel2->Location = System::Drawing::Point(5, 132);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(412, 189);
			this->panel2->TabIndex = 22;
			// 
			// resultListStudents
			// 
			this->resultListStudents->AccessibleName = L"resultListStudents";
			this->resultListStudents->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->resultListStudents->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->resultListStudents->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->resultListStudents->FormattingEnabled = true;
			this->resultListStudents->ItemHeight = 29;
			this->resultListStudents->Location = System::Drawing::Point(14, 20);
			this->resultListStudents->Name = L"resultListStudents";
			this->resultListStudents->Size = System::Drawing::Size(385, 145);
			this->resultListStudents->TabIndex = 4;
			// 
			// SearchForStudentsTextPanel
			// 
			this->SearchForStudentsTextPanel->AccessibleName = L"SearchSuggestionsPanel";
			this->SearchForStudentsTextPanel->BackColor = System::Drawing::SystemColors::Window;
			this->SearchForStudentsTextPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SearchForStudentsTextPanel->Controls->Add(this->SearchForStudentsText);
			this->SearchForStudentsTextPanel->Location = System::Drawing::Point(5, 86);
			this->SearchForStudentsTextPanel->Name = L"SearchForStudentsTextPanel";
			this->SearchForStudentsTextPanel->Size = System::Drawing::Size(412, 45);
			this->SearchForStudentsTextPanel->TabIndex = 21;
			// 
			// SearchForStudentsText
			// 
			this->SearchForStudentsText->AccessibleName = L"SearchForStudentsText";
			this->SearchForStudentsText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SearchForStudentsText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SearchForStudentsText->Location = System::Drawing::Point(11, 5);
			this->SearchForStudentsText->Multiline = true;
			this->SearchForStudentsText->Name = L"SearchForStudentsText";
			this->SearchForStudentsText->Size = System::Drawing::Size(391, 32);
			this->SearchForStudentsText->TabIndex = 0;
			this->SearchForStudentsText->TextChanged += gcnew System::EventHandler(this, &Loan::SearchForStudentsText_TextChanged_1);
			// 
			// SearchHeaderPanel
			// 
			this->SearchHeaderPanel->AccessibleName = L"SearchHeaderPanel";
			this->SearchHeaderPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SearchHeaderPanel->Controls->Add(this->SearchHeaderLabel);
			this->SearchHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->SearchHeaderPanel->Location = System::Drawing::Point(0, 0);
			this->SearchHeaderPanel->Name = L"SearchHeaderPanel";
			this->SearchHeaderPanel->Size = System::Drawing::Size(424, 80);
			this->SearchHeaderPanel->TabIndex = 2;
			// 
			// SearchHeaderLabel
			// 
			this->SearchHeaderLabel->AccessibleName = L"SearchHeaderLabel";
			this->SearchHeaderLabel->AutoSize = true;
			this->SearchHeaderLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchHeaderLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->SearchHeaderLabel->Location = System::Drawing::Point(65, 20);
			this->SearchHeaderLabel->Name = L"SearchHeaderLabel";
			this->SearchHeaderLabel->Size = System::Drawing::Size(297, 41);
			this->SearchHeaderLabel->TabIndex = 1;
			this->SearchHeaderLabel->Text = L"Search For Students";
			// 
			// SearchFormBookPanel
			// 
			this->SearchFormBookPanel->AccessibleName = L"SearchPanel";
			this->SearchFormBookPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SearchFormBookPanel->Controls->Add(this->panel1);
			this->SearchFormBookPanel->Controls->Add(this->SearchForBookTextPanel);
			this->SearchFormBookPanel->Controls->Add(this->SearchForBookHeaderPanel);
			this->SearchFormBookPanel->Location = System::Drawing::Point(444, 101);
			this->SearchFormBookPanel->Margin = System::Windows::Forms::Padding(6);
			this->SearchFormBookPanel->Name = L"SearchFormBookPanel";
			this->SearchFormBookPanel->Size = System::Drawing::Size(426, 330);
			this->SearchFormBookPanel->TabIndex = 20;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->resultListBooks);
			this->panel1->Location = System::Drawing::Point(5, 132);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(412, 189);
			this->panel1->TabIndex = 22;
			// 
			// resultListBooks
			// 
			this->resultListBooks->AccessibleName = L"resultListBooks";
			this->resultListBooks->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->resultListBooks->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->resultListBooks->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultListBooks->FormattingEnabled = true;
			this->resultListBooks->ItemHeight = 29;
			this->resultListBooks->Location = System::Drawing::Point(12, 20);
			this->resultListBooks->Name = L"resultListBooks";
			this->resultListBooks->Size = System::Drawing::Size(385, 145);
			this->resultListBooks->TabIndex = 4;
			// 
			// SearchForBookTextPanel
			// 
			this->SearchForBookTextPanel->AccessibleName = L"SearchSuggestionsPanel";
			this->SearchForBookTextPanel->BackColor = System::Drawing::SystemColors::Window;
			this->SearchForBookTextPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SearchForBookTextPanel->Controls->Add(this->SearchSForBooksText);
			this->SearchForBookTextPanel->Location = System::Drawing::Point(5, 86);
			this->SearchForBookTextPanel->Name = L"SearchForBookTextPanel";
			this->SearchForBookTextPanel->Size = System::Drawing::Size(412, 45);
			this->SearchForBookTextPanel->TabIndex = 21;
			// 
			// SearchSForBooksText
			// 
			this->SearchSForBooksText->AccessibleName = L"SearchSForBooksText";
			this->SearchSForBooksText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SearchSForBooksText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SearchSForBooksText->Location = System::Drawing::Point(12, 7);
			this->SearchSForBooksText->Multiline = true;
			this->SearchSForBooksText->Name = L"SearchSForBooksText";
			this->SearchSForBooksText->Size = System::Drawing::Size(391, 32);
			this->SearchSForBooksText->TabIndex = 0;
			this->SearchSForBooksText->TextChanged += gcnew System::EventHandler(this, &Loan::SearchSForBooksText_TextChanged_1);
			// 
			// SearchForBookHeaderPanel
			// 
			this->SearchForBookHeaderPanel->AccessibleName = L"SearchHeaderPanel";
			this->SearchForBookHeaderPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SearchForBookHeaderPanel->Controls->Add(this->SearchForBookHeaderLabel);
			this->SearchForBookHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->SearchForBookHeaderPanel->Location = System::Drawing::Point(0, 0);
			this->SearchForBookHeaderPanel->Name = L"SearchForBookHeaderPanel";
			this->SearchForBookHeaderPanel->Size = System::Drawing::Size(424, 80);
			this->SearchForBookHeaderPanel->TabIndex = 2;
			// 
			// SearchForBookHeaderLabel
			// 
			this->SearchForBookHeaderLabel->AccessibleName = L"SearchHeaderLabel";
			this->SearchForBookHeaderLabel->AutoSize = true;
			this->SearchForBookHeaderLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchForBookHeaderLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->SearchForBookHeaderLabel->Location = System::Drawing::Point(80, 20);
			this->SearchForBookHeaderLabel->Name = L"SearchForBookHeaderLabel";
			this->SearchForBookHeaderLabel->Size = System::Drawing::Size(258, 41);
			this->SearchForBookHeaderLabel->TabIndex = 1;
			this->SearchForBookHeaderLabel->Text = L"Search For Books";
			// 
			// LoanFormPanel
			// 
			this->LoanFormPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LoanFormPanel->Controls->Add(this->label1);
			this->LoanFormPanel->Controls->Add(this->updateStatusBtn);
			this->LoanFormPanel->Controls->Add(this->delBtn);
			this->LoanFormPanel->Controls->Add(this->LoanBtn);
			this->LoanFormPanel->Controls->Add(this->ReturnDatePicker);
			this->LoanFormPanel->Location = System::Drawing::Point(5, 440);
			this->LoanFormPanel->Margin = System::Windows::Forms::Padding(5, 3, 3, 3);
			this->LoanFormPanel->Name = L"LoanFormPanel";
			this->LoanFormPanel->Size = System::Drawing::Size(865, 85);
			this->LoanFormPanel->TabIndex = 21;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(175, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(153, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Chose Retern Date";
			// 
			// updateStatusBtn
			// 
			this->updateStatusBtn->AccessibleName = L"updateStatusBtn";
			this->updateStatusBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->updateStatusBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->updateStatusBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"updateStatusBtn.Image")));
			this->updateStatusBtn->Location = System::Drawing::Point(568, 12);
			this->updateStatusBtn->Name = L"updateStatusBtn";
			this->updateStatusBtn->Size = System::Drawing::Size(181, 60);
			this->updateStatusBtn->TabIndex = 1;
			this->updateStatusBtn->Text = L"update status";
			this->updateStatusBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->updateStatusBtn->UseVisualStyleBackColor = true;
			this->updateStatusBtn->Click += gcnew System::EventHandler(this, &Loan::updateStatusBtn_Click);
			// 
			// delBtn
			// 
			this->delBtn->AccessibleName = L"delBtn";
			this->delBtn->BackColor = System::Drawing::SystemColors::Control;
			this->delBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->delBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"delBtn.Image")));
			this->delBtn->Location = System::Drawing::Point(763, 12);
			this->delBtn->Name = L"delBtn";
			this->delBtn->Size = System::Drawing::Size(79, 60);
			this->delBtn->TabIndex = 1;
			this->delBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->delBtn->UseVisualStyleBackColor = false;
			this->delBtn->Click += gcnew System::EventHandler(this, &Loan::delBtn_Click);
			// 
			// LoanBtn
			// 
			this->LoanBtn->AccessibleName = L"LoanBtn";
			this->LoanBtn->BackColor = System::Drawing::SystemColors::Info;
			this->LoanBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->LoanBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoanBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LoanBtn.Image")));
			this->LoanBtn->Location = System::Drawing::Point(444, 12);
			this->LoanBtn->Name = L"LoanBtn";
			this->LoanBtn->Size = System::Drawing::Size(111, 60);
			this->LoanBtn->TabIndex = 1;
			this->LoanBtn->Text = L"Loan";
			this->LoanBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->LoanBtn->UseVisualStyleBackColor = false;
			this->LoanBtn->Click += gcnew System::EventHandler(this, &Loan::LoanBtn_Click);
			// 
			// ReturnDatePicker
			// 
			this->ReturnDatePicker->AccessibleName = L"ReturnDatePicker";
			this->ReturnDatePicker->Location = System::Drawing::Point(131, 50);
			this->ReturnDatePicker->Name = L"ReturnDatePicker";
			this->ReturnDatePicker->Size = System::Drawing::Size(248, 22);
			this->ReturnDatePicker->TabIndex = 0;
			// 
			// SuggestTabelPanel
			// 
			this->SuggestTabelPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SuggestTabelPanel->Controls->Add(this->LoanTable);
			this->SuggestTabelPanel->Controls->Add(this->LoanTableHeaderPanel);
			this->SuggestTabelPanel->Location = System::Drawing::Point(5, 533);
			this->SuggestTabelPanel->Margin = System::Windows::Forms::Padding(5, 5, 3, 5);
			this->SuggestTabelPanel->Name = L"SuggestTabelPanel";
			this->SuggestTabelPanel->Size = System::Drawing::Size(866, 344);
			this->SuggestTabelPanel->TabIndex = 18;
			// 
			// LoanTable
			// 
			this->LoanTable->AccessibleName = L"LoanTable";
			this->LoanTable->AllowUserToAddRows = false;
			this->LoanTable->AllowUserToResizeRows = false;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)));
			this->LoanTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->LoanTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->LoanTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->LoanTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->LoanTable->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->LoanTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->LoanTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->LoanTable->ColumnHeadersHeight = 50;
			this->LoanTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->LoanTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->IdCol, this->StudentCol,
					this->BookCol, this->statusCol, this->LoanDateCol, this->returnDateCol
			});
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->LoanTable->DefaultCellStyle = dataGridViewCellStyle4;
			this->LoanTable->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LoanTable->EnableHeadersVisualStyles = false;
			this->LoanTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->LoanTable->Location = System::Drawing::Point(0, 66);
			this->LoanTable->Name = L"LoanTable";
			this->LoanTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->LoanTable->RowHeadersVisible = false;
			this->LoanTable->RowHeadersWidth = 4;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->LoanTable->RowsDefaultCellStyle = dataGridViewCellStyle5;
			this->LoanTable->RowTemplate->DefaultCellStyle->Padding = System::Windows::Forms::Padding(5);
			this->LoanTable->RowTemplate->Height = 40;
			this->LoanTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->LoanTable->Size = System::Drawing::Size(864, 276);
			this->LoanTable->TabIndex = 19;
			this->LoanTable->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &Loan::LoanTable_CellFormatting);
			// 
			// IdCol
			// 
			this->IdCol->DataPropertyName = L"IdCol";
			this->IdCol->FillWeight = 10;
			this->IdCol->HeaderText = L"ID";
			this->IdCol->MaxInputLength = 20;
			this->IdCol->MinimumWidth = 6;
			this->IdCol->Name = L"IdCol";
			this->IdCol->ReadOnly = true;
			// 
			// StudentCol
			// 
			this->StudentCol->DataPropertyName = L"StudentCol";
			this->StudentCol->FillWeight = 25;
			this->StudentCol->HeaderText = L"Student";
			this->StudentCol->MaxInputLength = 40;
			this->StudentCol->MinimumWidth = 6;
			this->StudentCol->Name = L"StudentCol";
			this->StudentCol->ReadOnly = true;
			// 
			// BookCol
			// 
			this->BookCol->DataPropertyName = L"BookCol";
			this->BookCol->FillWeight = 35;
			this->BookCol->HeaderText = L"Book Loaned";
			this->BookCol->MaxInputLength = 10;
			this->BookCol->MinimumWidth = 6;
			this->BookCol->Name = L"BookCol";
			this->BookCol->ReadOnly = true;
			// 
			// statusCol
			// 
			this->statusCol->DataPropertyName = L"statusCol";
			this->statusCol->FillWeight = 25;
			this->statusCol->HeaderText = L"status";
			this->statusCol->MinimumWidth = 6;
			this->statusCol->Name = L"statusCol";
			// 
			// LoanDateCol
			// 
			this->LoanDateCol->DataPropertyName = L"LoanDateCol";
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->LoanDateCol->DefaultCellStyle = dataGridViewCellStyle3;
			this->LoanDateCol->FillWeight = 40;
			this->LoanDateCol->HeaderText = L"Loan Date";
			this->LoanDateCol->MaxInputLength = 1000;
			this->LoanDateCol->MinimumWidth = 6;
			this->LoanDateCol->Name = L"LoanDateCol";
			this->LoanDateCol->ReadOnly = true;
			// 
			// returnDateCol
			// 
			this->returnDateCol->DataPropertyName = L"returnDateCol";
			this->returnDateCol->FillWeight = 40;
			this->returnDateCol->HeaderText = L"return Date";
			this->returnDateCol->MinimumWidth = 6;
			this->returnDateCol->Name = L"returnDateCol";
			// 
			// LoanTableHeaderPanel
			// 
			this->LoanTableHeaderPanel->AccessibleName = L"LoanTableHeaderPanel";
			this->LoanTableHeaderPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->LoanTableHeaderPanel->Controls->Add(this->button2);
			this->LoanTableHeaderPanel->Controls->Add(this->button1);
			this->LoanTableHeaderPanel->Controls->Add(this->SearchLoanPanel);
			this->LoanTableHeaderPanel->Controls->Add(this->LoanHeaderLabel);
			this->LoanTableHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->LoanTableHeaderPanel->Location = System::Drawing::Point(0, 0);
			this->LoanTableHeaderPanel->Name = L"LoanTableHeaderPanel";
			this->LoanTableHeaderPanel->Size = System::Drawing::Size(864, 66);
			this->LoanTableHeaderPanel->TabIndex = 0;
			// 
			// button2
			// 
			this->button2->AccessibleName = L"LoanBtn";
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(107)), static_cast<System::Int32>(static_cast<System::Byte>(206)),
				static_cast<System::Int32>(static_cast<System::Byte>(112)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(273, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 50);
			this->button2->TabIndex = 21;
			this->button2->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Loan::button2_Click);
			// 
			// button1
			// 
			this->button1->AccessibleName = L"LoanBtn";
			this->button1->BackColor = System::Drawing::SystemColors::Info;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(179, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 50);
			this->button1->TabIndex = 21;
			this->button1->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Loan::button1_Click);
			// 
			// SearchLoanPanel
			// 
			this->SearchLoanPanel->AccessibleName = L"SearchLoanPanel";
			this->SearchLoanPanel->BackColor = System::Drawing::SystemColors::Window;
			this->SearchLoanPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SearchLoanPanel->Controls->Add(this->SearchLoansText);
			this->SearchLoanPanel->Location = System::Drawing::Point(437, 11);
			this->SearchLoanPanel->Name = L"SearchLoanPanel";
			this->SearchLoanPanel->Size = System::Drawing::Size(414, 45);
			this->SearchLoanPanel->TabIndex = 20;
			// 
			// SearchLoansText
			// 
			this->SearchLoansText->AccessibleName = L"SearchLoansText";
			this->SearchLoansText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SearchLoansText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchLoansText->Location = System::Drawing::Point(10, 7);
			this->SearchLoansText->Multiline = true;
			this->SearchLoansText->Name = L"SearchLoansText";
			this->SearchLoansText->Size = System::Drawing::Size(393, 32);
			this->SearchLoansText->TabIndex = 0;
			this->SearchLoansText->TextChanged += gcnew System::EventHandler(this, &Loan::SearchLoansText_TextChanged);
			// 
			// LoanHeaderLabel
			// 
			this->LoanHeaderLabel->AccessibleName = L"LoanHeaderLabel";
			this->LoanHeaderLabel->AutoSize = true;
			this->LoanHeaderLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoanHeaderLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->LoanHeaderLabel->Location = System::Drawing::Point(5, 9);
			this->LoanHeaderLabel->Name = L"LoanHeaderLabel";
			this->LoanHeaderLabel->Size = System::Drawing::Size(168, 41);
			this->LoanHeaderLabel->TabIndex = 1;
			this->LoanHeaderLabel->Text = L"Loan Table";
			// 
			// Loan
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(882, 976);
			this->Controls->Add(this->BContainer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Loan";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Loan";
			this->BContainer->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->SearchForStudentPanel->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->SearchForStudentsTextPanel->ResumeLayout(false);
			this->SearchForStudentsTextPanel->PerformLayout();
			this->SearchHeaderPanel->ResumeLayout(false);
			this->SearchHeaderPanel->PerformLayout();
			this->SearchFormBookPanel->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->SearchForBookTextPanel->ResumeLayout(false);
			this->SearchForBookTextPanel->PerformLayout();
			this->SearchForBookHeaderPanel->ResumeLayout(false);
			this->SearchForBookHeaderPanel->PerformLayout();
			this->LoanFormPanel->ResumeLayout(false);
			this->LoanFormPanel->PerformLayout();
			this->SuggestTabelPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LoanTable))->EndInit();
			this->LoanTableHeaderPanel->ResumeLayout(false);
			this->LoanTableHeaderPanel->PerformLayout();
			this->SearchLoanPanel->ResumeLayout(false);
			this->SearchLoanPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion




private: System::Void delBtn_Click(System::Object^ sender, System::EventArgs^ e);
};
}
