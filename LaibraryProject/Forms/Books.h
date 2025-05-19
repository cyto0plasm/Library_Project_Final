#pragma once
#include "../Models/Book.h"
#include "../Controllers/BookController.h"
#include "../Models/userModel.h"
#include "../HelperMethods/UIHelper.h"
#include "../Forms/Loan.h"
namespace LaibraryProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Books
	/// </summary>
	public ref class Books : public System::Windows::Forms::Form
	{
	public:
		Books(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	public:Books(UserModel^ user);
	protected: virtual void WndProc(System::Windows::Forms::Message% m) override {
		const int WM_NCHITTEST = 0x84;
		const int HTCLIENT = 1;
		const int HTCAPTION = 2;

		Form::WndProc(m);

		if (m.Msg == WM_NCHITTEST && (int)m.Result == HTCLIENT) {
			m.Result = (System::IntPtr)HTCAPTION;
		}
	}

	private: System::Windows::Forms::Panel^ panel3;
	public:
	private: System::Windows::Forms::Label^ Logo;
	private: System::Windows::Forms::Button^ closeBtn;
	private: System::Windows::Forms::Button^ miniBtn;
	private: System::Windows::Forms::Button^ excelBtn;
	private: System::Windows::Forms::Button^ printBtn;
		   UserModel^ currentUser;
		   Loan^ loanForm = nullptr;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Books()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ BContainer;
	protected:
	private: System::Windows::Forms::Panel^ SuggestTabelPanel;
	private: System::Windows::Forms::DataGridView^ BooksTable;




	private: System::Windows::Forms::Panel^ BooksTableHeaderPanel;
	private: System::Windows::Forms::Panel^ SearchPanel;
	private: System::Windows::Forms::TextBox^ SearchText;
	private: System::Windows::Forms::Label^ BooksTableHeader;
	private: System::Windows::Forms::Panel^ SuggestFromContainer;
	private: System::Windows::Forms::Panel^ StudentsForm;
	private: System::Windows::Forms::Label^ AuthorLabel;
	private: System::Windows::Forms::Panel^ AuthorPanel;


	private: System::Windows::Forms::TextBox^ AuthorText;

	private: System::Windows::Forms::Label^ DescriptionLabel;
	private: System::Windows::Forms::Panel^ DescreptionPanel;
	private: System::Windows::Forms::TextBox^ DescreptionText;






	private: System::Windows::Forms::Panel^ BookNamePanel;

	private: System::Windows::Forms::TextBox^ BookNameText;
	private: System::Windows::Forms::Label^ BookNameLabel;

	private: System::Windows::Forms::FlowLayoutPanel^ StudentsControlBtns;
	private: System::Windows::Forms::Button^ AddBookBtn;

	private: System::Windows::Forms::Button^ EditBookBtn;

	private: System::Windows::Forms::Button^ DeleteBookBtn;

	private: System::Windows::Forms::Panel^ BooksHeaderPanel;
	private: System::Windows::Forms::Label^ BooksHeaderFormLabel;
	private: System::Windows::Forms::Button^ sendBookToLoanScreenBtn;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ BookName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Author;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Descreption;

	private:
		//CRUDS OPERATIONS
	private: System::Void AddBookBtn_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void EditBookBtn_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void DeleteBookBtn_Click(System::Object^ sender, System::EventArgs^ e);
		   //LOAD THE BOOKS DATA
		   void LoadBooksForUser();


		   //MOVE DATA FROM TABLE TO FORM
	private: System::Void BooksTable_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e);


		   //SEARCH FOR STUDENTS
	private: System::Void SearchText_TextChanged(System::Object^ sender, System::EventArgs^ e);
		   //PRINT AND EXPORT
	private: System::Void excelBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void printBtn_Click(System::Object^ sender, System::EventArgs^ e);
		   /// <summary>
		   /// Required designer variable.
		   /// </summary>
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		
		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Books::typeid));
			   this->BContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->panel3 = (gcnew System::Windows::Forms::Panel());
			   this->Logo = (gcnew System::Windows::Forms::Label());
			   this->closeBtn = (gcnew System::Windows::Forms::Button());
			   this->miniBtn = (gcnew System::Windows::Forms::Button());
			   this->SuggestTabelPanel = (gcnew System::Windows::Forms::Panel());
			   this->BooksTable = (gcnew System::Windows::Forms::DataGridView());
			   this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->BookName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Author = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Descreption = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->BooksTableHeaderPanel = (gcnew System::Windows::Forms::Panel());
			   this->excelBtn = (gcnew System::Windows::Forms::Button());
			   this->printBtn = (gcnew System::Windows::Forms::Button());
			   this->SearchPanel = (gcnew System::Windows::Forms::Panel());
			   this->SearchText = (gcnew System::Windows::Forms::TextBox());
			   this->BooksTableHeader = (gcnew System::Windows::Forms::Label());
			   this->SuggestFromContainer = (gcnew System::Windows::Forms::Panel());
			   this->StudentsForm = (gcnew System::Windows::Forms::Panel());
			   this->sendBookToLoanScreenBtn = (gcnew System::Windows::Forms::Button());
			   this->AuthorLabel = (gcnew System::Windows::Forms::Label());
			   this->AuthorPanel = (gcnew System::Windows::Forms::Panel());
			   this->AuthorText = (gcnew System::Windows::Forms::TextBox());
			   this->DescriptionLabel = (gcnew System::Windows::Forms::Label());
			   this->DescreptionPanel = (gcnew System::Windows::Forms::Panel());
			   this->DescreptionText = (gcnew System::Windows::Forms::TextBox());
			   this->BookNamePanel = (gcnew System::Windows::Forms::Panel());
			   this->BookNameText = (gcnew System::Windows::Forms::TextBox());
			   this->BookNameLabel = (gcnew System::Windows::Forms::Label());
			   this->StudentsControlBtns = (gcnew System::Windows::Forms::FlowLayoutPanel());
			   this->AddBookBtn = (gcnew System::Windows::Forms::Button());
			   this->EditBookBtn = (gcnew System::Windows::Forms::Button());
			   this->DeleteBookBtn = (gcnew System::Windows::Forms::Button());
			   this->BooksHeaderPanel = (gcnew System::Windows::Forms::Panel());
			   this->BooksHeaderFormLabel = (gcnew System::Windows::Forms::Label());
			   this->BContainer->SuspendLayout();
			   this->panel3->SuspendLayout();
			   this->SuggestTabelPanel->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BooksTable))->BeginInit();
			   this->BooksTableHeaderPanel->SuspendLayout();
			   this->SearchPanel->SuspendLayout();
			   this->SuggestFromContainer->SuspendLayout();
			   this->StudentsForm->SuspendLayout();
			   this->AuthorPanel->SuspendLayout();
			   this->DescreptionPanel->SuspendLayout();
			   this->BookNamePanel->SuspendLayout();
			   this->StudentsControlBtns->SuspendLayout();
			   this->BooksHeaderPanel->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // BContainer
			   // 
			   this->BContainer->Controls->Add(this->panel3);
			   this->BContainer->Controls->Add(this->SuggestTabelPanel);
			   this->BContainer->Controls->Add(this->SuggestFromContainer);
			   this->BContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->BContainer->Location = System::Drawing::Point(0, 0);
			   this->BContainer->Name = L"BContainer";
			   this->BContainer->Size = System::Drawing::Size(1317, 653);
			   this->BContainer->TabIndex = 20;
			   // 
			   // panel3
			   // 
			   this->panel3->Controls->Add(this->Logo);
			   this->panel3->Controls->Add(this->closeBtn);
			   this->panel3->Controls->Add(this->miniBtn);
			   this->panel3->Location = System::Drawing::Point(3, 3);
			   this->panel3->Name = L"panel3";
			   this->panel3->Size = System::Drawing::Size(1314, 89);
			   this->panel3->TabIndex = 26;
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
			   this->closeBtn->Location = System::Drawing::Point(1218, 6);
			   this->closeBtn->Name = L"closeBtn";
			   this->closeBtn->Size = System::Drawing::Size(87, 74);
			   this->closeBtn->TabIndex = 23;
			   this->closeBtn->UseVisualStyleBackColor = true;
			   this->closeBtn->Click += gcnew System::EventHandler(this, &Books::closeBtn_Click);
			   // 
			   // miniBtn
			   // 
			   this->miniBtn->AccessibleName = L"miniBtn";
			   this->miniBtn->FlatAppearance->BorderSize = 0;
			   this->miniBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->miniBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"miniBtn.Image")));
			   this->miniBtn->Location = System::Drawing::Point(1123, 25);
			   this->miniBtn->Name = L"miniBtn";
			   this->miniBtn->Size = System::Drawing::Size(75, 36);
			   this->miniBtn->TabIndex = 22;
			   this->miniBtn->UseVisualStyleBackColor = true;
			   this->miniBtn->Click += gcnew System::EventHandler(this, &Books::miniBtn_Click);
			   // 
			   // SuggestTabelPanel
			   // 
			   this->SuggestTabelPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->SuggestTabelPanel->Controls->Add(this->BooksTable);
			   this->SuggestTabelPanel->Controls->Add(this->BooksTableHeaderPanel);
			   this->SuggestTabelPanel->Location = System::Drawing::Point(5, 100);
			   this->SuggestTabelPanel->Margin = System::Windows::Forms::Padding(5, 5, 3, 5);
			   this->SuggestTabelPanel->Name = L"SuggestTabelPanel";
			   this->SuggestTabelPanel->Size = System::Drawing::Size(824, 543);
			   this->SuggestTabelPanel->TabIndex = 18;
			   // 
			   // BooksTable
			   // 
			   this->BooksTable->AccessibleName = L"BooksTable";
			   this->BooksTable->AllowUserToAddRows = false;
			   this->BooksTable->AllowUserToResizeRows = false;
			   dataGridViewCellStyle6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				   static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)));
			   this->BooksTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle6;
			   this->BooksTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			   this->BooksTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				   static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			   this->BooksTable->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			   this->BooksTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			   dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			   dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				   static_cast<System::Int32>(static_cast<System::Byte>(50)));
			   dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
			   dataGridViewCellStyle7->ForeColor = System::Drawing::Color::White;
			   dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				   static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			   dataGridViewCellStyle7->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			   dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			   this->BooksTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle7;
			   this->BooksTable->ColumnHeadersHeight = 50;
			   this->BooksTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			   this->BooksTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				   this->Id, this->BookName,
					   this->Author, this->Descreption
			   });
			   dataGridViewCellStyle9->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			   dataGridViewCellStyle9->BackColor = System::Drawing::Color::White;
			   dataGridViewCellStyle9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			   dataGridViewCellStyle9->ForeColor = System::Drawing::SystemColors::ControlText;
			   dataGridViewCellStyle9->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)),
				   static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			   dataGridViewCellStyle9->SelectionForeColor = System::Drawing::Color::Black;
			   dataGridViewCellStyle9->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			   this->BooksTable->DefaultCellStyle = dataGridViewCellStyle9;
			   this->BooksTable->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->BooksTable->EnableHeadersVisualStyles = false;
			   this->BooksTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				   static_cast<System::Int32>(static_cast<System::Byte>(230)));
			   this->BooksTable->Location = System::Drawing::Point(0, 81);
			   this->BooksTable->Name = L"BooksTable";
			   this->BooksTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			   this->BooksTable->RowHeadersVisible = false;
			   this->BooksTable->RowHeadersWidth = 4;
			   dataGridViewCellStyle10->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			   this->BooksTable->RowsDefaultCellStyle = dataGridViewCellStyle10;
			   this->BooksTable->RowTemplate->DefaultCellStyle->Padding = System::Windows::Forms::Padding(5);
			   this->BooksTable->RowTemplate->Height = 40;
			   this->BooksTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			   this->BooksTable->Size = System::Drawing::Size(822, 460);
			   this->BooksTable->TabIndex = 19;
			   this->BooksTable->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Books::BooksTable_CellMouseClick);
			   // 
			   // Id
			   // 
			   this->Id->DataPropertyName = L"Id";
			   this->Id->FillWeight = 15;
			   this->Id->HeaderText = L"ID";
			   this->Id->MaxInputLength = 20;
			   this->Id->MinimumWidth = 6;
			   this->Id->Name = L"Id";
			   this->Id->ReadOnly = true;
			   // 
			   // BookName
			   // 
			   this->BookName->DataPropertyName = L"BookName";
			   this->BookName->FillWeight = 25;
			   this->BookName->HeaderText = L"Book Name";
			   this->BookName->MaxInputLength = 40;
			   this->BookName->MinimumWidth = 6;
			   this->BookName->Name = L"BookName";
			   this->BookName->ReadOnly = true;
			   // 
			   // Author
			   // 
			   this->Author->DataPropertyName = L"Author";
			   this->Author->FillWeight = 30;
			   this->Author->HeaderText = L"Author";
			   this->Author->MaxInputLength = 10;
			   this->Author->MinimumWidth = 6;
			   this->Author->Name = L"Author";
			   this->Author->ReadOnly = true;
			   // 
			   // Descreption
			   // 
			   this->Descreption->DataPropertyName = L"Descreption";
			   dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			   this->Descreption->DefaultCellStyle = dataGridViewCellStyle8;
			   this->Descreption->FillWeight = 40;
			   this->Descreption->HeaderText = L"Descreption";
			   this->Descreption->MaxInputLength = 1000;
			   this->Descreption->MinimumWidth = 6;
			   this->Descreption->Name = L"Descreption";
			   this->Descreption->ReadOnly = true;
			   // 
			   // BooksTableHeaderPanel
			   // 
			   this->BooksTableHeaderPanel->AccessibleName = L"BooksTableHeaderPanel";
			   this->BooksTableHeaderPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->BooksTableHeaderPanel->Controls->Add(this->excelBtn);
			   this->BooksTableHeaderPanel->Controls->Add(this->printBtn);
			   this->BooksTableHeaderPanel->Controls->Add(this->SearchPanel);
			   this->BooksTableHeaderPanel->Controls->Add(this->BooksTableHeader);
			   this->BooksTableHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			   this->BooksTableHeaderPanel->Location = System::Drawing::Point(0, 0);
			   this->BooksTableHeaderPanel->Name = L"BooksTableHeaderPanel";
			   this->BooksTableHeaderPanel->Size = System::Drawing::Size(822, 81);
			   this->BooksTableHeaderPanel->TabIndex = 0;
			   // 
			   // excelBtn
			   // 
			   this->excelBtn->AccessibleName = L"excelBtn";
			   this->excelBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(107)), static_cast<System::Int32>(static_cast<System::Byte>(206)),
				   static_cast<System::Int32>(static_cast<System::Byte>(112)));
			   this->excelBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->excelBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->excelBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"excelBtn.Image")));
			   this->excelBtn->Location = System::Drawing::Point(316, 15);
			   this->excelBtn->Name = L"excelBtn";
			   this->excelBtn->Size = System::Drawing::Size(75, 50);
			   this->excelBtn->TabIndex = 24;
			   this->excelBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			   this->excelBtn->UseVisualStyleBackColor = false;
			   this->excelBtn->Click += gcnew System::EventHandler(this, &Books::excelBtn_Click);
			   // 
			   // printBtn
			   // 
			   this->printBtn->AccessibleName = L"printBtn";
			   this->printBtn->BackColor = System::Drawing::SystemColors::Info;
			   this->printBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->printBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->printBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"printBtn.Image")));
			   this->printBtn->Location = System::Drawing::Point(222, 15);
			   this->printBtn->Name = L"printBtn";
			   this->printBtn->Size = System::Drawing::Size(75, 50);
			   this->printBtn->TabIndex = 25;
			   this->printBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			   this->printBtn->UseVisualStyleBackColor = false;
			   this->printBtn->Click += gcnew System::EventHandler(this, &Books::printBtn_Click);
			   // 
			   // SearchPanel
			   // 
			   this->SearchPanel->AccessibleName = L"SearchPanel";
			   this->SearchPanel->BackColor = System::Drawing::SystemColors::Window;
			   this->SearchPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->SearchPanel->Controls->Add(this->SearchText);
			   this->SearchPanel->Location = System::Drawing::Point(447, 20);
			   this->SearchPanel->Name = L"SearchPanel";
			   this->SearchPanel->Size = System::Drawing::Size(368, 45);
			   this->SearchPanel->TabIndex = 20;
			   // 
			   // SearchText
			   // 
			   this->SearchText->AccessibleName = L"SearchText";
			   this->SearchText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->SearchText->Location = System::Drawing::Point(18, 5);
			   this->SearchText->Multiline = true;
			   this->SearchText->Name = L"SearchText";
			   this->SearchText->Size = System::Drawing::Size(337, 32);
			   this->SearchText->TabIndex = 0;
			   this->SearchText->TextChanged += gcnew System::EventHandler(this, &Books::SearchText_TextChanged);
			   // 
			   // BooksTableHeader
			   // 
			   this->BooksTableHeader->AccessibleName = L"BooksTableHeader";
			   this->BooksTableHeader->AutoSize = true;
			   this->BooksTableHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BooksTableHeader->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				   static_cast<System::Int32>(static_cast<System::Byte>(120)));
			   this->BooksTableHeader->Location = System::Drawing::Point(14, 18);
			   this->BooksTableHeader->Name = L"BooksTableHeader";
			   this->BooksTableHeader->Size = System::Drawing::Size(186, 41);
			   this->BooksTableHeader->TabIndex = 1;
			   this->BooksTableHeader->Text = L"Books Table";
			   // 
			   // SuggestFromContainer
			   // 
			   this->SuggestFromContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->SuggestFromContainer->Controls->Add(this->StudentsForm);
			   this->SuggestFromContainer->Controls->Add(this->StudentsControlBtns);
			   this->SuggestFromContainer->Controls->Add(this->BooksHeaderPanel);
			   this->SuggestFromContainer->Location = System::Drawing::Point(838, 101);
			   this->SuggestFromContainer->Margin = System::Windows::Forms::Padding(6);
			   this->SuggestFromContainer->Name = L"SuggestFromContainer";
			   this->SuggestFromContainer->Size = System::Drawing::Size(470, 542);
			   this->SuggestFromContainer->TabIndex = 16;
			   // 
			   // StudentsForm
			   // 
			   this->StudentsForm->AccessibleName = L"StudentsForm";
			   this->StudentsForm->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->StudentsForm->Controls->Add(this->sendBookToLoanScreenBtn);
			   this->StudentsForm->Controls->Add(this->AuthorLabel);
			   this->StudentsForm->Controls->Add(this->AuthorPanel);
			   this->StudentsForm->Controls->Add(this->DescriptionLabel);
			   this->StudentsForm->Controls->Add(this->DescreptionPanel);
			   this->StudentsForm->Controls->Add(this->BookNamePanel);
			   this->StudentsForm->Controls->Add(this->BookNameLabel);
			   this->StudentsForm->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->StudentsForm->Location = System::Drawing::Point(0, 80);
			   this->StudentsForm->Name = L"StudentsForm";
			   this->StudentsForm->Size = System::Drawing::Size(468, 388);
			   this->StudentsForm->TabIndex = 3;
			   // 
			   // sendBookToLoanScreenBtn
			   // 
			   this->sendBookToLoanScreenBtn->AccessibleName = L"sendBookToLoanScreenBtn";
			   this->sendBookToLoanScreenBtn->BackColor = System::Drawing::SystemColors::Info;
			   this->sendBookToLoanScreenBtn->FlatAppearance->BorderSize = 0;
			   this->sendBookToLoanScreenBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->sendBookToLoanScreenBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->sendBookToLoanScreenBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->sendBookToLoanScreenBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sendBookToLoanScreenBtn.Image")));
			   this->sendBookToLoanScreenBtn->Location = System::Drawing::Point(6, 323);
			   this->sendBookToLoanScreenBtn->Margin = System::Windows::Forms::Padding(5);
			   this->sendBookToLoanScreenBtn->Name = L"sendBookToLoanScreenBtn";
			   this->sendBookToLoanScreenBtn->Size = System::Drawing::Size(142, 56);
			   this->sendBookToLoanScreenBtn->TabIndex = 0;
			   this->sendBookToLoanScreenBtn->Text = L"Loan";
			   this->sendBookToLoanScreenBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			   this->sendBookToLoanScreenBtn->UseVisualStyleBackColor = false;
			   this->sendBookToLoanScreenBtn->Click += gcnew System::EventHandler(this, &Books::sendBookToLoanScreenBtn_Click);
			   // 
			   // AuthorLabel
			   // 
			   this->AuthorLabel->AccessibleName = L"AuthorLabel";
			   this->AuthorLabel->AutoSize = true;
			   this->AuthorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->AuthorLabel->Location = System::Drawing::Point(35, 103);
			   this->AuthorLabel->Name = L"AuthorLabel";
			   this->AuthorLabel->Size = System::Drawing::Size(69, 22);
			   this->AuthorLabel->TabIndex = 20;
			   this->AuthorLabel->Text = L"Author";
			   // 
			   // AuthorPanel
			   // 
			   this->AuthorPanel->BackColor = System::Drawing::SystemColors::Window;
			   this->AuthorPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->AuthorPanel->Controls->Add(this->AuthorText);
			   this->AuthorPanel->Location = System::Drawing::Point(25, 137);
			   this->AuthorPanel->Name = L"AuthorPanel";
			   this->AuthorPanel->Size = System::Drawing::Size(429, 45);
			   this->AuthorPanel->TabIndex = 21;
			   // 
			   // AuthorText
			   // 
			   this->AuthorText->AccessibleName = L"AuthorText";
			   this->AuthorText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->AuthorText->Location = System::Drawing::Point(16, 5);
			   this->AuthorText->Multiline = true;
			   this->AuthorText->Name = L"AuthorText";
			   this->AuthorText->Size = System::Drawing::Size(394, 32);
			   this->AuthorText->TabIndex = 0;
			   // 
			   // DescriptionLabel
			   // 
			   this->DescriptionLabel->AccessibleName = L"DescriptionLabel";
			   this->DescriptionLabel->AutoSize = true;
			   this->DescriptionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->DescriptionLabel->Location = System::Drawing::Point(35, 193);
			   this->DescriptionLabel->Name = L"DescriptionLabel";
			   this->DescriptionLabel->Size = System::Drawing::Size(111, 22);
			   this->DescriptionLabel->TabIndex = 18;
			   this->DescriptionLabel->Text = L"Description";
			   // 
			   // DescreptionPanel
			   // 
			   this->DescreptionPanel->AccessibleName = L"DepartmentPanel";
			   this->DescreptionPanel->BackColor = System::Drawing::SystemColors::Window;
			   this->DescreptionPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->DescreptionPanel->Controls->Add(this->DescreptionText);
			   this->DescreptionPanel->Location = System::Drawing::Point(25, 227);
			   this->DescreptionPanel->Name = L"DescreptionPanel";
			   this->DescreptionPanel->Size = System::Drawing::Size(429, 45);
			   this->DescreptionPanel->TabIndex = 19;
			   // 
			   // DescreptionText
			   // 
			   this->DescreptionText->AccessibleName = L"DescreptionText";
			   this->DescreptionText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->DescreptionText->Location = System::Drawing::Point(12, 6);
			   this->DescreptionText->Multiline = true;
			   this->DescreptionText->Name = L"DescreptionText";
			   this->DescreptionText->Size = System::Drawing::Size(394, 32);
			   this->DescreptionText->TabIndex = 0;
			   // 
			   // BookNamePanel
			   // 
			   this->BookNamePanel->BackColor = System::Drawing::SystemColors::Window;
			   this->BookNamePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->BookNamePanel->Controls->Add(this->BookNameText);
			   this->BookNamePanel->Location = System::Drawing::Point(25, 50);
			   this->BookNamePanel->Name = L"BookNamePanel";
			   this->BookNamePanel->Size = System::Drawing::Size(429, 45);
			   this->BookNamePanel->TabIndex = 17;
			   // 
			   // BookNameText
			   // 
			   this->BookNameText->AccessibleName = L"BookNameText";
			   this->BookNameText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->BookNameText->Location = System::Drawing::Point(15, 5);
			   this->BookNameText->Multiline = true;
			   this->BookNameText->Name = L"BookNameText";
			   this->BookNameText->Size = System::Drawing::Size(394, 32);
			   this->BookNameText->TabIndex = 0;
			   // 
			   // BookNameLabel
			   // 
			   this->BookNameLabel->AccessibleName = L"BookNameLabel";
			   this->BookNameLabel->AutoSize = true;
			   this->BookNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BookNameLabel->Location = System::Drawing::Point(35, 16);
			   this->BookNameLabel->Name = L"BookNameLabel";
			   this->BookNameLabel->Size = System::Drawing::Size(112, 22);
			   this->BookNameLabel->TabIndex = 16;
			   this->BookNameLabel->Text = L"Book Name";
			   // 
			   // StudentsControlBtns
			   // 
			   this->StudentsControlBtns->AccessibleName = L"StudentsControlBtns";
			   this->StudentsControlBtns->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->StudentsControlBtns->Controls->Add(this->AddBookBtn);
			   this->StudentsControlBtns->Controls->Add(this->EditBookBtn);
			   this->StudentsControlBtns->Controls->Add(this->DeleteBookBtn);
			   this->StudentsControlBtns->Dock = System::Windows::Forms::DockStyle::Bottom;
			   this->StudentsControlBtns->Location = System::Drawing::Point(0, 468);
			   this->StudentsControlBtns->Name = L"StudentsControlBtns";
			   this->StudentsControlBtns->Size = System::Drawing::Size(468, 72);
			   this->StudentsControlBtns->TabIndex = 2;
			   // 
			   // AddBookBtn
			   // 
			   this->AddBookBtn->AccessibleName = L"AddBookBtn";
			   this->AddBookBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				   static_cast<System::Int32>(static_cast<System::Byte>(224)));
			   this->AddBookBtn->FlatAppearance->BorderSize = 0;
			   this->AddBookBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->AddBookBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->AddBookBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->AddBookBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddBookBtn.Image")));
			   this->AddBookBtn->Location = System::Drawing::Point(5, 5);
			   this->AddBookBtn->Margin = System::Windows::Forms::Padding(5);
			   this->AddBookBtn->Name = L"AddBookBtn";
			   this->AddBookBtn->Size = System::Drawing::Size(143, 56);
			   this->AddBookBtn->TabIndex = 0;
			   this->AddBookBtn->Text = L"Add";
			   this->AddBookBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			   this->AddBookBtn->UseVisualStyleBackColor = false;
			   this->AddBookBtn->Click += gcnew System::EventHandler(this, &Books::AddBookBtn_Click);
			   // 
			   // EditBookBtn
			   // 
			   this->EditBookBtn->AccessibleName = L"EditBookBtn";
			   this->EditBookBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				   static_cast<System::Int32>(static_cast<System::Byte>(224)));
			   this->EditBookBtn->FlatAppearance->BorderSize = 0;
			   this->EditBookBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->EditBookBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->EditBookBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->EditBookBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"EditBookBtn.Image")));
			   this->EditBookBtn->Location = System::Drawing::Point(158, 5);
			   this->EditBookBtn->Margin = System::Windows::Forms::Padding(5);
			   this->EditBookBtn->Name = L"EditBookBtn";
			   this->EditBookBtn->Size = System::Drawing::Size(143, 56);
			   this->EditBookBtn->TabIndex = 0;
			   this->EditBookBtn->Text = L"Edit";
			   this->EditBookBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			   this->EditBookBtn->UseVisualStyleBackColor = false;
			   this->EditBookBtn->Click += gcnew System::EventHandler(this, &Books::EditBookBtn_Click);
			   // 
			   // DeleteBookBtn
			   // 
			   this->DeleteBookBtn->AccessibleName = L"DeleteBookBtn";
			   this->DeleteBookBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				   static_cast<System::Int32>(static_cast<System::Byte>(224)));
			   this->DeleteBookBtn->FlatAppearance->BorderSize = 0;
			   this->DeleteBookBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			   this->DeleteBookBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->DeleteBookBtn->ForeColor = System::Drawing::Color::Red;
			   this->DeleteBookBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeleteBookBtn.Image")));
			   this->DeleteBookBtn->Location = System::Drawing::Point(311, 5);
			   this->DeleteBookBtn->Margin = System::Windows::Forms::Padding(5);
			   this->DeleteBookBtn->Name = L"DeleteBookBtn";
			   this->DeleteBookBtn->Size = System::Drawing::Size(143, 56);
			   this->DeleteBookBtn->TabIndex = 0;
			   this->DeleteBookBtn->Text = L"Delete";
			   this->DeleteBookBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			   this->DeleteBookBtn->UseVisualStyleBackColor = false;
			   this->DeleteBookBtn->Click += gcnew System::EventHandler(this, &Books::DeleteBookBtn_Click);
			   // 
			   // BooksHeaderPanel
			   // 
			   this->BooksHeaderPanel->AccessibleName = L"BooksHeaderPanel";
			   this->BooksHeaderPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			   this->BooksHeaderPanel->Controls->Add(this->BooksHeaderFormLabel);
			   this->BooksHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			   this->BooksHeaderPanel->Location = System::Drawing::Point(0, 0);
			   this->BooksHeaderPanel->Name = L"BooksHeaderPanel";
			   this->BooksHeaderPanel->Size = System::Drawing::Size(468, 80);
			   this->BooksHeaderPanel->TabIndex = 1;
			   // 
			   // BooksHeaderFormLabel
			   // 
			   this->BooksHeaderFormLabel->AccessibleName = L"BooksHeaderFormLabel";
			   this->BooksHeaderFormLabel->AutoSize = true;
			   this->BooksHeaderFormLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->BooksHeaderFormLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)),
				   static_cast<System::Int32>(static_cast<System::Byte>(95)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
			   this->BooksHeaderFormLabel->Location = System::Drawing::Point(106, 17);
			   this->BooksHeaderFormLabel->Name = L"BooksHeaderFormLabel";
			   this->BooksHeaderFormLabel->Size = System::Drawing::Size(217, 41);
			   this->BooksHeaderFormLabel->TabIndex = 1;
			   this->BooksHeaderFormLabel->Text = L"Books Control";
			   // 
			   // Books
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1317, 653);
			   this->Controls->Add(this->BContainer);
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Name = L"Books";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Books";
			   this->BContainer->ResumeLayout(false);
			   this->panel3->ResumeLayout(false);
			   this->panel3->PerformLayout();
			   this->SuggestTabelPanel->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BooksTable))->EndInit();
			   this->BooksTableHeaderPanel->ResumeLayout(false);
			   this->BooksTableHeaderPanel->PerformLayout();
			   this->SearchPanel->ResumeLayout(false);
			   this->SearchPanel->PerformLayout();
			   this->SuggestFromContainer->ResumeLayout(false);
			   this->StudentsForm->ResumeLayout(false);
			   this->StudentsForm->PerformLayout();
			   this->AuthorPanel->ResumeLayout(false);
			   this->AuthorPanel->PerformLayout();
			   this->DescreptionPanel->ResumeLayout(false);
			   this->DescreptionPanel->PerformLayout();
			   this->BookNamePanel->ResumeLayout(false);
			   this->BookNamePanel->PerformLayout();
			   this->StudentsControlBtns->ResumeLayout(false);
			   this->BooksHeaderPanel->ResumeLayout(false);
			   this->BooksHeaderPanel->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void miniBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->WindowState == System::Windows::Forms::FormWindowState::Normal) {
		this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
	}
	else {
		this->WindowState = System::Windows::Forms::FormWindowState::Normal;

	}
}

private: System::Void sendBookToLoanScreenBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (BooksTable->SelectedRows->Count == 0) {
		MessageBox::Show("Please select a book to send to Loan Screen.");
		return;
	}

	// Get selected book details
	auto selectedRow = BooksTable->SelectedRows[0];
	String^ bookId = selectedRow->Cells["Id"]->Value->ToString();
	String^ bookName = selectedRow->Cells["BookName"]->Value->ToString();
	String^ author = selectedRow->Cells["Author"]->Value != nullptr ? selectedRow->Cells["Author"]->Value->ToString() : "";

	// Show or bring Loan screen
	if (loanForm == nullptr || loanForm->IsDisposed) {
		loanForm = gcnew Loan(currentUser);
		loanForm->Show();
	}
	else {
		loanForm->BringToFront();
	}

	// Send the book
	loanForm->SelectBookFromExternal(bookId, bookName, author);
}

};
}

