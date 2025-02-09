#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFalid = false;
		string Username, Password;
		int FailedCounts = 0;

		do
		{
			if (LoginFalid)
			{
				cout << "\nInvalid Username/Password!\n\n";
				FailedCounts++;
			}
			if (FailedCounts == 3)
			{
				cout << "\nYour are Locked after 3 faild trails \n\n";
				return false;
			}
			cout << "Enter Username: ";
			cin >> Username;

			cout << "Enter Password: ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);
			LoginFalid = CurrentUser.IsEmpty();
		} while (LoginFalid);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenu();
	};

public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t	Login Screen");
		_Login();
	}
};

