#pragma once
#include "../Forms/Books.h"
#include "../Forms/BookSuggestions.h"
#include "../Forms/Student.h"
#include "../Forms/Loan.h"
#include "../Models/userModel.h"
#include "../Forms/Home.h"
namespace LaibraryProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Home : public System::Windows::Forms::Form
    {
    public:
        Home(void)
        {
            InitializeComponent();
            resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
            //resources =gcnew System::Resources::ResourceManager("LaibraryProject.Forms.Home", System::Reflection::Assembly::GetExecutingAssembly());

            // Set form icon
            //this->Icon = gcnew System::Drawing::Icon("book_icon.ico");
        }
        Home(UserModel^ user);
        System::Void Home::Home_FormClosing(System::Object^ sender, FormClosingEventArgs^ e);
    protected: virtual void WndProc(System::Windows::Forms::Message% m) override {
        const int WM_NCHITTEST = 0x84;
        const int HTCLIENT = 1;
        const int HTCAPTION = 2;

        Form::WndProc(m);

        if (m.Msg == WM_NCHITTEST && (int)m.Result == HTCLIENT) {
            m.Result = (System::IntPtr)HTCAPTION;
        }
    }


    protected:
        ~Home()
        {
            if (components)
            {
                delete components;
            }
        }

    private:


        void LoadUserData() {
            this->WelcomeLabel->Text = "Library Of : " + currentUser->Name;
        }




        //System::Resources::ResourceManager^ resources;

        System::ComponentModel::ComponentResourceManager^ resources;

        System::Windows::Forms::Panel^ footerPanel;
        System::Windows::Forms::Label^ footerLabel;
    private: System::Windows::Forms::FlowLayoutPanel^ NavButtons;
    private: System::Windows::Forms::Button^ BooksSuggestionsNavBtn;
    private: System::Windows::Forms::Button^ StudentsNavBtn;
    private: System::Windows::Forms::Button^ BooksNavBtn;
    private: System::Windows::Forms::Button^ RentNavBtn;
    private: System::Windows::Forms::Panel^ HomeHeaderPanel;
    private: System::Windows::Forms::Label^ HomeHeaderLabel;
    private: System::Windows::Forms::Panel^ Container;
    private: System::Windows::Forms::Label^ WelcomeLabel;

           //Database
           UserModel^ currentUser;
    private: System::Windows::Forms::Button^ closeBtn;
    private: System::Windows::Forms::Button^ miniBtn;
    private: System::Windows::Forms::Label^ Logo;


           BookSuggestions^ bookSuggestionsForm = nullptr;
           Student^ studentForm = nullptr;
           Books^ booksForm = nullptr;
           Loan^ loanForm = nullptr;



        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
            this->footerPanel = (gcnew System::Windows::Forms::Panel());
            this->footerLabel = (gcnew System::Windows::Forms::Label());
            this->NavButtons = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->BooksSuggestionsNavBtn = (gcnew System::Windows::Forms::Button());
            this->StudentsNavBtn = (gcnew System::Windows::Forms::Button());
            this->BooksNavBtn = (gcnew System::Windows::Forms::Button());
            this->RentNavBtn = (gcnew System::Windows::Forms::Button());
            this->HomeHeaderPanel = (gcnew System::Windows::Forms::Panel());
            this->HomeHeaderLabel = (gcnew System::Windows::Forms::Label());
            this->Container = (gcnew System::Windows::Forms::Panel());
            this->WelcomeLabel = (gcnew System::Windows::Forms::Label());
            this->closeBtn = (gcnew System::Windows::Forms::Button());
            this->miniBtn = (gcnew System::Windows::Forms::Button());
            this->Logo = (gcnew System::Windows::Forms::Label());
            this->footerPanel->SuspendLayout();
            this->NavButtons->SuspendLayout();
            this->HomeHeaderPanel->SuspendLayout();
            this->Container->SuspendLayout();
            this->SuspendLayout();
            // 
            // footerPanel
            // 
            this->footerPanel->BackColor = System::Drawing::Color::DarkSlateGray;
            this->footerPanel->Controls->Add(this->footerLabel);
            this->footerPanel->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->footerPanel->Location = System::Drawing::Point(0, 742);
            this->footerPanel->Name = L"footerPanel";
            this->footerPanel->Size = System::Drawing::Size(640, 40);
            this->footerPanel->TabIndex = 3;
            // 
            // footerLabel
            // 
            this->footerLabel->AutoSize = true;
            this->footerLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->footerLabel->ForeColor = System::Drawing::Color::White;
            this->footerLabel->Location = System::Drawing::Point(20, 10);
            this->footerLabel->Name = L"footerLabel";
            this->footerLabel->Size = System::Drawing::Size(250, 20);
            this->footerLabel->TabIndex = 0;
            this->footerLabel->Text = L"Library Management System © 2023";
            // 
            // NavButtons
            // 
            this->NavButtons->AccessibleName = L"NavButtons";
            this->NavButtons->Controls->Add(this->BooksSuggestionsNavBtn);
            this->NavButtons->Controls->Add(this->StudentsNavBtn);
            this->NavButtons->Controls->Add(this->BooksNavBtn);
            this->NavButtons->Controls->Add(this->RentNavBtn);
            this->NavButtons->Location = System::Drawing::Point(20, 120);
            this->NavButtons->Margin = System::Windows::Forms::Padding(0);
            this->NavButtons->Name = L"NavButtons";
            this->NavButtons->Size = System::Drawing::Size(500, 400);
            this->NavButtons->TabIndex = 0;
            // 
            // BooksSuggestionsNavBtn
            // 
            this->BooksSuggestionsNavBtn->AccessibleName = L"BooksSuggestionsNavBtn";
            this->BooksSuggestionsNavBtn->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BooksSuggestionsNavBtn->FlatAppearance->BorderSize = 0;
            this->BooksSuggestionsNavBtn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
            this->BooksSuggestionsNavBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BooksSuggestionsNavBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->BooksSuggestionsNavBtn->ForeColor = System::Drawing::Color::White;
            this->BooksSuggestionsNavBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BooksSuggestionsNavBtn.Image")));
            this->BooksSuggestionsNavBtn->Location = System::Drawing::Point(10, 10);
            this->BooksSuggestionsNavBtn->Margin = System::Windows::Forms::Padding(10);
            this->BooksSuggestionsNavBtn->Name = L"BooksSuggestionsNavBtn";
            this->BooksSuggestionsNavBtn->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
            this->BooksSuggestionsNavBtn->Size = System::Drawing::Size(480, 80);
            this->BooksSuggestionsNavBtn->TabIndex = 0;
            this->BooksSuggestionsNavBtn->Text = L"  Book Suggestions";
            this->BooksSuggestionsNavBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->BooksSuggestionsNavBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->BooksSuggestionsNavBtn->UseVisualStyleBackColor = false;
            this->BooksSuggestionsNavBtn->Click += gcnew System::EventHandler(this, &Home::BooksSuggestionsNavBtn_Click);
            // 
            // StudentsNavBtn
            // 
            this->StudentsNavBtn->AccessibleName = L"StudentsNavBtn";
            this->StudentsNavBtn->BackColor = System::Drawing::Color::LightSeaGreen;
            this->StudentsNavBtn->FlatAppearance->BorderSize = 0;
            this->StudentsNavBtn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
            this->StudentsNavBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->StudentsNavBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->StudentsNavBtn->ForeColor = System::Drawing::Color::White;
            this->StudentsNavBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"StudentsNavBtn.Image")));
            this->StudentsNavBtn->Location = System::Drawing::Point(10, 110);
            this->StudentsNavBtn->Margin = System::Windows::Forms::Padding(10);
            this->StudentsNavBtn->Name = L"StudentsNavBtn";
            this->StudentsNavBtn->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
            this->StudentsNavBtn->Size = System::Drawing::Size(480, 80);
            this->StudentsNavBtn->TabIndex = 1;
            this->StudentsNavBtn->Text = L"Manage Students";
            this->StudentsNavBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->StudentsNavBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->StudentsNavBtn->UseVisualStyleBackColor = false;
            this->StudentsNavBtn->Click += gcnew System::EventHandler(this, &Home::StudentsNavBtn_Click);
            // 
            // BooksNavBtn
            // 
            this->BooksNavBtn->AccessibleName = L"BooksNavBtn";
            this->BooksNavBtn->BackColor = System::Drawing::Color::LightSeaGreen;
            this->BooksNavBtn->FlatAppearance->BorderSize = 0;
            this->BooksNavBtn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
            this->BooksNavBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->BooksNavBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->BooksNavBtn->ForeColor = System::Drawing::Color::White;
            this->BooksNavBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"BooksNavBtn.Image")));
            this->BooksNavBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->BooksNavBtn->Location = System::Drawing::Point(10, 210);
            this->BooksNavBtn->Margin = System::Windows::Forms::Padding(10);
            this->BooksNavBtn->Name = L"BooksNavBtn";
            this->BooksNavBtn->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
            this->BooksNavBtn->Size = System::Drawing::Size(480, 80);
            this->BooksNavBtn->TabIndex = 2;
            this->BooksNavBtn->Text = L" Manage Books";
            this->BooksNavBtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->BooksNavBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->BooksNavBtn->UseVisualStyleBackColor = false;
            this->BooksNavBtn->Click += gcnew System::EventHandler(this, &Home::BooksNavBtn_Click);
            // 
            // RentNavBtn
            // 
            this->RentNavBtn->AccessibleName = L"RentNavBtn";
            this->RentNavBtn->BackColor = System::Drawing::Color::LightSeaGreen;
            this->RentNavBtn->FlatAppearance->BorderSize = 0;
            this->RentNavBtn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(70)), static_cast<System::Int32>(static_cast<System::Byte>(90)));
            this->RentNavBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->RentNavBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->RentNavBtn->ForeColor = System::Drawing::Color::White;
            this->RentNavBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RentNavBtn.Image")));
            this->RentNavBtn->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->RentNavBtn->Location = System::Drawing::Point(10, 310);
            this->RentNavBtn->Margin = System::Windows::Forms::Padding(10);
            this->RentNavBtn->Name = L"RentNavBtn";
            this->RentNavBtn->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
            this->RentNavBtn->Size = System::Drawing::Size(480, 80);
            this->RentNavBtn->TabIndex = 3;
            this->RentNavBtn->Text = L"Rent a Book";
            this->RentNavBtn->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->RentNavBtn->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
            this->RentNavBtn->UseVisualStyleBackColor = false;
            this->RentNavBtn->Click += gcnew System::EventHandler(this, &Home::RentNavBtn_Click);
            // 
            // HomeHeaderPanel
            // 
            this->HomeHeaderPanel->BackColor = System::Drawing::Color::DarkSlateGray;
            this->HomeHeaderPanel->Controls->Add(this->HomeHeaderLabel);
            this->HomeHeaderPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->HomeHeaderPanel->Location = System::Drawing::Point(0, 0);
            this->HomeHeaderPanel->Name = L"HomeHeaderPanel";
            this->HomeHeaderPanel->Size = System::Drawing::Size(538, 80);
            this->HomeHeaderPanel->TabIndex = 1;
            // 
            // HomeHeaderLabel
            // 
            this->HomeHeaderLabel->AccessibleName = L"HomeHeaderLabel";
            this->HomeHeaderLabel->AutoSize = true;
            this->HomeHeaderLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->HomeHeaderLabel->ForeColor = System::Drawing::Color::White;
            this->HomeHeaderLabel->Location = System::Drawing::Point(81, 21);
            this->HomeHeaderLabel->Name = L"HomeHeaderLabel";
            this->HomeHeaderLabel->Size = System::Drawing::Size(354, 38);
            this->HomeHeaderLabel->TabIndex = 0;
            this->HomeHeaderLabel->Text = L"Start Control Your Library";
            // 
            // Container
            // 
            this->Container->BackColor = System::Drawing::Color::White;
            this->Container->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->Container->Controls->Add(this->HomeHeaderPanel);
            this->Container->Controls->Add(this->NavButtons);
            this->Container->Location = System::Drawing::Point(50, 183);
            this->Container->Name = L"Container";
            this->Container->Size = System::Drawing::Size(540, 540);
            this->Container->TabIndex = 1;
            // 
            // WelcomeLabel
            // 
            this->WelcomeLabel->AccessibleName = L"WelcomeLabel";
            this->WelcomeLabel->AutoSize = true;
            this->WelcomeLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->WelcomeLabel->ForeColor = System::Drawing::Color::LightSeaGreen;
            this->WelcomeLabel->Location = System::Drawing::Point(80, 111);
            this->WelcomeLabel->Name = L"WelcomeLabel";
            this->WelcomeLabel->Size = System::Drawing::Size(177, 41);
            this->WelcomeLabel->TabIndex = 0;
            this->WelcomeLabel->Text = L"Library Of :";
            // 
            // closeBtn
            // 
            this->closeBtn->AccessibleName = L"closeBtn";
            this->closeBtn->FlatAppearance->BorderSize = 0;
            this->closeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->closeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeBtn.Image")));
            this->closeBtn->Location = System::Drawing::Point(541, 12);
            this->closeBtn->Name = L"closeBtn";
            this->closeBtn->Size = System::Drawing::Size(87, 74);
            this->closeBtn->TabIndex = 4;
            this->closeBtn->UseVisualStyleBackColor = true;
            this->closeBtn->Click += gcnew System::EventHandler(this, &Home::closeBtn_Click);
            // 
            // miniBtn
            // 
            this->miniBtn->AccessibleName = L"miniBtn";
            this->miniBtn->FlatAppearance->BorderSize = 0;
            this->miniBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->miniBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"miniBtn.Image")));
            this->miniBtn->Location = System::Drawing::Point(454, 28);
            this->miniBtn->Name = L"miniBtn";
            this->miniBtn->Size = System::Drawing::Size(75, 36);
            this->miniBtn->TabIndex = 4;
            this->miniBtn->UseVisualStyleBackColor = true;
            this->miniBtn->Click += gcnew System::EventHandler(this, &Home::miniBtn_Click);
            // 
            // Logo
            // 
            this->Logo->AutoSize = true;
            this->Logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Logo.Image")));
            this->Logo->Location = System::Drawing::Point(23, 16);
            this->Logo->MinimumSize = System::Drawing::Size(100, 90);
            this->Logo->Name = L"Logo";
            this->Logo->Size = System::Drawing::Size(100, 90);
            this->Logo->TabIndex = 5;
            // 
            // Home
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
                static_cast<System::Int32>(static_cast<System::Byte>(250)));
            this->ClientSize = System::Drawing::Size(640, 782);
            this->Controls->Add(this->Logo);
            this->Controls->Add(this->miniBtn);
            this->Controls->Add(this->closeBtn);
            this->Controls->Add(this->footerPanel);
            this->Controls->Add(this->WelcomeLabel);
            this->Controls->Add(this->Container);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->Name = L"Home";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Library Management System";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Home::Home_FormClosing);
            this->footerPanel->ResumeLayout(false);
            this->footerPanel->PerformLayout();
            this->NavButtons->ResumeLayout(false);
            this->HomeHeaderPanel->ResumeLayout(false);
            this->HomeHeaderPanel->PerformLayout();
            this->Container->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private:
        System::Void BooksSuggestionsNavBtn_Click(System::Object^ sender, System::EventArgs^ e) {
           if(bookSuggestionsForm == nullptr || bookSuggestionsForm->IsDisposed){
               bookSuggestionsForm = gcnew BookSuggestions(currentUser);
           bookSuggestionsForm->Show();
           }else {
               bookSuggestionsForm->BringToFront();
           }
        }

        System::Void StudentsNavBtn_Click(System::Object^ sender, System::EventArgs^ e) {
            if (studentForm == nullptr || studentForm->IsDisposed) {
                studentForm = gcnew Student(currentUser);
                studentForm->Show();
            }
            else {
                studentForm->BringToFront();
            }
        }


        System::Void BooksNavBtn_Click(System::Object^ sender, System::EventArgs^ e) {
            if (booksForm == nullptr || booksForm->IsDisposed) {
                booksForm = gcnew Books(currentUser);
                booksForm->Show();
            }
            else {
                booksForm->BringToFront();
            }
        }


        System::Void RentNavBtn_Click(System::Object^ sender, System::EventArgs^ e) {
            if (loanForm == nullptr || loanForm->IsDisposed) {
                loanForm = gcnew Loan(currentUser);
                loanForm->Show();
            }
            else {
                loanForm->BringToFront();
            }
        }

    private: System::Void ExitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
        Application::Exit();
    }
private: System::Void minBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    if (this->WindowState == System::Windows::Forms::FormWindowState::Maximized) {
        this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
    }
    else {
        this->WindowState = System::Windows::Forms::FormWindowState::Maximized;

    }
}

private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    Application::Exit();
}
private: System::Void miniBtn_Click(System::Object^ sender, System::EventArgs^ e) {
    if (this->WindowState == Windows::Forms::FormWindowState::Normal) {
        this->WindowState = Windows::Forms::FormWindowState::Minimized;
    }
    else
    {
        this->WindowState = Windows::Forms::FormWindowState::Normal;

    }
}
};
}