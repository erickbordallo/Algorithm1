#ifndef SYSTEM_MANAGER_HEADER_H
#define SYSTEM_MANAGER_HEADER_H


#include <iostream>
#include <list>
#include <string.h>

#include "JournalView.h"


using namespace std;

class SystemManager
{
public:
	SystemManager()
	{
		_mPagination = JournalView(5);
	}

	~SystemManager() {}

	void CreateNewJournal(char* title)
	{
		bool journalExist = false;
		if (_mJournals.size() == 0)
		{
			Journal journal = Journal(title);
			_mJournals.push_back(journal);
			return;
		}

		for (list<Journal>::iterator iterator = _mJournals.begin(), end = _mJournals.end(); iterator != end; ++iterator)
		{
			if (strcmp(iterator->_mTitle, title) == 0)
			{
				cout << "This journal already exist." << endl;
				journalExist = true;
				break;
			}	
		}
		if (journalExist)
		{
			return;
		}
		else
		{
			Journal journal = Journal(title);
			_mJournals.push_back(journal);
		}

	}

	void DeleteJournal(char* title)
	{
		for (list<Journal>::iterator iterator = _mJournals.begin(), end = _mJournals.end(); iterator != end; ++iterator)
		{
			if (strcmp(iterator->_mTitle, title) == 0)
			{
				_mJournals.erase(iterator);
				break;
			}
		}
	}

	void AccessJournal(char* title)
	{
		for (list<Journal>::iterator iterator = _mJournals.begin(), end = _mJournals.end(); iterator != end; ++iterator)
		{
			if (strcmp(iterator->_mTitle, title) == 0)
			{
				_mPagination.ShowEntries(*iterator);
				break;
			}
		}
	}

	void PrintJournals()
	{
		cout << "YOUR JOURNALS--------------------------------------------" << endl;
		cout << endl;

		for (list<Journal>::const_iterator iterator = _mJournals.begin(), end = _mJournals.end(); iterator != end; ++iterator)
		{
			cout << iterator->_mTitle << endl;;
		}
		cout << endl;
		cout << "----------------------------------------------------------" << endl;
	}
	
private:
	list<Journal> _mJournals;
	JournalView _mPagination;

};




#endif // !SYSTEM_MANAGER_HEADER_H