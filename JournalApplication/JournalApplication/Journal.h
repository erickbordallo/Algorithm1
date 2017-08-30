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
		cout << endl;
		cout << "TITLE: "<<_mTitle << endl;
		cout << endl;

		for (list<Entry>::const_iterator iterator = _mEntries.begin(), end = _mEntries.end(); iterator != end; ++iterator)
		{
			if (iterator->_mID >= firstEntry && iterator->_mID <= lastEntry)
			{
				cout << iterator->_mID << "             " << iterator->_mContent << "             " << iterator->_mTimeStamp << endl;
			}
		}
	}
	
	list<Entry> _mEntries;
	char* _mTitle;
	
};






#endif // !JOURNAL_HEADER_H


