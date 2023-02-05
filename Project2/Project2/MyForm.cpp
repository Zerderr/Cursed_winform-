#include "MyForm.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include "coolfunctions.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main() {
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::MyForm form;
	Application::Run(% form);

	setlocale(LC_ALL, "Russian");
	


}