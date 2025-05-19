#pragma once
#include "../Controllers/StudentController.h"
#include "../Models/userModel.h"
#include "../HelperMethods/UIHelper.h"

namespace LaibraryProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Student
	/// </summary>
	public ref class Student : public System::Windows::Forms::Form
	{
	public:
		Student(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		Student::Student(UserModel^ user);
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Student()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: virtual void WndProc(System::Windows::Forms::Message% m) override {
		const int WM_NCHITTEST = 0x84;
		const int HTCLIENT = 1;
		const int HTCAPTION = 2;

		Form::WndProc(m);

		if (m.Msg == WM_NCHITTEST && (int)m.Result == HTCLIENT) {
			m.Result = (System::IntPtr)HTCAPTION;
		}
	}

		System::Drawing::Font^ TABLE_CELLS_FONT = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
	private: System::Windows::Forms::FlowLayoutPanel^ BContainer;
	protected:
	private: System::Windows::Forms::Panel^ SuggestTabelPanel;
	private: System::Windows::Forms::DataGridView^ StudentsTable;





	private: System::Windows::Forms::Panel^ StudentsTableHeaderPanel;

	private: System::Windows::Forms::Label^ StudentsTableHeader;

	private: System::Windows::Forms::Panel^ SuggestFromContainer;
	private: System::Windows::Forms::Panel^ StudentsForm;

	private: System::Windows::Forms::Label^ StudentIdLabel;
	private: System::Windows::Forms::Panel^ StudentIdPanel;
	private: System::Windows::Forms::TextBox^ StidentIdText;
	private: System::Windows::Forms::Label^ DepartmentLabel;

	private: System::Windows::Forms::Panel^ DepartmentPanel;
	private: System::Windows::Forms::TextBox^ DepartmentText;


	private: System::Windows::Forms::Panel^ StudentNamePanel;
	private: System::Windows::Forms::TextBox^ StudentNameText;
	private: System::Windows::Forms::Label^ StudentNameLabel;
	private: System::Windows::Forms::FlowLayoutPanel^ StudentsControlBtns;
	private: System::Windows::Forms::Button^ DeleteStudentBtn;
	private: System::Windows::Forms::Button^ AddStudentBtn;
	private: System::Windows::Forms::Button^ EditStudentBtn;




	private: System::Windows::Forms::Panel^ StudentsHeaderPanel;
	private: System::Windows::Forms::Label^ StudentsHeaderFormLabel;


	private: System::Windows::Forms::Label^ EmailLabel;
	private: System::Windows::Forms::Panel^ EmailPanel;
	private: System::Windows::Forms::TextBox^ EmailText;
	private: System::Windows::Forms::Panel^ SearchPanel;
	private: System::Windows::Forms::TextBox^ SearchText;







		   //DATABASE
		   UserModel^ currentUser;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NameCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ SeatnumberCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DepartmentCol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ EmailCol;

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ Logo;
	private: System::Windows::Forms::Button^ closeBtn;
	private: System::Windows::Forms::Button^ miniBtn;
	private: System::Windows::Forms::Button^ excelBtn;

	private: System::Windows::Forms::Button^ printBtn;












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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Student::typeid));
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
			this->SuggestTabelPanel = (gcnew System::Windows::Forms::Panel());
			this->StudentsTable = (gcnew System::Windows::Forms::DataGridView());
			this->IdCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NameCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SeatnumberCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->DepartmentCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EmailCol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StudentsTableHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->excelBtn = (gcnew System::Windows::Forms::Button());
			this->printBtn = (gcnew System::Windows::Forms::Button());
			this->SearchPanel = (gcnew System::Windows::Forms::Panel());
			this->SearchText = (gcnew System::Windows::Forms::TextBox());
			this->StudentsTableHeader = (gcnew System::Windows::Forms::Label());
			this->SuggestFromContainer = (gcnew System::Windows::Forms::Panel());
			this->StudentsForm = (gcnew System::Windows::Forms::Panel());
			this->StudentIdLabel = (gcnew System::Windows::Forms::Label());
			this->StudentIdPanel = (gcnew System::Windows::Forms::Panel());
			this->StidentIdText = (gcnew System::Windows::Forms::TextBox());
			this->EmailLabel = (gcnew System::Windows::Forms::Label());
			this->DepartmentLabel = (gcnew System::Windows::Forms::Label());
			this->EmailPanel = (gcnew System::Windows::Forms::Panel());
			this->EmailText = (gcnew System::Windows::Forms::TextBox());
			this->DepartmentPanel = (gcnew System::Windows::Forms::Panel());
			this->DepartmentText = (gcnew System::Windows::Forms::TextBox());
			this->StudentNamePanel = (gcnew System::Windows::Forms::Panel());
			this->StudentNameText = (gcnew System::Windows::Forms::TextBox());
			this->StudentNameLabel = (gcnew System::Windows::Forms::Label());
			this->StudentsControlBtns = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->AddStudentBtn = (gcnew System::Windows::Forms::Button());
			this->EditStudentBtn = (gcnew System::Windows::Forms::Button());
			this->DeleteStudentBtn = (gcnew System::Windows::Forms::Button());
			this->StudentsHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->StudentsHeaderFormLabel = (gcnew System::Windows::Forms::Label());
			this->BContainer->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuggestTabelPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StudentsTable))->BeginInit();
			this->StudentsTableHeaderPanel->SuspendLayout();
			this->SearchPanel->SuspendLayout();
			this->SuggestFromContainer->SuspendLayout();
			this->StudentsForm->SuspendLayout();
			this->StudentIdPanel->SuspendLayout();
			this->EmailPanel->SuspendLayout();
			this->DepartmentPanel->SuspendLayout();
			this->StudentNamePanel->SuspendLayout();
			this->StudentsControlBtns->SuspendLayout();
			this->StudentsHeaderPanel->SuspendLayout();
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
			this->BContainer->Size = System::Drawing::Size(1253, 664);
			this->BContainer->TabIndex = 19;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->Logo);
			this->panel3->Controls->Add(this->closeBtn);
			this->panel3->Controls->Add(this->miniBtn);
			this->panel3->Location = System::Drawing::Point(3, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1250, 89);
			this->panel3->TabIndex = 25;
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
			this->closeBtn->Location = System::Drawing::Point(1151, 7);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(87, 74);
			this->closeBtn->TabIndex = 23;
			this->closeBtn->UseVisualStyleBackColor = true;
			this->closeBtn->Click += gcnew System::EventHandler(this, &Student::closeBtn_Click);
			// 
			// miniBtn
			// 
			this->miniBtn->AccessibleName = L"miniBtn";
			this->miniBtn->FlatAppearance->BorderSize = 0;
			this->miniBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->miniBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"miniBtn.Image")));
			this->miniBtn->Location = System::Drawing::Point(1056, 26);
			this->miniBtn->Name = L"miniBtn";
			this->miniBtn->Size = System::Drawing::Size(75, 36);
			this->miniBtn->TabIndex = 22;
			this->miniBtn->UseVisualStyleBackColor = true;
			this->miniBtn->Click += gcnew System::EventHandler(this, &Student::miniBtn_Click);
			// 
			// SuggestTabelPanel
			// 
			this->SuggestTabelPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SuggestTabelPanel->Controls->Add(this->StudentsTable);
			this->SuggestTabelPanel->Controls->Add(this->StudentsTableHeaderPanel);
			this->SuggestTabelPanel->Location = System::Drawing::Point(5, 100);
			this->SuggestTabelPanel->Margin = System::Windows::Forms::Padding(5, 5, 3, 5);
			this->SuggestTabelPanel->Name = L"SuggestTabelPanel";
			this->SuggestTabelPanel->Size = System::Drawing::Size(786, 543);
			this->SuggestTabelPanel->TabIndex = 18;
			// 
			// StudentsTable
			// 
			this->StudentsTable->AccessibleName = L"StudentsTable";
			this->StudentsTable->AllowUserToAddRows = false;
			this->StudentsTable->AllowUserToResizeRows = false;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)));
			this->StudentsTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->StudentsTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->StudentsTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->StudentsTable->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->StudentsTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->StudentsTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->StudentsTable->ColumnHeadersHeight = 50;
			this->StudentsTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->StudentsTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->IdCol,
					this->NameCol, this->SeatnumberCol, this->DepartmentCol, this->EmailCol
			});
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->StudentsTable->DefaultCellStyle = dataGridViewCellStyle4;
			this->StudentsTable->Dock = System::Windows::Forms::DockStyle::Fill;
			this->StudentsTable->EnableHeadersVisualStyles = false;
			this->StudentsTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->StudentsTable->Location = System::Drawing::Point(0, 81);
			this->StudentsTable->Name = L"StudentsTable";
			this->StudentsTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->StudentsTable->RowHeadersVisible = false;
			this->StudentsTable->RowHeadersWidth = 4;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->StudentsTable->RowsDefaultCellStyle = dataGridViewCellStyle5;
			this->StudentsTable->RowTemplate->DefaultCellStyle->Padding = System::Windows::Forms::Padding(5);
			this->StudentsTable->RowTemplate->Height = 40;
			this->StudentsTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->StudentsTable->Size = System::Drawing::Size(784, 460);
			this->StudentsTable->TabIndex = 19;
			this->StudentsTable->CellMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &Student::StudentsTable_CellMouseClick);
			// 
			// IdCol
			// 
			this->IdCol->DataPropertyName = L"IdCol";
			this->IdCol->FillWeight = 15;
			this->IdCol->HeaderText = L"ID";
			this->IdCol->MaxInputLength = 20;
			this->IdCol->MinimumWidth = 6;
			this->IdCol->Name = L"IdCol";
			this->IdCol->ReadOnly = true;
			// 
			// NameCol
			// 
			this->NameCol->DataPropertyName = L"NameCol";
			this->NameCol->FillWeight = 25;
			this->NameCol->HeaderText = L"Student Name";
			this->NameCol->MaxInputLength = 40;
			this->NameCol->MinimumWidth = 6;
			this->NameCol->Name = L"NameCol";
			this->NameCol->ReadOnly = true;
			// 
			// SeatnumberCol
			// 
			this->SeatnumberCol->DataPropertyName = L"SeatnumberCol";
			this->SeatnumberCol->FillWeight = 30;
			this->SeatnumberCol->HeaderText = L"Seat Number";
			this->SeatnumberCol->MaxInputLength = 10;
			this->SeatnumberCol->MinimumWidth = 6;
			this->SeatnumberCol->Name = L"SeatnumberCol";
			this->SeatnumberCol->ReadOnly = true;
			// 
			// DepartmentCol
			// 
			this->DepartmentCol->DataPropertyName = L"DepartmentCol";
			this->DepartmentCol->FillWeight = 30;
			this->DepartmentCol->HeaderText = L"Department";
			this->DepartmentCol->MinimumWidth = 6;
			this->DepartmentCol->Name = L"DepartmentCol";
			// 
			// EmailCol
			// 
			this->EmailCol->DataPropertyName = L"EmailCol";
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->EmailCol->DefaultCellStyle = dataGridViewCellStyle3;
			this->EmailCol->FillWeight = 30;
			this->EmailCol->HeaderText = L"Email";
			this->EmailCol->MaxInputLength = 1000;
			this->EmailCol->MinimumWidth = 6;
			this->EmailCol->Name = L"EmailCol";
			this->EmailCol->ReadOnly = true;
			// 
			// StudentsTableHeaderPanel
			// 
			this->StudentsTableHeaderPanel->AccessibleName = L"StudentsTableHeaderPanel";
			this->StudentsTableHeaderPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->StudentsTableHeaderPanel->Controls->Add(this->excelBtn);
			this->StudentsTableHeaderPanel->Controls->Add(this->printBtn);
			this->StudentsTableHeaderPanel->Controls->Add(this->SearchPanel);
			this->StudentsTableHeaderPanel->Controls->Add(this->StudentsTableHeader);
			this->StudentsTableHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->StudentsTableHeaderPanel->Location = System::Drawing::Point(0, 0);
			this->StudentsTableHeaderPanel->Name = L"StudentsTableHeaderPanel";
			this->StudentsTableHeaderPanel->Size = System::Drawing::Size(784, 81);
			this->StudentsTableHeaderPanel->TabIndex = 0;
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
			this->excelBtn->Location = System::Drawing::Point(348, 15);
			this->excelBtn->Name = L"excelBtn";
			this->excelBtn->Size = System::Drawing::Size(75, 50);
			this->excelBtn->TabIndex = 22;
			this->excelBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->excelBtn->UseVisualStyleBackColor = false;
			this->excelBtn->Click += gcnew System::EventHandler(this, &Student::excelBtn_Click);
			// 
			// printBtn
			// 
			this->printBtn->AccessibleName = L"printBtn";
			this->printBtn->BackColor = System::Drawing::SystemColors::Info;
			this->printBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->printBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"printBtn.Image")));
			this->printBtn->Location = System::Drawing::Point(254, 15);
			this->printBtn->Name = L"printBtn";
			this->printBtn->Size = System::Drawing::Size(75, 50);
			this->printBtn->TabIndex = 23;
			this->printBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->printBtn->UseVisualStyleBackColor = false;
			this->printBtn->Click += gcnew System::EventHandler(this, &Student::printBtn_Click);
			// 
			// SearchPanel
			// 
			this->SearchPanel->AccessibleName = L"SearchPanel";
			this->SearchPanel->BackColor = System::Drawing::SystemColors::Window;
			this->SearchPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SearchPanel->Controls->Add(this->SearchText);
			this->SearchPanel->Location = System::Drawing::Point(460, 20);
			this->SearchPanel->Name = L"SearchPanel";
			this->SearchPanel->Size = System::Drawing::Size(317, 45);
			this->SearchPanel->TabIndex = 20;
			// 
			// SearchText
			// 
			this->SearchText->AccessibleName = L"SearchText";
			this->SearchText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SearchText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SearchText->Location = System::Drawing::Point(17, 7);
			this->SearchText->Multiline = true;
			this->SearchText->Name = L"SearchText";
			this->SearchText->Size = System::Drawing::Size(284, 32);
			this->SearchText->TabIndex = 0;
			this->SearchText->TextChanged += gcnew System::EventHandler(this, &Student::SearchText_TextChanged);
			// 
			// StudentsTableHeader
			// 
			this->StudentsTableHeader->AccessibleName = L"StudentsTableHeader";
			this->StudentsTableHeader->AutoSize = true;
			this->StudentsTableHeader->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StudentsTableHeader->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->StudentsTableHeader->Location = System::Drawing::Point(14, 18);
			this->StudentsTableHeader->Name = L"StudentsTableHeader";
			this->StudentsTableHeader->Size = System::Drawing::Size(225, 41);
			this->StudentsTableHeader->TabIndex = 1;
			this->StudentsTableHeader->Text = L"Students Table";
			// 
			// SuggestFromContainer
			// 
			this->SuggestFromContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SuggestFromContainer->Controls->Add(this->StudentsForm);
			this->SuggestFromContainer->Controls->Add(this->StudentsControlBtns);
			this->SuggestFromContainer->Controls->Add(this->StudentsHeaderPanel);
			this->SuggestFromContainer->Location = System::Drawing::Point(800, 101);
			this->SuggestFromContainer->Margin = System::Windows::Forms::Padding(6);
			this->SuggestFromContainer->Name = L"SuggestFromContainer";
			this->SuggestFromContainer->Size = System::Drawing::Size(438, 542);
			this->SuggestFromContainer->TabIndex = 16;
			// 
			// StudentsForm
			// 
			this->StudentsForm->AccessibleName = L"StudentsForm";
			this->StudentsForm->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->StudentsForm->Controls->Add(this->StudentIdLabel);
			this->StudentsForm->Controls->Add(this->StudentIdPanel);
			this->StudentsForm->Controls->Add(this->EmailLabel);
			this->StudentsForm->Controls->Add(this->DepartmentLabel);
			this->StudentsForm->Controls->Add(this->EmailPanel);
			this->StudentsForm->Controls->Add(this->DepartmentPanel);
			this->StudentsForm->Controls->Add(this->StudentNamePanel);
			this->StudentsForm->Controls->Add(this->StudentNameLabel);
			this->StudentsForm->Dock = System::Windows::Forms::DockStyle::Fill;
			this->StudentsForm->Location = System::Drawing::Point(0, 80);
			this->StudentsForm->Name = L"StudentsForm";
			this->StudentsForm->Size = System::Drawing::Size(436, 388);
			this->StudentsForm->TabIndex = 3;
			// 
			// StudentIdLabel
			// 
			this->StudentIdLabel->AccessibleName = L"StudentIdLabel";
			this->StudentIdLabel->AutoSize = true;
			this->StudentIdLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StudentIdLabel->Location = System::Drawing::Point(35, 103);
			this->StudentIdLabel->Name = L"StudentIdLabel";
			this->StudentIdLabel->Size = System::Drawing::Size(126, 22);
			this->StudentIdLabel->TabIndex = 20;
			this->StudentIdLabel->Text = L"Seat Number";
			// 
			// StudentIdPanel
			// 
			this->StudentIdPanel->BackColor = System::Drawing::SystemColors::Window;
			this->StudentIdPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->StudentIdPanel->Controls->Add(this->StidentIdText);
			this->StudentIdPanel->Location = System::Drawing::Point(25, 137);
			this->StudentIdPanel->Name = L"StudentIdPanel";
			this->StudentIdPanel->Size = System::Drawing::Size(393, 45);
			this->StudentIdPanel->TabIndex = 21;
			// 
			// StidentIdText
			// 
			this->StidentIdText->AccessibleName = L"StudentNameText";
			this->StidentIdText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->StidentIdText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StidentIdText->Location = System::Drawing::Point(14, 7);
			this->StidentIdText->Multiline = true;
			this->StidentIdText->Name = L"StidentIdText";
			this->StidentIdText->Size = System::Drawing::Size(365, 32);
			this->StidentIdText->TabIndex = 0;
			// 
			// EmailLabel
			// 
			this->EmailLabel->AccessibleName = L"EmailLabel";
			this->EmailLabel->AutoSize = true;
			this->EmailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EmailLabel->Location = System::Drawing::Point(35, 278);
			this->EmailLabel->Name = L"EmailLabel";
			this->EmailLabel->Size = System::Drawing::Size(59, 22);
			this->EmailLabel->TabIndex = 18;
			this->EmailLabel->Text = L"Email";
			// 
			// DepartmentLabel
			// 
			this->DepartmentLabel->AccessibleName = L"DepartmentLabel";
			this->DepartmentLabel->AutoSize = true;
			this->DepartmentLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DepartmentLabel->Location = System::Drawing::Point(35, 193);
			this->DepartmentLabel->Name = L"DepartmentLabel";
			this->DepartmentLabel->Size = System::Drawing::Size(113, 22);
			this->DepartmentLabel->TabIndex = 18;
			this->DepartmentLabel->Text = L"Department";
			// 
			// EmailPanel
			// 
			this->EmailPanel->AccessibleName = L"EmailPanel";
			this->EmailPanel->BackColor = System::Drawing::SystemColors::Window;
			this->EmailPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->EmailPanel->Controls->Add(this->EmailText);
			this->EmailPanel->Location = System::Drawing::Point(25, 312);
			this->EmailPanel->Name = L"EmailPanel";
			this->EmailPanel->Size = System::Drawing::Size(393, 45);
			this->EmailPanel->TabIndex = 19;
			// 
			// EmailText
			// 
			this->EmailText->AccessibleName = L"EmailText";
			this->EmailText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->EmailText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EmailText->Location = System::Drawing::Point(14, 9);
			this->EmailText->Multiline = true;
			this->EmailText->Name = L"EmailText";
			this->EmailText->Size = System::Drawing::Size(365, 32);
			this->EmailText->TabIndex = 0;
			// 
			// DepartmentPanel
			// 
			this->DepartmentPanel->AccessibleName = L"DepartmentPanel";
			this->DepartmentPanel->BackColor = System::Drawing::SystemColors::Window;
			this->DepartmentPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->DepartmentPanel->Controls->Add(this->DepartmentText);
			this->DepartmentPanel->Location = System::Drawing::Point(25, 227);
			this->DepartmentPanel->Name = L"DepartmentPanel";
			this->DepartmentPanel->Size = System::Drawing::Size(393, 45);
			this->DepartmentPanel->TabIndex = 19;
			// 
			// DepartmentText
			// 
			this->DepartmentText->AccessibleName = L"DepartmentText";
			this->DepartmentText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->DepartmentText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DepartmentText->Location = System::Drawing::Point(14, 7);
			this->DepartmentText->Multiline = true;
			this->DepartmentText->Name = L"DepartmentText";
			this->DepartmentText->Size = System::Drawing::Size(365, 32);
			this->DepartmentText->TabIndex = 0;
			// 
			// StudentNamePanel
			// 
			this->StudentNamePanel->BackColor = System::Drawing::SystemColors::Window;
			this->StudentNamePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->StudentNamePanel->Controls->Add(this->StudentNameText);
			this->StudentNamePanel->Location = System::Drawing::Point(25, 50);
			this->StudentNamePanel->Name = L"StudentNamePanel";
			this->StudentNamePanel->Size = System::Drawing::Size(393, 45);
			this->StudentNamePanel->TabIndex = 17;
			// 
			// StudentNameText
			// 
			this->StudentNameText->AccessibleName = L"StudentNameText";
			this->StudentNameText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->StudentNameText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StudentNameText->Location = System::Drawing::Point(14, 8);
			this->StudentNameText->Multiline = true;
			this->StudentNameText->Name = L"StudentNameText";
			this->StudentNameText->Size = System::Drawing::Size(365, 32);
			this->StudentNameText->TabIndex = 0;
			// 
			// StudentNameLabel
			// 
			this->StudentNameLabel->AccessibleName = L"StudentNameLabel";
			this->StudentNameLabel->AutoSize = true;
			this->StudentNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StudentNameLabel->Location = System::Drawing::Point(35, 16);
			this->StudentNameLabel->Name = L"StudentNameLabel";
			this->StudentNameLabel->Size = System::Drawing::Size(136, 22);
			this->StudentNameLabel->TabIndex = 16;
			this->StudentNameLabel->Text = L"Student Name";
			// 
			// StudentsControlBtns
			// 
			this->StudentsControlBtns->AccessibleName = L"StudentsControlBtns";
			this->StudentsControlBtns->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->StudentsControlBtns->Controls->Add(this->AddStudentBtn);
			this->StudentsControlBtns->Controls->Add(this->EditStudentBtn);
			this->StudentsControlBtns->Controls->Add(this->DeleteStudentBtn);
			this->StudentsControlBtns->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->StudentsControlBtns->Location = System::Drawing::Point(0, 468);
			this->StudentsControlBtns->Name = L"StudentsControlBtns";
			this->StudentsControlBtns->Size = System::Drawing::Size(436, 72);
			this->StudentsControlBtns->TabIndex = 2;
			// 
			// AddStudentBtn
			// 
			this->AddStudentBtn->AccessibleName = L"AddStudentBtn";
			this->AddStudentBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->AddStudentBtn->FlatAppearance->BorderSize = 0;
			this->AddStudentBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AddStudentBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AddStudentBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			this->AddStudentBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddStudentBtn.Image")));
			this->AddStudentBtn->Location = System::Drawing::Point(5, 5);
			this->AddStudentBtn->Margin = System::Windows::Forms::Padding(5);
			this->AddStudentBtn->Name = L"AddStudentBtn";
			this->AddStudentBtn->Size = System::Drawing::Size(133, 56);
			this->AddStudentBtn->TabIndex = 0;
			this->AddStudentBtn->Text = L"Add";
			this->AddStudentBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->AddStudentBtn->UseVisualStyleBackColor = false;
			this->AddStudentBtn->Click += gcnew System::EventHandler(this, &Student::AddStudentBtn_Click);
			// 
			// EditStudentBtn
			// 
			this->EditStudentBtn->AccessibleName = L"EditStudentBtn";
			this->EditStudentBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->EditStudentBtn->FlatAppearance->BorderSize = 0;
			this->EditStudentBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->EditStudentBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditStudentBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			this->EditStudentBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"EditStudentBtn.Image")));
			this->EditStudentBtn->Location = System::Drawing::Point(148, 5);
			this->EditStudentBtn->Margin = System::Windows::Forms::Padding(5);
			this->EditStudentBtn->Name = L"EditStudentBtn";
			this->EditStudentBtn->Size = System::Drawing::Size(133, 56);
			this->EditStudentBtn->TabIndex = 0;
			this->EditStudentBtn->Text = L"Edit";
			this->EditStudentBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->EditStudentBtn->UseVisualStyleBackColor = false;
			this->EditStudentBtn->Click += gcnew System::EventHandler(this, &Student::EditStudentBtn_Click);
			// 
			// DeleteStudentBtn
			// 
			this->DeleteStudentBtn->AccessibleName = L"DeleteStudentBtn";
			this->DeleteStudentBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->DeleteStudentBtn->FlatAppearance->BorderSize = 0;
			this->DeleteStudentBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DeleteStudentBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DeleteStudentBtn->ForeColor = System::Drawing::Color::Red;
			this->DeleteStudentBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeleteStudentBtn.Image")));
			this->DeleteStudentBtn->Location = System::Drawing::Point(291, 5);
			this->DeleteStudentBtn->Margin = System::Windows::Forms::Padding(5);
			this->DeleteStudentBtn->Name = L"DeleteStudentBtn";
			this->DeleteStudentBtn->Size = System::Drawing::Size(133, 56);
			this->DeleteStudentBtn->TabIndex = 0;
			this->DeleteStudentBtn->Text = L"Delete";
			this->DeleteStudentBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->DeleteStudentBtn->UseVisualStyleBackColor = false;
			this->DeleteStudentBtn->Click += gcnew System::EventHandler(this, &Student::DeleteStudentBtn_Click);
			// 
			// StudentsHeaderPanel
			// 
			this->StudentsHeaderPanel->AccessibleName = L"StudentsHeaderPanel";
			this->StudentsHeaderPanel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->StudentsHeaderPanel->Controls->Add(this->StudentsHeaderFormLabel);
			this->StudentsHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->StudentsHeaderPanel->Location = System::Drawing::Point(0, 0);
			this->StudentsHeaderPanel->Name = L"StudentsHeaderPanel";
			this->StudentsHeaderPanel->Size = System::Drawing::Size(436, 80);
			this->StudentsHeaderPanel->TabIndex = 1;
			// 
			// StudentsHeaderFormLabel
			// 
			this->StudentsHeaderFormLabel->AccessibleName = L"StudentsHeaderFormLabel";
			this->StudentsHeaderFormLabel->AutoSize = true;
			this->StudentsHeaderFormLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StudentsHeaderFormLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->StudentsHeaderFormLabel->Location = System::Drawing::Point(40, 17);
			this->StudentsHeaderFormLabel->Name = L"StudentsHeaderFormLabel";
			this->StudentsHeaderFormLabel->Size = System::Drawing::Size(256, 41);
			this->StudentsHeaderFormLabel->TabIndex = 1;
			this->StudentsHeaderFormLabel->Text = L"Students Control";
			// 
			// Student
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1253, 664);
			this->ControlBox = false;
			this->Controls->Add(this->BContainer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Student";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Student";
			this->BContainer->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->SuggestTabelPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->StudentsTable))->EndInit();
			this->StudentsTableHeaderPanel->ResumeLayout(false);
			this->StudentsTableHeaderPanel->PerformLayout();
			this->SearchPanel->ResumeLayout(false);
			this->SearchPanel->PerformLayout();
			this->SuggestFromContainer->ResumeLayout(false);
			this->StudentsForm->ResumeLayout(false);
			this->StudentsForm->PerformLayout();
			this->StudentIdPanel->ResumeLayout(false);
			this->StudentIdPanel->PerformLayout();
			this->EmailPanel->ResumeLayout(false);
			this->EmailPanel->PerformLayout();
			this->DepartmentPanel->ResumeLayout(false);
			this->DepartmentPanel->PerformLayout();
			this->StudentNamePanel->ResumeLayout(false);
			this->StudentNamePanel->PerformLayout();
			this->StudentsControlBtns->ResumeLayout(false);
			this->StudentsHeaderPanel->ResumeLayout(false);
			this->StudentsHeaderPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void AddStudentBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void EditStudentBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void DeleteStudentBtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: void LoadStudentsForUser();

		   //Ui
		   void ClearForm();

	//private: System::Void StudentsTable_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void StudentsTable_CellMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e);
	private: System::Void PrintTablePtn_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void SearchText_TextChanged(System::Object^ sender, System::EventArgs^ e);
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


private: System::Void printBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::PrintTable(StudentsTable);
}
private: System::Void excelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	UIHelper::ExportTableToCsv(StudentsTable);
}
};
}
