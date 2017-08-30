#ifndef ENTRY_HEADER_H
#define ENTRY_HEADER_H


#include <iostream>
#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string

using namespace std::chrono;

class Entry
{
public:
	Entry() {}

	Entry(int id, char* content) : _mID(id), _mContent(content)
	{
		currentDateTime();
	}

	~Entry();

	void currentDateTime() 
	{
		time_t result = time(NULL);
		ctime_s(_mTimeStamp, sizeof _mTimeStamp, &result);
	}

	char* _mContent;
	int _mID;
	char _mTimeStamp [26];

};



Entry::~Entry()
{
}




#endif // !ENTRY_HEADER_H

