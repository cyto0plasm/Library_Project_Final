#pragma once
#include "../Controllers/userController.h"
#include "../Models/userModel.h"
#include "../Forms/Login.h"
#include "../Forms/Home.h"

namespace LaibraryProject {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Register
	/// </summary>
	public ref class Register : public System::Windows::Forms::Form
	{
	public:
		Register(void)
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
		~Register()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ Container;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ PasswordConfirsmLabel;
	private: System::Windows::Forms::Panel^ PasswordConfirmPanel;
	private: System::Windows::Forms::TextBox^ PasswordConfirmText;
	private: System::Windows::Forms::Label^ PasswordLabel;
	private: System::Windows::Forms::Label^ NameLabel;
	private: System::Windows::Forms::Panel^ PasswordPanel;
	private: System::Windows::Forms::TextBox^ PasswordText;
	private: System::Windows::Forms::Panel^ NamePanel;
	private: System::Windows::Forms::TextBox^ NameText;
	private: System::Windows::Forms::Button^ NavToLoginBtn;
	private: System::Windows::Forms::Button^ RegisterBtn;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ closeBtn;
















	protected:


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Register::typeid));
			this->Container = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->PasswordConfirsmLabel = (gcnew System::Windows::Forms::Label());
			this->PasswordConfirmPanel = (gcnew System::Windows::Forms::Panel());
			this->PasswordConfirmText = (gcnew System::Windows::Forms::TextBox());
			this->PasswordLabel = (gcnew System::Windows::Forms::Label());
			this->NameLabel = (gcnew System::Windows::Forms::Label());
			this->PasswordPanel = (gcnew System::Windows::Forms::Panel());
			this->PasswordText = (gcnew System::Windows::Forms::TextBox());
			this->NamePanel = (gcnew System::Windows::Forms::Panel());
			this->NameText = (gcnew System::Windows::Forms::TextBox());
			this->NavToLoginBtn = (gcnew System::Windows::Forms::Button());
			this->RegisterBtn = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->closeBtn = (gcnew System::Windows::Forms::Button());
			this->Container->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->PasswordConfirmPanel->SuspendLayout();
			this->PasswordPanel->SuspendLayout();
			this->NamePanel->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Container
			// 
			this->Container->Controls->Add(this->panel2);
			this->Container->Controls->Add(this->panel1);
			this->Container->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Container->Location = System::Drawing::Point(0, 0);
			this->Container->Name = L"Container";
			this->Container->Size = System::Drawing::Size(391, 530);
			this->Container->TabIndex = 0;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 90);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(391, 440);
			this->panel2->TabIndex = 15;
			// 
			// panel3
			// 
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->PasswordConfirsmLabel);
			this->panel3->Controls->Add(this->PasswordConfirmPanel);
			this->panel3->Controls->Add(this->PasswordLabel);
			this->panel3->Controls->Add(this->NameLabel);
			this->panel3->Controls->Add(this->PasswordPanel);
			this->panel3->Controls->Add(this->NamePanel);
			this->panel3->Controls->Add(this->NavToLoginBtn);
			this->panel3->Controls->Add(this->RegisterBtn);
			this->panel3->Location = System::Drawing::Point(12, 6);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(367, 422);
			this->panel3->TabIndex = 0;
			// 
			// PasswordConfirsmLabel
			// 
			this->PasswordConfirsmLabel->AccessibleName = L"PasswordConfirsmLabel";
			this->PasswordConfirsmLabel->AutoSize = true;
			this->PasswordConfirsmLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PasswordConfirsmLabel->Location = System::Drawing::Point(92, 209);
			this->PasswordConfirsmLabel->Name = L"PasswordConfirsmLabel";
			this->PasswordConfirsmLabel->Size = System::Drawing::Size(193, 25);
			this->PasswordConfirsmLabel->TabIndex = 14;
			this->PasswordConfirsmLabel->Text = L"Confirm Password ";
			// 
			// PasswordConfirmPanel
			// 
			this->PasswordConfirmPanel->BackColor = System::Drawing::SystemColors::Window;
			this->PasswordConfirmPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PasswordConfirmPanel->Controls->Add(this->PasswordConfirmText);
			this->PasswordConfirmPanel->Location = System::Drawing::Point(13, 244);
			this->PasswordConfirmPanel->Name = L"PasswordConfirmPanel";
			this->PasswordConfirmPanel->Size = System::Drawing::Size(338, 45);
			this->PasswordConfirmPanel->TabIndex = 15;
			// 
			// PasswordConfirmText
			// 
			this->PasswordConfirmText->AccessibleName = L"PasswordConfirmText";
			this->PasswordConfirmText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->PasswordConfirmText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PasswordConfirmText->Location = System::Drawing::Point(13, 6);
			this->PasswordConfirmText->Multiline = true;
			this->PasswordConfirmText->Name = L"PasswordConfirmText";
			this->PasswordConfirmText->PasswordChar = '*';
			this->PasswordConfirmText->Size = System::Drawing::Size(315, 32);
			this->PasswordConfirmText->TabIndex = 0;
			// 
			// PasswordLabel
			// 
			this->PasswordLabel->AccessibleName = L"PasswordLabel";
			this->PasswordLabel->AutoSize = true;
			this->PasswordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PasswordLabel->Location = System::Drawing::Point(134, 115);
			this->PasswordLabel->Name = L"PasswordLabel";
			this->PasswordLabel->Size = System::Drawing::Size(106, 25);
			this->PasswordLabel->TabIndex = 12;
			this->PasswordLabel->Text = L"Password";
			// 
			// NameLabel
			// 
			this->NameLabel->AccessibleName = L"NameLabel";
			this->NameLabel->AutoSize = true;
			this->NameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NameLabel->Location = System::Drawing::Point(129, 21);
			this->NameLabel->Name = L"NameLabel";
			this->NameLabel->Size = System::Drawing::Size(110, 25);
			this->NameLabel->TabIndex = 10;
			this->NameLabel->Text = L"Username";
			// 
			// PasswordPanel
			// 
			this->PasswordPanel->BackColor = System::Drawing::SystemColors::Window;
			this->PasswordPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PasswordPanel->Controls->Add(this->PasswordText);
			this->PasswordPanel->Location = System::Drawing::Point(13, 151);
			this->PasswordPanel->Name = L"PasswordPanel";
			this->PasswordPanel->Size = System::Drawing::Size(338, 45);
			this->PasswordPanel->TabIndex = 13;
			// 
			// PasswordText
			// 
			this->PasswordText->AccessibleName = L"PasswordText";
			this->PasswordText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->PasswordText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PasswordText->Location = System::Drawing::Point(11, 7);
			this->PasswordText->Multiline = true;
			this->PasswordText->Name = L"PasswordText";
			this->PasswordText->PasswordChar = '*';
			this->PasswordText->Size = System::Drawing::Size(315, 32);
			this->PasswordText->TabIndex = 0;
			// 
			// NamePanel
			// 
			this->NamePanel->BackColor = System::Drawing::SystemColors::Window;
			this->NamePanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->NamePanel->Controls->Add(this->NameText);
			this->NamePanel->Location = System::Drawing::Point(13, 59);
			this->NamePanel->Name = L"NamePanel";
			this->NamePanel->Size = System::Drawing::Size(338, 45);
			this->NamePanel->TabIndex = 11;
			// 
			// NameText
			// 
			this->NameText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->NameText->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NameText->Location = System::Drawing::Point(12, 7);
			this->NameText->Multiline = true;
			this->NameText->Name = L"NameText";
			this->NameText->Size = System::Drawing::Size(315, 32);
			this->NameText->TabIndex = 0;
			// 
			// NavToLoginBtn
			// 
			this->NavToLoginBtn->AccessibleName = L"RegisterBtn";
			this->NavToLoginBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->NavToLoginBtn->Location = System::Drawing::Point(56, 348);
			this->NavToLoginBtn->Name = L"NavToLoginBtn";
			this->NavToLoginBtn->Size = System::Drawing::Size(244, 38);
			this->NavToLoginBtn->TabIndex = 8;
			this->NavToLoginBtn->Text = L"I Have An Account";
			this->NavToLoginBtn->UseVisualStyleBackColor = true;
			this->NavToLoginBtn->Click += gcnew System::EventHandler(this, &Register::NavToLoginBtn_Click);
			// 
			// RegisterBtn
			// 
			this->RegisterBtn->AccessibleName = L"RegisterBtn";
			this->RegisterBtn->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegisterBtn->Location = System::Drawing::Point(97, 304);
			this->RegisterBtn->Name = L"RegisterBtn";
			this->RegisterBtn->Size = System::Drawing::Size(169, 38);
			this->RegisterBtn->TabIndex = 9;
			this->RegisterBtn->Text = L"Create Account";
			this->RegisterBtn->UseVisualStyleBackColor = true;
			this->RegisterBtn->Click += gcnew System::EventHandler(this, &Register::RegisterBtn_Click);
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
			this->panel1->Size = System::Drawing::Size(391, 90);
			this->panel1->TabIndex = 14;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(9, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(126, 37);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Register";
			// 
			// closeBtn
			// 
			this->closeBtn->AccessibleName = L"closeBtn";
			this->closeBtn->FlatAppearance->BorderSize = 0;
			this->closeBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->closeBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeBtn.Image")));
			this->closeBtn->Location = System::Drawing::Point(303, 11);
			this->closeBtn->Name = L"closeBtn";
			this->closeBtn->Size = System::Drawing::Size(75, 65);
			this->closeBtn->TabIndex = 12;
			this->closeBtn->UseVisualStyleBackColor = true;
			this->closeBtn->Click += gcnew System::EventHandler(this, &Register::closeBtn_Click);
			// 
			// Register
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(391, 530);
			this->Controls->Add(this->Container);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Register";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Register";
			this->Container->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->PasswordConfirmPanel->ResumeLayout(false);
			this->PasswordConfirmPanel->PerformLayout();
			this->PasswordPanel->ResumeLayout(false);
			this->PasswordPanel->PerformLayout();
			this->NamePanel->ResumeLayout(false);
			this->NamePanel->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		UserModel^ user;  // This is fine as a member variable

private: System::Void RegisterBtn_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void NavToLoginBtn_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void closeBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
};
}
