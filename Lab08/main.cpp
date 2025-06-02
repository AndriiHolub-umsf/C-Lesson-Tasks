#include "MainForm.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(cli::array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab08::MainForm^ mainForm = gcnew Lab08::MainForm();
	Application::Run(mainForm);
	return 0;
}