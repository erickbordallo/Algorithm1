#ifndef JOURNAL_HEADER_H
#define JOURNAL_HEADER_H


#include <iostream>
#include <list>
#include "Entry.h"


using namespace std;

class Journal
{
public:
	Journal(char* title) : _mTitle(title) {}
	~Journal() {}
	

	void AddEntry(char* entry)
	{
		Entry newEntry = Entry(_mEntries.size() + 1, entry);
		_mEntries.push_back(newEntry);
	}


	void RemoveEntry(int id)
	{
		for (list<Entry>:: iterator iterator = _mEntries.begin(), end = _mEntries.end(); iterator != end; ++iterator)
		{
			if (iterator->_mID == id)
			{
				_mEntries.erase(iterator);
				break;
			}
		}

		int i = 0;
		for (list<Entry>::iterator iterator = _mEntries.begin(), end = _mEntries.end(); iterator != end; ++iterator)
		{
			iterator->_mID = i + 1;
			i++;
		}

	}

	void PrintJournalInRange(int firstEntry, int lastEntry)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int k;
		k = 15; //WHITE
		SetConsoleTextAttribute(hConsole, k);

		cout << endl;
		cout << "TITLE: ";
		k = 10;
		SetConsoleTextAttribute(hConsole, k);
		cout<< _mTitle << endl;
		cout << endl;
		k = 10;

		for (list<Entry>::const_iterator iterator = _mEntries.begin(), end = _mEntries.end(); iterator != end; ++iterator)
		{
			if (iterator->_mID >= firstEntry && iterator->_mID <= lastEntry)
			{
				k = 10;
				SetConsoleTextAttribute(hConsole, k);
				cout << iterator->_mID << " - ";
				cout << iterator->_mTimeStamp << " | ";
				k = 11;
				SetConsoleTextAttribute(hConsole, k);
				cout << iterator->_mContent << endl;
			}
		}
	}
	
	list<Entry> _mEntries;
	char* _mTitle;
	
};






#endif // !JOURNAL_HEADER_H


