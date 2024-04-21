#pragma once
#include <iostream>
#include <string>
#include <msclr/marshal.h>
#include <msclr/marshal_windows.h>
#include <msclr/marshal_cppstd.h>

namespace My347 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace msclr;
	using namespace msclr::interop;

	std::string findOccurrences(const std::string& S, const std::string& T) {
		int n = S.length();
		int m = T.length();
		std::string result;

		for (int i = 0; i <= n - m; ++i) {
			bool found = true;
			for (int j = 0; j < m; ++j) {
				if (S[i + j] != T[j]) {
					found = false;
					break;
				}
			}

			if (found) {
				result += "Pattern found at index " + std::to_string(i + 1) + "\n";
			}
		}

		return result;
	}

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(213, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите бинарную последовательность:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(15, 36);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(452, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 184);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 49);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Дешифровать последовательность";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(15, 94);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(617, 394);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    string stringT = marshal_as<string>(textBox1->Text);
    string stringS = marshal_as<string>(textBox2->Text);
    string result = findOccurrences(stringS, stringT);
    String^ convResult = gcnew String(result.c_str());
    String^ resultMessage = "Результат дешифровки: " + convResult;
    //resultMessage += "Результат дешифровки: " + convResult;

    MessageBox::Show(resultMessage, "Результат дешифровки", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
	};
}
