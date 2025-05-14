#include "LoginForm.h"
using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(cli::array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Lab07::LoginForm^ loginForm = gcnew Lab07::LoginForm();
	Application::Run(loginForm);
	return 0;
}