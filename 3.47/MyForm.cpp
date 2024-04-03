#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array<String^>^ args) {
	system("chcp 1251");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	My347::MyForm form;
	Application::Run(% form);
}
