#include <iostream>
#include "clsBankClient.h";
#include "clsPerson.h";
#include "clsLoginScreen.h";
#include "clsUtil.h";
#include "clsInputValidate.h";
#include "clsMainScreen.h";
#include <iomanip>

using namespace std;

int main()
{
    //clsMainScreen::ShowMainMenu();
	while(true)
		clsLoginScreen::ShowLoginScreen();

	system("pause>0");
	return 0;
}
