#pragma once
#include "../Controllers/userController.h"
#include "../Models/userModel.h"\

//forms
#include "../Forms/Home.h"
#include "../Forms/Register.h"

namespace LaibraryProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:







	private: System::Windows::Forms::Button^ closeBtn;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ PasswordLabel;
	private: System::Windows::Forms::Label^ NameLabel;
	private: System::Windows::Forms::Panel^ PasswordPanel;
	private: System::Windows::Forms::TextBox^ PasswordText;
	private: System::Windows::Forms::Panel^ NamePanel;
	private: System::Windows::Forms::TextBox^ NameText;
	private: System::Windows::Forms::Button^ LoginBtn;
	private: System::Windows::Forms::Button^ NavToRegisterBtn;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->PasswordLabel = (gcnew System::Windows::Forms::Label());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->PasswordPanel = (gcnew System::Windows::Forms::Panel());
			this->PasswordText = (gcnew System::Windows::Forms::TextBox());
			this->NamePanel = (gcnew System::Windows::Forms::Panel());
			this->NameText = (gcnew System::Windows::Forms::TextBox());
			this->LoginBtn = (gcnew System::Windows::Forms::Button());
			this->NavToRegisterBtn = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->PasswordPanel->SuspendLayout();
			this->NamePanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// closeBtn
			// 
			this->closeBtn->AccessibleName = L"closeBtn";
			this->closeBtn->FlatAppearance->BorderSize = 0;
			this->closeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeBtn.Image")));
			this->closeBtn->Location = System::Drawing::Point(322, 12);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(75, 65);
			this->closeBtn->TabIndex = 12;
			this->closeBtn->UseVisualStyleBackColor = true;
			this->closeBtn->Click += gcnew System::EventHandler(this, &Login::closeBtn_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::DarkSlateGray;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->closeBtn);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(409, 90);
			this->panel1->TabIndex = 13;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(9, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 37);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Login ";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 90);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(409, 334);
			this->panel2->TabIndex = 14;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->PasswordLabel);
			this->panel3->Controls->Add(this->NameLabel);
			this->panel3->Controls->Add(this->PasswordPanel);
			this->panel3->Controls->Add(this->NamePanel);
			this->panel3->Controls->Add(this->LoginBtn);
			this->panel3->Controls->Add(this->NavToRegisterBtn);
			this->panel3->Location = System::Drawing::Point(6, 6);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(398, 321);
			this->panel3->TabIndex = 0;
			// 
			// PasswordLabel
			// 
			this->PasswordLabel->AccessibleName = L"PasswordLabel";
			this->PasswordLabel->AutoSize = true;
			this->PasswordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PasswordLabel->Location = System::Drawing::Point(150, 118);
			this->PasswordLabel->Name = L"PasswordLabel";
			this->PasswordLabel->Size = System::Drawing::Size(106, 25);
			this->PasswordLabel->TabIndex = 22;
			this->PasswordLabel->Text = L"Password";
			// 
			// NameLabel
			// 
			this->NameLabel->AccessibleName = L"NameLabel";
			this->NameLabel->AutoSize = true;
			this->NameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NameLabel->Location = System::Drawing::Point(146, 29);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(110, 25);
			this->NameLabel->TabIndex = 20;
			this->NameLabel->Text = L"Username";
			// 
			// PasswordPanel
			// 
			this->PasswordPanel->BackColor = System::Drawing::SystemColors::Window;
			this->PasswordPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PasswordPanel->Controls->Add(this->PasswordText);
			this->PasswordPanel->Location = System::Drawing::Point(28, 155);
			this->PasswordPanel->Name = L"PasswordPanel";
			this->PasswordPanel->Size = System::Drawing::Size(338, 45);
			this->PasswordPanel->TabIndex = 23;
			// 
			// PasswordText
			// 
			this->PasswordText->AccessibleName = L"PasswordText";
			this->PasswordText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->PasswordText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PasswordText->Location = System::Drawing::Point(10, 7);
			this->PasswordText->Multiline = true;
			this->PasswordText->Name = L"PasswordText";
			this->PasswordText->PasswordChar = '*';
			this->PasswordText->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->PasswordText->Size = System::Drawing::Size(315, 32);
			this->PasswordText->TabIndex = 0;
			// 
			// NamePanel
			// 
			this->NamePanel->BackColor = System::Drawing::SystemColors::Window;
			this->NamePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->NamePanel->Controls->Add(this->NameText);
			this->NamePanel->Location = System::Drawing::Point(28, 66);
			this->NamePanel->Name = L"NamePanel";
			this->NamePanel->Size = System::Drawing::Size(338, 42);
			this->NamePanel->TabIndex = 21;
			// 
			// NameText
			// 
			this->NameText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->NameText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NameText->Location = System::Drawing::Point(9, 5);
			this->NameText->Multiline = true;
			this->NameText->Name = L"NameText";
			this->NameText->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->NameText->Size = System::Drawing::Size(316, 32);
			this->NameText->TabIndex = 0;
			// 
			// LoginBtn
			// 
			this->LoginBtn->AccessibleName = L"LoginBtn";
			this->LoginBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoginBtn->Location = System::Drawing::Point(124, 213);
			this->LoginBtn->Name = L"LoginBtn";
			this->LoginBtn->Size = System::Drawing::Size(144, 38);
			this->LoginBtn->TabIndex = 18;
			this->LoginBtn->Text = L"Log In";
			this->LoginBtn->UseVisualStyleBackColor = true;
			this->LoginBtn->Click += gcnew System::EventHandler(this, &Login::LoginBtn_Click);
			// 
			// NavToRegisterBtn
			// 
			this->NavToRegisterBtn->AccessibleName = L"NavToRegisterBtn";
			this->NavToRegisterBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NavToRegisterBtn->Location = System::Drawing::Point(69, 264);
			this->NavToRegisterBtn->Name = L"NavToRegisterBtn";
			this->NavToRegisterBtn->Size = System::Drawing::Size(249, 38);
			this->NavToRegisterBtn->TabIndex = 19;
			this->NavToRegisterBtn->Text = L"Dont Have An Account";
			this->NavToRegisterBtn->UseVisualStyleBackColor = true;
			this->NavToRegisterBtn->Click += gcnew System::EventHandler(this, &Login::NavToRegisterBtn_Click);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(409, 424);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->PasswordPanel->ResumeLayout(false);
			this->PasswordPanel->PerformLayout();
			this->NamePanel->ResumeLayout(false);
			this->NamePanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


private: System::Void NavToRegisterBtn_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void LoginBtn_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}
