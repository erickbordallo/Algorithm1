#ifndef MYLOG_HEADER_H
#define MYLOG_HEADER_H

#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <sstream> // stringstream
#include <iomanip> // put_time
#include <string>  // string

class Log
{
public:
	Log() { _mData = "Nothing in this log."; currentDateTime(); }

	Log(char* data) : _mData(data)
	{
		currentDateTime();
	}


	char* GetLog() const { return _mData; }
	const char* GetTS() const 
	{ 
		const char* tempString = _mTimeStamp;
		return tempString; 
	
	}

	~Log() {}

private:
	char* _mData;
	char _mTimeStamp [26];


	//Private Function
	void currentDateTime()
	{
		time_t result = time(NULL);
		ctime_s(_mTimeStamp, sizeof _mTimeStamp, &result);
	}


};






#endif // !MYLOG_HEADER_H

