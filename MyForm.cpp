#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Reflection;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

    Font_To_Uint_8t::MyForm form;
	Application::Run(% form);
	return 0;
}