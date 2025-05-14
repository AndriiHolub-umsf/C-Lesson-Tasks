#pragma once
#include <string>
#include <random>

namespace Lab07 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
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
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ nameBox;
	private: System::Windows::Forms::TextBox^ pswBox;
	protected:

	private: System::Windows::Forms::Button^ loginbtn;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ genpwdbtn;

	protected:

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
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->pswBox = (gcnew System::Windows::Forms::TextBox());
			this->loginbtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->genpwdbtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// nameBox
			// 
			this->nameBox->Location = System::Drawing::Point(76, 53);
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(184, 20);
			this->nameBox->TabIndex = 0;
			// 
			// pswBox
			// 
			this->pswBox->Location = System::Drawing::Point(76, 91);
			this->pswBox->Name = L"pswBox";
			this->pswBox->PasswordChar = '*';
			this->pswBox->Size = System::Drawing::Size(184, 20);
			this->pswBox->TabIndex = 1;
			// 
			// loginbtn
			// 
			this->loginbtn->Location = System::Drawing::Point(168, 128);
			this->loginbtn->Name = L"loginbtn";
			this->loginbtn->Size = System::Drawing::Size(92, 23);
			this->loginbtn->TabIndex = 2;
			this->loginbtn->Text = L"Login";
			this->loginbtn->UseVisualStyleBackColor = true;
			this->loginbtn->Click += gcnew System::EventHandler(this, &LoginForm::loginbtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Name:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 94);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Password:";
			// 
			// genpwdbtn
			// 
			this->genpwdbtn->Location = System::Drawing::Point(168, 158);
			this->genpwdbtn->Name = L"genpwdbtn";
			this->genpwdbtn->Size = System::Drawing::Size(92, 23);
			this->genpwdbtn->TabIndex = 5;
			this->genpwdbtn->Text = L"Gen Password";
			this->genpwdbtn->UseVisualStyleBackColor = true;
			this->genpwdbtn->Click += gcnew System::EventHandler(this, &LoginForm::genpwdbtn_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->genpwdbtn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->loginbtn);
			this->Controls->Add(this->pswBox);
			this->Controls->Add(this->nameBox);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void CheckLogin(String^ login)
	{
		if (login->Length < 8)
			throw gcnew Exception("Логін повинен містити щонайменше 8 символів!");

		if (!System::Text::RegularExpressions::Regex::IsMatch(login, "[A-Z]"))
			throw gcnew Exception("Логін має містити хоча б одну велику літеру!");

		if (!System::Text::RegularExpressions::Regex::IsMatch(login, "[0-9]"))
			throw gcnew Exception("Логін має містити хоча б одну цифру!");

		if (!System::Text::RegularExpressions::Regex::IsMatch(login, "[^a-zA-Z0-9]"))
			throw gcnew Exception("Логін має містити хоча б один спецсимвол!");

		if (!System::Text::RegularExpressions::Regex::IsMatch(login, "^[a-zA-Z0-9\\W]+$"))
			throw gcnew Exception("Логін має містити лише англійські літери та символи!");
	}
	private: void CheckPassword(String^ password)
	{
		if (password->Length < 8)
			throw gcnew Exception("Пароль має бути не менше 8 символів!");

		if (!System::Text::RegularExpressions::Regex::IsMatch(password, "[A-Z]"))
			throw gcnew Exception("Пароль має містити велику літеру!");

		if (!System::Text::RegularExpressions::Regex::IsMatch(password, "[a-z]"))
			throw gcnew Exception("Пароль має містити малу літеру!");

		if (!System::Text::RegularExpressions::Regex::IsMatch(password, "[0-9]"))
			throw gcnew Exception("Пароль має містити цифру!");

		if (!System::Text::RegularExpressions::Regex::IsMatch(password, "[^a-zA-Z0-9]"))
			throw gcnew Exception("Пароль має містити спецсимвол!");
	}

	private: System::Void loginbtn_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ login = nameBox->Text;
		String^ password = pswBox->Text;

		try {
			CheckLogin(login);
			CheckPassword(password);
			MessageBox::Show("Логін та пароль успішно перевірені!", "Успіх", MessageBoxButtons::OK, MessageBoxIcon::Information);
	
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void genpwdbtn_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ gen = GenerateStrongPassword(12);
		MessageBox::Show("Згенерований пароль: " + gen, "Пароль", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}


	private: String^ GenerateStrongPassword(int length) {
		std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*";
		std::random_device rd;
		std::mt19937 gen(rd());

		std::uniform_int_distribution<> dis(0, chars.length() - 1);

		std::string pwd;
		while (true) {
			pwd.clear();
			for (int i = 0; i < length; ++i)
				pwd += chars[dis(gen)];

			String^ temp = gcnew String(pwd.c_str());
			try {
				CheckPassword(temp);
				return temp;
			}
			catch (...)
			{
				continue;
			}
		}
	}
	};
}
