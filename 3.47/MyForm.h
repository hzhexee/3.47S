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

	string decipherPattern(const string& binarySequence) {
		string result; // результат (строка)
		int count = 0; // счетчик нулей

		for (char i : binarySequence) { // пробегаем по всем символам циклом
			if (i == '1') { // если встретили '1', добавляем соответствующую букву
				result += static_cast<char>('a' + count); // статик_каст удостоверяет то, что переменная будет типа char
				// 'a' + count - прибавляем к ascii коду буквы a счетчкик
				count = 0; // обнуляем счетчик
			}
			else {
				count++; // если встретили '0', увеличиваем счетчик
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
			this->button1->Location = System::Drawing::Point(15, 73);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(151, 49);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Дешифровать последовательность";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(617, 394);
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
		String^ inputString = textBox1->Text;
		string nativeInput = marshal_as<string>(inputString);
		string result = decipherPattern(nativeInput);
		String^ convResult = gcnew String(result.c_str());

		String^ resultMessage = "Результат дешифровки: " + convResult;
		//resultMessage += "Результат дешифровки: " + convResult;

		MessageBox::Show(resultMessage, "Результат дешифровки", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	};
}
