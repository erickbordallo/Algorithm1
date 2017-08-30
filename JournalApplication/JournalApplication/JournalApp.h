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
		string s;
		char* title;
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
			cout << "Type the title of the journal that you want to remove:" << endl;
			cin.ignore();
			getline(cin, s);
			title = new char[s.size() + 1];
			memcpy(title, s.c_str(), s.size() + 1);
			_mSysManager.DeleteJournal(title);
			break;
		case 'v':
			cout << "Type the title of the journal that you want to visualize:" << endl;
			cin.ignore();
			getline(cin, s);
			title = new char[s.size() + 1];
			memcpy(title, s.c_str(), s.size() + 1);
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

