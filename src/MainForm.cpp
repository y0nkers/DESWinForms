#include "../MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[System::STAThread]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DESWinForms::MainForm form;
	Application::Run(% form);
}