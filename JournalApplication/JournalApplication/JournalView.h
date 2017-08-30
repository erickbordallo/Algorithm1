#ifndef JOURNAL_VIEW_HEADER_H
#define JOURNAL_VIEW_HEADER_H


#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include "Journal.h"

using namespace std;

class JournalView
{
public:
	//CTOR, DTOR-------------------------------------------------------------
	JournalView(int maxElementsPerPage) : _mMaxElements(maxElementsPerPage)
	{
		_mCurrentPage = 1;
		_mLastPage = 1;
	}

	JournalView() {}
	~JournalView() {}
	//-----------------------------------------------------------------------


	//Show the entries of a Journal using Pagination Until Exit.------------
	void ShowEntries(Journal& journal)
	{
		char option = ' ';
		
		int firstEntryId;
		int lastEntryId;
		do
		{
			
			_mLastPage = (int)ceilf((float)journal._mEntries.size() / (float)_mMaxElements);
			firstEntryId = (_mMaxElements * (_mCurrentPage - 1)) + 1;

			lastEntryId = (firstEntryId + (_mMaxElements - 1));

			journal.PrintJournalInRange(firstEntryId, lastEntryId);

			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << "(1) FIRST PAGE----------(2) PREVIOUS PAGE----------(3) NEXT PAGE----------(4) LAST PAGE" << endl;
			cout << "---------------------------------------------------------------------------------------" << endl;
			cout << "(a) Add Entry" << endl;
			cout << "(r) Remove Entry" << endl;
			cout << "(s) Save as .txt" << endl;
			cout << "(b) Back to Journals" << endl;
			option = GetOption();
			Update(option, journal);

		} while (option != 'b');
		
	}
	//-----------------------------------------------------------------------
	
private:

	int _mMaxElements;
	int _mCurrentPage;
	int _mLastPage;


	void GoToNextPage()
	{
		if (_mCurrentPage != _mLastPage)
		{
			_mCurrentPage++;
		}
		else
		{
			_mCurrentPage = 1;
		}
	}

	void GoToPreviousPage()
	{
		if (_mCurrentPage > 1)
		{
			_mCurrentPage--;
		}
		else
		{
			_mCurrentPage = _mLastPage;
		}
	}

	void GoToFirstPage() { _mCurrentPage = 1; }

	void GoToLastPage() { _mCurrentPage = _mLastPage; }

	char GetOption()
	{
		char opt = ' ';
		cin >> opt;
		return opt;
	}

	void Update(char option, Journal& journal)
	{
		string s;
		char* phrase;
		int id = 0;
		switch (option)
		{
		case '1':
			GoToFirstPage();
			break;
		case '2':
			GoToPreviousPage();
			break;
		case '3':
			GoToNextPage();
			break;
		case '4':
			GoToLastPage();
			break;
		case 'a':

			cout << "Type the entry for your journal:" << endl;
			cin.ignore();
			getline(cin, s);
			phrase = new char[s.size() + 1];
			memcpy(phrase, s.c_str(), s.size() + 1);
			journal.AddEntry(phrase);
			
			break;
		case 'r':
			cout << "Enter the iD that you want to remove:" << endl;
			cin >> id;
			journal.RemoveEntry(id);
			break;
		case 's':
			SaveAsTXT(journal);
			break;
		default:
			cout << "Invalid Option." << endl;
			break;
		}
	}


	void SaveAsTXT(Journal& journal)
	{
		cout << "Saving..." << endl;
		char* extension = ".txt";
		char fullPath[50] = "";
		
		strcat_s(fullPath, 50, journal._mTitle);
		strcat_s(fullPath, 50, extension);

		ofstream txtFile(fullPath);
		
		txtFile << "TITLE: " << journal._mTitle << endl;
		txtFile << endl;
		txtFile << endl;

		for (list<Entry>::const_iterator iterator = journal._mEntries.begin(), end = journal._mEntries.end(); iterator != end; ++iterator)
		{
			txtFile << iterator->_mID << ")  " << iterator->_mContent << "      DATE: " << iterator->_mTimeStamp << endl;
		}

		txtFile.close();

		cout << "Journal saved." << endl;
	}



};






#endif // !JOURNAL_VIEW_HEADER_H


