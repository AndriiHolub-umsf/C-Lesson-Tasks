#pragma once

namespace Lab07 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 108);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Calcualte Func";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(374, 90);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(387, 181);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		// Function to calculate the function value
		double CalculateFunction(double x) {

			double y = 0.0;
			try {
				if (x >= 2) {
					double denom = 12.3 * x * x - 9 * x + 1.5;
					if (denom == 0) 
						throw gcnew DivideByZeroException("Ділення на нуль!");
					y = 1.0 / denom;
				}
				else {
					double underRoot = 4 - x * x;
					if (underRoot < 0) 
						throw gcnew Exception("Підкореневий вираз менше нуля!");
					y = Math::Sqrt(underRoot);
				}
				return y;
			}
			catch (Exception^ ex) {
				return -1;
			}
		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		MessageBox::Show("Результат для 3.7: " + CalculateFunction(3.7).ToString(), "Результат", MessageBoxButtons::OK, MessageBoxIcon::Information);
		MessageBox::Show("Результат для 2: " + CalculateFunction(2).ToString(), "Результат", MessageBoxButtons::OK, MessageBoxIcon::Information);
		MessageBox::Show("Результат для -3.5: " + CalculateFunction(-3.5).ToString(), "Результат", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	};
}
