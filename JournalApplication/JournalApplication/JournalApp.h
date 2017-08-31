#ifndef JOURNAL_APP_HEADER_H
#define JOURNAL_APP_HEADER_H

#include <iostream>
#include "SystemManager.h"

using namespace std;


class JournalApp
{
public:
	JournalApp() {}
	~JournalApp() {}

	void Run()
	{
		char option;
		do
		{
			ShowMenu();
			option = GetOption();
			Update(option);

		} while (option != 'e');

	}

private:

	SystemManager _mSysManager;

	char GetOption() const
	{
		char opt = ' ';
		cin >> opt;
		return opt;
	}

	void Update(char option)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int k;

		k = 15; //WHITE
		SetConsoleTextAttribute(hConsole, k);
		string s;
		char* title;
		char opt;
		int id;
		switch (option)
		{
		case 'a':
			cout << "Create a Title for your journal:" << endl;
			cin.ignore();
			getline(cin, s);
			title = new char[s.size() + 1];
			memcpy(title, s.c_str(), s.size() + 1);
			_mSysManager.CreateNewJournal(title);
			break;
		case 'r':
			cout << "Type the number of the Journal that you want to remove:" << endl;
			cin >> id;
			title = _mSysManager.GetJournalTitle(id);
			if (strcmp(title, " ") != 0)
			{
				do
				{
					cout << "Do you want to remove:";
					k = 10; 
					SetConsoleTextAttribute(hConsole, k); 
					cout <<_mSysManager.GetJournalTitle(id) << endl;
					k = 15;
					SetConsoleTextAttribute(hConsole, k);
					cout << "Type: (y) yes  (n) no" << endl;
					cin >> opt;
				} while (opt != 'y' && opt != 'n');

				if (opt == 'y')
				{
					_mSysManager.DeleteJournal(_mSysManager.GetJournalTitle(id));
				}
			}
			else
			{
				cout << "This Journal is not on the list." << endl;
			}
			
			
			break;
		case 'v':
			cout << "Type the number of the journal that you want to visualize:" << endl;
			cin >> id;
			title = _mSysManager.GetJournalTitle(id);
			_mSysManager.AccessJournal(title);
			break;
		case 'e':
			cout << "BYE!" << endl;
		default:
			break;
		}
	}


	void ShowMenu()
	{
		_mSysManager.PrintJournals();
		cout << endl;
		cout << "CHOOSE AN OPTION:" << endl;
		cout << endl;
		cout << "(a) Add a Journal" << endl;
		cout << "(r) Remove a Journal" << endl;
		cout << "(v) View a Journal" << endl;
		cout << "(e) EXIT" << endl;
	}
};






#endif // !MENU_HEADER_H

