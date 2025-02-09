#pragma once
#include <iostream>
#include "clsInputValidate.h";
#include "clsClientListScreen.h";
#include "clsFindClientScreen.h";
#include "clsAddNewClientScreen.h";
#include "clsDeleteClientScreen.h";
#include "clsTransactionsScreen.h";
#include "clsUpdateCLientScreen.h";
#include "clsManageUsersScreen.h";
#include "clsShowRegistersLogScreen.h";
#include "clsCurrencyExchangeMainScreen.h";
#include "clsScreen.h";
#include <iomanip>
#include "Global.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eRegistersLog = 8, eCurriencesList = 9, eExit = 10
    };
    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
        short Choice = clsInputValidate::ReadShortNumber();
        return Choice;
    }
    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();

    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::AddNewClient();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::DeleteClient();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowRegistersLog()
    {
        clsShowRegistersLogScreen::ShowLoginRegisterScreen();
    }
    static void _ShowCurrenciesList()
    {
        clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }
    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            break;
        case enMainMenueOptions::eRegistersLog:
            system("cls");
            _ShowRegistersLog();
            break;
        case enMainMenueOptions::eCurriencesList:
            system("cls");
            _ShowCurrenciesList();
            break;
        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }


    }
public:
	static void ShowMainMenu()
	{

        system("cls");
        _DrawScreenHeader("\t\tMain Screen");
         
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Show Register Logs.\n";
        cout << setw(37) << left << "" << "\t[9] Curriences List.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}
};

