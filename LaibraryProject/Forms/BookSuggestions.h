#pragma once
#include "../HelperMethods/UIHelper.h"
#include "../Models/userModel.h"
#include "../Controllers/StudentController.h"
#include "../Controllers/BookSuggestionController.h"
#include "../Models/BookSuggestionModel.h"
namespace LaibraryProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for BookSuggestions
	/// </summary>
	public ref class BookSuggestions : public System::Windows::Forms::Form
	{
	public:
		BookSuggestions(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		UserModel^ currentUser;

		BookSuggestions(UserModel^ user)
		{
			if (user == nullptr) {
				throw gcnew ArgumentNullException("User cannot be null");
			}
			currentUser = user;
			InitializeComponent();
			RefreshSuggestionsTable();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~BookSuggestions()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:













	private: System::Windows::Forms::Panel^ SuggestFromContainer;
	private: System::Windows::Forms::Button^ DeleteSuggestBtn;
	private: System::Windows::Forms::Button^ EditSuggestBtn;
	private: System::Windows::Forms::Button^ AddSuggestBtn;
	private: System::Windows::Forms::Panel^ SuggestHeaderPanel;
	private: System::Windows::Forms::Panel^ SuggestionsForm;




	private: System::Windows::Forms::Label^ SuggestLabel;
	private: System::Windows::Forms::Panel^ SuggestPanel;
	private: System::Windows::Forms::TextBox^ SuggestText;



	private: System::Windows::Forms::FlowLayoutPanel^ SuggestionsControlBtns;
	private: System::Windows::Forms::Label^ HomeHeaderLabel;





	private: System::Windows::Forms::FlowLayoutPanel^ BContainer;
	private: System::Windows::Forms::Panel^ SuggestTabelPanel;
	private: System::Windows::Forms::DataGridView^ SuggestionsTable;




	private: System::Windows::Forms::Panel^ SuggestTableHeaderPanel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ StudentName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ StudentSeatnumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Suggestion;
	private: System::Windows::Forms::Label^ StudentIdLabel;
	private: System::Windows::Forms::Panel^ StudentIdPanel;
	private: System::Windows::Forms::TextBox^ StidentIdText;
	private: System::Windows::Forms::Panel^ SearchPanel;
	private: System::Windows::Forms::Panel^ SearchHeaderPanel;
	private: System::Windows::Forms::Label^ SearchHeaderLabel;
	private: System::Windows::Forms::Panel^ SearchSuggestionsPanel;
	private: System::Windows::Forms::TextBox^ SearchSuggestionsText;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ SearchForStudentsText;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ListBox^ resultListStudents;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BookSuggestions::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->SuggestFromContainer = (gcnew System::Windows::Forms::Panel());
			this->SuggestionsForm = (gcnew System::Windows::Forms::Panel());
			this->StudentIdLabel = (gcnew System::Windows::Forms::Label());
			this->StudentIdPanel = (gcnew System::Windows::Forms::Panel());
			this->StidentIdText = (gcnew System::Windows::Forms::TextBox());
			this->SuggestLabel = (gcnew System::Windows::Forms::Label());
			this->SuggestPanel = (gcnew System::Windows::Forms::Panel());
			this->SuggestText = (gcnew System::Windows::Forms::TextBox());
			this->SuggestionsControlBtns = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->AddSuggestBtn = (gcnew System::Windows::Forms::Button());
			this->EditSuggestBtn = (gcnew System::Windows::Forms::Button());
			this->DeleteSuggestBtn = (gcnew System::Windows::Forms::Button());
			this->SuggestHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->HomeHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->BContainer = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->Logo = (gcnew System::Windows::Forms::Label());
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->miniBtn = (gcnew System::Windows::Forms::Button());
			this->SearchPanel = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->SearchForStudentsText = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->resultListStudents = (gcnew System::Windows::Forms::ListBox());
			this->SearchHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->SearchHeaderLabel = (gcnew System::Windows::Forms::Label());
			this->SuggestTabelPanel = (gcnew System::Windows::Forms::Panel());
			this->SuggestionsTable = (gcnew System::Windows::Forms::DataGridView());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StudentName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StudentSeatnumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Suggestion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->SuggestTableHeaderPanel = (gcnew System::Windows::Forms::Panel());
			this->excelBtn = (gcnew System::Windows::Forms::Button());
			this->printBtn = (gcnew System::Windows::Forms::Button());
			this->SearchSuggestionsPanel = (gcnew System::Windows::Forms::Panel());
			this->SearchSuggestionsText = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuggestFromContainer->SuspendLayout();
			this->SuggestionsForm->SuspendLayout();
			this->StudentIdPanel->SuspendLayout();
			this->SuggestPanel->SuspendLayout();
			this->SuggestionsControlBtns->SuspendLayout();
			this->SuggestHeaderPanel->SuspendLayout();
			this->BContainer->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SearchPanel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SearchHeaderPanel->SuspendLayout();
			this->SuggestTabelPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SuggestionsTable))->BeginInit();
			this->SuggestTableHeaderPanel->SuspendLayout();
			this->SearchSuggestionsPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// SuggestFromContainer
			// 
			this->SuggestFromContainer->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SuggestFromContainer->Controls->Add(this->SuggestionsForm);
			this->SuggestFromContainer->Controls->Add(this->SuggestionsControlBtns);
			this->SuggestFromContainer->Controls->Add(this->SuggestHeaderPanel);
			this->SuggestFromContainer->Location = System::Drawing::Point(444, 101);
			this->SuggestFromContainer->Margin = System::Windows::Forms::Padding(6);
			this->SuggestFromContainer->Name = L"SuggestFromContainer";
			this->SuggestFromContainer->Size = System::Drawing::Size(427, 425);
			this->SuggestFromContainer->TabIndex = 16;
			// 
			// SuggestionsForm
			// 
			this->SuggestionsForm->AccessibleName = L"SuggestionsForm";
			this->SuggestionsForm->Controls->Add(this->StudentIdLabel);
			this->SuggestionsForm->Controls->Add(this->StudentIdPanel);
			this->SuggestionsForm->Controls->Add(this->SuggestLabel);
			this->SuggestionsForm->Controls->Add(this->SuggestPanel);
			this->SuggestionsForm->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SuggestionsForm->Location = System::Drawing::Point(0, 77);
			this->SuggestionsForm->Name = L"SuggestionsForm";
			this->SuggestionsForm->Size = System::Drawing::Size(425, 277);
			this->SuggestionsForm->TabIndex = 3;
			// 
			// StudentIdLabel
			// 
			this->StudentIdLabel->AccessibleName = L"StudentIdLabel";
			this->StudentIdLabel->AutoSize = true;
			this->StudentIdLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StudentIdLabel->Location = System::Drawing::Point(35, 27);
			this->StudentIdLabel->Name = L"StudentIdLabel";
			this->StudentIdLabel->Size = System::Drawing::Size(104, 22);
			this->StudentIdLabel->TabIndex = 20;
			this->StudentIdLabel->Text = L"Student ID";
			// 
			// StudentIdPanel
			// 
			this->StudentIdPanel->BackColor = System::Drawing::SystemColors::Window;
			this->StudentIdPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->StudentIdPanel->Controls->Add(this->StidentIdText);
			this->StudentIdPanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StudentIdPanel->Location = System::Drawing::Point(25, 64);
			this->StudentIdPanel->Name = L"StudentIdPanel";
			this->StudentIdPanel->Size = System::Drawing::Size(374, 45);
			this->StudentIdPanel->TabIndex = 21;
			// 
			// StidentIdText
			// 
			this->StidentIdText->AccessibleName = L"StudentNameText";
			this->StidentIdText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->StidentIdText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->StidentIdText->Location = System::Drawing::Point(6, 7);
			this->StidentIdText->Multiline = true;
			this->StidentIdText->Name = L"StidentIdText";
			this->StidentIdText->Size = System::Drawing::Size(362, 32);
			this->StidentIdText->TabIndex = 0;
			// 
			// SuggestLabel
			// 
			this->SuggestLabel->AccessibleName = L"StudentNameLabel";
			this->SuggestLabel->AutoSize = true;
			this->SuggestLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SuggestLabel->Location = System::Drawing::Point(35, 123);
			this->SuggestLabel->Name = L"SuggestLabel";
			this->SuggestLabel->Size = System::Drawing::Size(110, 22);
			this->SuggestLabel->TabIndex = 18;
			this->SuggestLabel->Text = L"Suggestion";
			// 
			// SuggestPanel
			// 
			this->SuggestPanel->BackColor = System::Drawing::SystemColors::Window;
			this->SuggestPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SuggestPanel->Controls->Add(this->SuggestText);
			this->SuggestPanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SuggestPanel->Location = System::Drawing::Point(25, 157);
			this->SuggestPanel->Name = L"SuggestPanel";
			this->SuggestPanel->Size = System::Drawing::Size(374, 72);
			this->SuggestPanel->TabIndex = 19;
			// 
			// SuggestText
			// 
			this->SuggestText->AccessibleName = L"StudentNameText";
			this->SuggestText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SuggestText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SuggestText->Location = System::Drawing::Point(9, 7);
			this->SuggestText->Multiline = true;
			this->SuggestText->Name = L"SuggestText";
			this->SuggestText->Size = System::Drawing::Size(356, 56);
			this->SuggestText->TabIndex = 0;
			// 
			// SuggestionsControlBtns
			// 
			this->SuggestionsControlBtns->AccessibleName = L"SuggestionsControlBtns";
			this->SuggestionsControlBtns->Controls->Add(this->AddSuggestBtn);
			this->SuggestionsControlBtns->Controls->Add(this->EditSuggestBtn);
			this->SuggestionsControlBtns->Controls->Add(this->DeleteSuggestBtn);
			this->SuggestionsControlBtns->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->SuggestionsControlBtns->Location = System::Drawing::Point(0, 354);
			this->SuggestionsControlBtns->Name = L"SuggestionsControlBtns";
			this->SuggestionsControlBtns->Size = System::Drawing::Size(425, 69);
			this->SuggestionsControlBtns->TabIndex = 2;
			// 
			// AddSuggestBtn
			// 
			this->AddSuggestBtn->AccessibleName = L"AddSuggestBtn";
			this->AddSuggestBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->AddSuggestBtn->FlatAppearance->BorderSize = 0;
			this->AddSuggestBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AddSuggestBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AddSuggestBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			this->AddSuggestBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"AddSuggestBtn.Image")));
			this->AddSuggestBtn->Location = System::Drawing::Point(5, 5);
			this->AddSuggestBtn->Margin = System::Windows::Forms::Padding(5);
			this->AddSuggestBtn->Name = L"AddSuggestBtn";
			this->AddSuggestBtn->Size = System::Drawing::Size(130, 56);
			this->AddSuggestBtn->TabIndex = 0;
			this->AddSuggestBtn->Text = L"Add";
			this->AddSuggestBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->AddSuggestBtn->UseVisualStyleBackColor = false;
			this->AddSuggestBtn->Click += gcnew System::EventHandler(this, &BookSuggestions::AddSuggestBtn_Click);
			// 
			// EditSuggestBtn
			// 
			this->EditSuggestBtn->AccessibleName = L"EditSuggestBtn";
			this->EditSuggestBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->EditSuggestBtn->FlatAppearance->BorderSize = 0;
			this->EditSuggestBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->EditSuggestBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EditSuggestBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			this->EditSuggestBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"EditSuggestBtn.Image")));
			this->EditSuggestBtn->Location = System::Drawing::Point(145, 5);
			this->EditSuggestBtn->Margin = System::Windows::Forms::Padding(5);
			this->EditSuggestBtn->Name = L"EditSuggestBtn";
			this->EditSuggestBtn->Size = System::Drawing::Size(130, 56);
			this->EditSuggestBtn->TabIndex = 0;
			this->EditSuggestBtn->Text = L"Edit";
			this->EditSuggestBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->EditSuggestBtn->UseVisualStyleBackColor = false;
			this->EditSuggestBtn->Click += gcnew System::EventHandler(this, &BookSuggestions::EditSuggestBtn_Click);
			// 
			// DeleteSuggestBtn
			// 
			this->DeleteSuggestBtn->AccessibleName = L"DeleteSuggestBtn";
			this->DeleteSuggestBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->DeleteSuggestBtn->FlatAppearance->BorderSize = 0;
			this->DeleteSuggestBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->DeleteSuggestBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DeleteSuggestBtn->ForeColor = System::Drawing::Color::Red;
			this->DeleteSuggestBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"DeleteSuggestBtn.Image")));
			this->DeleteSuggestBtn->Location = System::Drawing::Point(285, 5);
			this->DeleteSuggestBtn->Margin = System::Windows::Forms::Padding(5);
			this->DeleteSuggestBtn->Name = L"DeleteSuggestBtn";
			this->DeleteSuggestBtn->Size = System::Drawing::Size(130, 56);
			this->DeleteSuggestBtn->TabIndex = 0;
			this->DeleteSuggestBtn->Text = L"Delete";
			this->DeleteSuggestBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->DeleteSuggestBtn->UseVisualStyleBackColor = false;
			this->DeleteSuggestBtn->Click += gcnew System::EventHandler(this, &BookSuggestions::DeleteSuggestBtn_Click);
			// 
			// SuggestHeaderPanel
			// 
			this->SuggestHeaderPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SuggestHeaderPanel->Controls->Add(this->HomeHeaderLabel);
			this->SuggestHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->SuggestHeaderPanel->Location = System::Drawing::Point(0, 0);
			this->SuggestHeaderPanel->Name = L"SuggestHeaderPanel";
			this->SuggestHeaderPanel->Size = System::Drawing::Size(425, 77);
			this->SuggestHeaderPanel->TabIndex = 1;
			// 
			// HomeHeaderLabel
			// 
			this->HomeHeaderLabel->AccessibleName = L"HomeHeaderLabel";
			this->HomeHeaderLabel->AutoSize = true;
			this->HomeHeaderLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->HomeHeaderLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->HomeHeaderLabel->Location = System::Drawing::Point(61, 17);
			this->HomeHeaderLabel->Name = L"HomeHeaderLabel";
			this->HomeHeaderLabel->Size = System::Drawing::Size(304, 41);
			this->HomeHeaderLabel->TabIndex = 1;
			this->HomeHeaderLabel->Text = L"Suggestions Control";
			// 
			// BContainer
			// 
			this->BContainer->Controls->Add(this->panel3);
			this->BContainer->Controls->Add(this->SearchPanel);
			this->BContainer->Controls->Add(this->SuggestFromContainer);
			this->BContainer->Controls->Add(this->SuggestTabelPanel);
			this->BContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->BContainer->Location = System::Drawing::Point(0, 0);
			this->BContainer->Name = L"BContainer";
			this->BContainer->Size = System::Drawing::Size(878, 1001);
			this->BContainer->TabIndex = 18;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->Logo);
			this->panel3->Controls->Add(this->closeBtn);
			this->panel3->Controls->Add(this->miniBtn);
			this->panel3->Location = System::Drawing::Point(3, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(867, 89);
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
			this->closeBtn->Location = System::Drawing::Point(772, 4);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(87, 74);
			this->closeBtn->TabIndex = 23;
			this->closeBtn->UseVisualStyleBackColor = true;
			this->closeBtn->Click += gcnew System::EventHandler(this, &BookSuggestions::closeBtn_Click);
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
			this->miniBtn->Click += gcnew System::EventHandler(this, &BookSuggestions::miniBtn_Click);
			// 
			// SearchPanel
			// 
			this->SearchPanel->AccessibleName = L"SearchPanel";
			this->SearchPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SearchPanel->Controls->Add(this->panel2);
			this->SearchPanel->Controls->Add(this->panel1);
			this->SearchPanel->Controls->Add(this->SearchHeaderPanel);
			this->SearchPanel->Location = System::Drawing::Point(6, 101);
			this->SearchPanel->Margin = System::Windows::Forms::Padding(6);
			this->SearchPanel->Name = L"SearchPanel";
			this->SearchPanel->Size = System::Drawing::Size(426, 425);
			this->SearchPanel->TabIndex = 19;
			// 
			// panel2
			// 
			this->panel2->AccessibleName = L"SearchSuggestionsPanel";
			this->panel2->BackColor = System::Drawing::SystemColors::Window;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->SearchForStudentsText);
			this->panel2->Location = System::Drawing::Point(10, 93);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(404, 45);
			this->panel2->TabIndex = 20;
			// 
			// SearchForStudentsText
			// 
			this->SearchForStudentsText->AccessibleName = L"SearchForStudentsText";
			this->SearchForStudentsText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SearchForStudentsText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SearchForStudentsText->Location = System::Drawing::Point(10, 5);
			this->SearchForStudentsText->Multiline = true;
			this->SearchForStudentsText->Name = L"SearchForStudentsText";
			this->SearchForStudentsText->Size = System::Drawing::Size(385, 32);
			this->SearchForStudentsText->TabIndex = 0;
			this->SearchForStudentsText->TextChanged += gcnew System::EventHandler(this, &BookSuggestions::SearchForStudentsText_TextChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel1->Controls->Add(this->resultListStudents);
			this->panel1->Location = System::Drawing::Point(10, 163);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(404, 252);
			this->panel1->TabIndex = 3;
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
			this->resultListStudents->Location = System::Drawing::Point(13, 8);
			this->resultListStudents->Name = L"resultListStudents";
			this->resultListStudents->Size = System::Drawing::Size(382, 232);
			this->resultListStudents->TabIndex = 5;
			this->resultListStudents->SelectedIndexChanged += gcnew System::EventHandler(this, &BookSuggestions::resultListStudents_SelectedIndexChanged);
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
			// SuggestTabelPanel
			// 
			this->SuggestTabelPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SuggestTabelPanel->Controls->Add(this->SuggestionsTable);
			this->SuggestTabelPanel->Controls->Add(this->SuggestTableHeaderPanel);
			this->SuggestTabelPanel->Location = System::Drawing::Point(5, 537);
			this->SuggestTabelPanel->Margin = System::Windows::Forms::Padding(5, 5, 3, 5);
			this->SuggestTabelPanel->Name = L"SuggestTabelPanel";
			this->SuggestTabelPanel->Size = System::Drawing::Size(866, 332);
			this->SuggestTabelPanel->TabIndex = 18;
			// 
			// SuggestionsTable
			// 
			this->SuggestionsTable->AllowUserToAddRows = false;
			this->SuggestionsTable->AllowUserToResizeRows = false;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(245)));
			this->SuggestionsTable->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->SuggestionsTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->SuggestionsTable->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->SuggestionsTable->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SuggestionsTable->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->SuggestionsTable->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->SuggestionsTable->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->SuggestionsTable->ColumnHeadersHeight = 50;
			this->SuggestionsTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->SuggestionsTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Id,
					this->StudentName, this->StudentSeatnumber, this->Suggestion
			});
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->SuggestionsTable->DefaultCellStyle = dataGridViewCellStyle4;
			this->SuggestionsTable->Dock = System::Windows::Forms::DockStyle::Fill;
			this->SuggestionsTable->EnableHeadersVisualStyles = false;
			this->SuggestionsTable->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->SuggestionsTable->Location = System::Drawing::Point(0, 66);
			this->SuggestionsTable->Name = L"SuggestionsTable";
			this->SuggestionsTable->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->SuggestionsTable->RowHeadersVisible = false;
			this->SuggestionsTable->RowHeadersWidth = 4;
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->SuggestionsTable->RowsDefaultCellStyle = dataGridViewCellStyle5;
			this->SuggestionsTable->RowTemplate->DefaultCellStyle->Padding = System::Windows::Forms::Padding(5);
			this->SuggestionsTable->RowTemplate->Height = 40;
			this->SuggestionsTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->SuggestionsTable->Size = System::Drawing::Size(864, 264);
			this->SuggestionsTable->TabIndex = 19;
			this->SuggestionsTable->SelectionChanged += gcnew System::EventHandler(this, &BookSuggestions::SuggestionsTable_SelectionChanged);
			// 
			// Id
			// 
			this->Id->FillWeight = 15;
			this->Id->HeaderText = L"ID";
			this->Id->MaxInputLength = 20;
			this->Id->MinimumWidth = 6;
			this->Id->Name = L"Id";
			this->Id->ReadOnly = true;
			// 
			// StudentName
			// 
			this->StudentName->FillWeight = 25;
			this->StudentName->HeaderText = L"Student Name";
			this->StudentName->MaxInputLength = 40;
			this->StudentName->MinimumWidth = 6;
			this->StudentName->Name = L"StudentName";
			this->StudentName->ReadOnly = true;
			// 
			// StudentSeatnumber
			// 
			this->StudentSeatnumber->DataPropertyName = L"StudentSeatnumber";
			this->StudentSeatnumber->FillWeight = 30;
			this->StudentSeatnumber->HeaderText = L"Student Seat Number";
			this->StudentSeatnumber->MaxInputLength = 10;
			this->StudentSeatnumber->MinimumWidth = 6;
			this->StudentSeatnumber->Name = L"StudentSeatnumber";
			this->StudentSeatnumber->ReadOnly = true;
			// 
			// Suggestion
			// 
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->Suggestion->DefaultCellStyle = dataGridViewCellStyle3;
			this->Suggestion->FillWeight = 40;
			this->Suggestion->HeaderText = L"Suggestion";
			this->Suggestion->MaxInputLength = 1000;
			this->Suggestion->MinimumWidth = 6;
			this->Suggestion->Name = L"Suggestion";
			this->Suggestion->ReadOnly = true;
			// 
			// SuggestTableHeaderPanel
			// 
			this->SuggestTableHeaderPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SuggestTableHeaderPanel->Controls->Add(this->excelBtn);
			this->SuggestTableHeaderPanel->Controls->Add(this->printBtn);
			this->SuggestTableHeaderPanel->Controls->Add(this->SearchSuggestionsPanel);
			this->SuggestTableHeaderPanel->Controls->Add(this->label1);
			this->SuggestTableHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->SuggestTableHeaderPanel->Location = System::Drawing::Point(0, 0);
			this->SuggestTableHeaderPanel->Name = L"SuggestTableHeaderPanel";
			this->SuggestTableHeaderPanel->Size = System::Drawing::Size(864, 66);
			this->SuggestTableHeaderPanel->TabIndex = 0;
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
			this->excelBtn->Location = System::Drawing::Point(378, 9);
			this->excelBtn->Name = L"excelBtn";
			this->excelBtn->Size = System::Drawing::Size(75, 50);
			this->excelBtn->TabIndex = 22;
			this->excelBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->excelBtn->UseVisualStyleBackColor = false;
			this->excelBtn->Click += gcnew System::EventHandler(this, &BookSuggestions::excelBtn_Click);
			// 
			// printBtn
			// 
			this->printBtn->AccessibleName = L"printBtn";
			this->printBtn->BackColor = System::Drawing::SystemColors::Info;
			this->printBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->printBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"printBtn.Image")));
			this->printBtn->Location = System::Drawing::Point(295, 9);
			this->printBtn->Name = L"printBtn";
			this->printBtn->Size = System::Drawing::Size(75, 50);
			this->printBtn->TabIndex = 23;
			this->printBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->printBtn->UseVisualStyleBackColor = false;
			this->printBtn->Click += gcnew System::EventHandler(this, &BookSuggestions::printBtn_Click);
			// 
			// SearchSuggestionsPanel
			// 
			this->SearchSuggestionsPanel->AccessibleName = L"SearchSuggestionsPanel";
			this->SearchSuggestionsPanel->BackColor = System::Drawing::SystemColors::Window;
			this->SearchSuggestionsPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->SearchSuggestionsPanel->Controls->Add(this->SearchSuggestionsText);
			this->SearchSuggestionsPanel->Location = System::Drawing::Point(463, 11);
			this->SearchSuggestionsPanel->Name = L"SearchSuggestionsPanel";
			this->SearchSuggestionsPanel->Size = System::Drawing::Size(388, 45);
			this->SearchSuggestionsPanel->TabIndex = 20;
			// 
			// SearchSuggestionsText
			// 
			this->SearchSuggestionsText->AccessibleName = L"SearchSuggestionsText";
			this->SearchSuggestionsText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->SearchSuggestionsText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->SearchSuggestionsText->Location = System::Drawing::Point(13, 6);
			this->SearchSuggestionsText->Multiline = true;
			this->SearchSuggestionsText->Name = L"SearchSuggestionsText";
			this->SearchSuggestionsText->Size = System::Drawing::Size(360, 32);
			this->SearchSuggestionsText->TabIndex = 0;
			this->SearchSuggestionsText->TextChanged += gcnew System::EventHandler(this, &BookSuggestions::SearchSuggestionsText_TextChanged);
			// 
			// label1
			// 
			this->label1->AccessibleName = L"HomeHeaderLabel";
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(56)), static_cast<System::Int32>(static_cast<System::Byte>(95)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->label1->Location = System::Drawing::Point(14, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(273, 41);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Suggestions Table";
			// 
			// BookSuggestions
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(878, 1001);
			this->Controls->Add(this->BContainer);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"BookSuggestions";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"BookSuggestions";
			this->SuggestFromContainer->ResumeLayout(false);
			this->SuggestionsForm->ResumeLayout(false);
			this->SuggestionsForm->PerformLayout();
			this->StudentIdPanel->ResumeLayout(false);
			this->StudentIdPanel->PerformLayout();
			this->SuggestPanel->ResumeLayout(false);
			this->SuggestPanel->PerformLayout();
			this->SuggestionsControlBtns->ResumeLayout(false);
			this->SuggestHeaderPanel->ResumeLayout(false);
			this->SuggestHeaderPanel->PerformLayout();
			this->BContainer->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->SearchPanel->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->SearchHeaderPanel->ResumeLayout(false);
			this->SearchHeaderPanel->PerformLayout();
			this->SuggestTabelPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SuggestionsTable))->EndInit();
			this->SuggestTableHeaderPanel->ResumeLayout(false);
			this->SuggestTableHeaderPanel->PerformLayout();
			this->SearchSuggestionsPanel->ResumeLayout(false);
			this->SearchSuggestionsPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//SEARCH SUGGESTION TABLE 
	private: System::Void SearchSuggestionsText_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		UIHelper::FilterDataGridView(SuggestionsTable, SearchSuggestionsText->Text);
	}
		   //SEARCH FOR STUDENTS
		   //WINDOW CONTROL		
	private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void miniBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->WindowState == System::Windows::Forms::FormWindowState::Maximized) {
			this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
		}
		else {
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;

		}
	}



		   //printing and exporting
	private: System::Void printBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		UIHelper::PrintTable(SuggestionsTable);
	}
	private: System::Void excelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		UIHelper::ExportTableToCsv(SuggestionsTable);
	}


	private: System::Void SearchForStudentsText_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ searchText = SearchForStudentsText->Text->Trim();
		resultListStudents->Items->Clear();

		if (String::IsNullOrEmpty(searchText) || searchText->Length < 1) return;

		auto controller = gcnew BookSuggestionController();
		auto students = controller->SearchStudents(searchText, currentUser->Id);

		for each (auto student in students) {
			// Store both display text and student ID (separated by |)
			String^ displayText = String::Format("{0} - {1} (Seat: {2})|{3}",
				student->Name,
				student->Department,
				student->SeatNumber,
				student->Id);

			resultListStudents->Items->Add(displayText);
		}
	}




	private: System::Void resultListStudents_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (resultListStudents->SelectedIndex == -1) return;

		// Get the selected item text
		String^ selectedItem = resultListStudents->SelectedItem->ToString();

		// Extract the student ID (part after the last |)
		int lastPipeIndex = selectedItem->LastIndexOf('|');
		if (lastPipeIndex >= 0) {
			String^ studentIdStr = selectedItem->Substring(lastPipeIndex + 1);
			int studentId;
			if (Int32::TryParse(studentIdStr, studentId)) {
				// Set the student ID in your form
				StidentIdText->Text = studentId.ToString();

				// Optional: Focus on the suggestion text box for quick input
				SuggestText->Focus();
			}
		}
	}
	private: System::Void AddSuggestBtn_Click(System::Object^ sender, System::EventArgs^ e) {


		// Validate inputs
		if (String::IsNullOrEmpty(StidentIdText->Text)) {
			MessageBox::Show("Please select a student first");
			return;
		}

		if (String::IsNullOrEmpty(SuggestText->Text)) {
			MessageBox::Show("Please enter a suggestion");
			return;
		}

		try {
			// Create new suggestion
			auto suggestion = gcnew BookSuggestionModel();
			suggestion->StudentId = Int32::Parse(StidentIdText->Text);
			suggestion->Suggestion = SuggestText->Text;
			suggestion->UserId = currentUser->Id;

			// Save to database
			auto controller = gcnew BookSuggestionController();
			controller->Create(suggestion);

			// Clear inputs and refresh table
			SuggestText->Clear();
			RefreshSuggestionsTable();

			MessageBox::Show("Suggestion added successfully");
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error adding suggestion: " + ex->Message);
		}
	}


	private: Void RefreshSuggestionsTable() {
		auto controller = gcnew BookSuggestionController();
		auto suggestions = controller->GetByUserId(currentUser->Id);

		// Clear existing rows
		SuggestionsTable->Rows->Clear();

		// Add new rows
		for each (auto suggestion in suggestions) {
			// You might need to get student details here
			auto studentController = gcnew StudentsController();
			auto student = studentController->GetById(suggestion->StudentId);

			SuggestionsTable->Rows->Add(
				suggestion->Id,
				student->Name,
				student->SeatNumber,
				suggestion->Suggestion
			);
		}
	}

private: System::Void EditSuggestBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	// Check if a row is selected
	if (SuggestionsTable->SelectedRows->Count == 0) {
		MessageBox::Show("Please select a suggestion to edit.");
		return;
	}

	// Get the selected row
	auto selectedRow = SuggestionsTable->SelectedRows[0];
	int suggestionId = Convert::ToInt32(selectedRow->Cells["Id"]->Value);

	// Get the existing suggestion
	auto controller = gcnew BookSuggestionController();
	auto suggestion = controller->GetById(suggestionId);

	if (suggestion == nullptr) {
		MessageBox::Show("Selected suggestion not found.");
		return;
	}

	// Update suggestion properties from form controls
	suggestion->Suggestion = SuggestText->Text;
	// StudentId and UserId should remain unchanged

	if (controller->Update(suggestion)) {
		MessageBox::Show("Suggestion updated successfully.");
		RefreshSuggestionsTable(); // Refresh the DataGridView
	}
	else {
		MessageBox::Show("Failed to update suggestion.");
	}
}
	  private: System::Void DeleteSuggestBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		  // Check if a row is selected
		  if (SuggestionsTable->SelectedRows->Count == 0) {
			  MessageBox::Show("Please select a suggestion to delete.");
			  return;
		  }

		  // Get the selected row
		  auto selectedRow = SuggestionsTable->SelectedRows[0];
		  int suggestionId = Convert::ToInt32(selectedRow->Cells["Id"]->Value);

		  // Confirm deletion directly
		  if (MessageBox::Show(
			  "Are you sure you want to delete this suggestion?",
			  "Confirm Delete",
			  MessageBoxButtons::YesNo,
			  MessageBoxIcon::Question
		  ) != Windows::Forms::DialogResult::Yes) {
			  return;
		  }

		  // Delete the suggestion
		  auto controller = gcnew BookSuggestionController();
		  if (controller->Delete(suggestionId)) {
			  MessageBox::Show("Suggestion deleted successfully.");
			  RefreshSuggestionsTable(); // Refresh the DataGridView
		  }
		  else {
			  MessageBox::Show("Failed to delete suggestion.");
		  }
	  }


			  private: System::Void SuggestionsTable_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
				  if (SuggestionsTable->SelectedRows->Count > 0) {
					  auto selectedRow = SuggestionsTable->SelectedRows[0];

					  // Display selected suggestion in the text box
					  SuggestText->Text = selectedRow->Cells["Suggestion"]->Value->ToString();

					  // Display student ID (if needed)
					  StidentIdText->Text = selectedRow->Cells["Id"]->Value->ToString();
				  }
			  }
};
}
