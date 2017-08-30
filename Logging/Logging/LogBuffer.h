#ifndef LOG_BUFFER_HEADER_H
#define LOG_BUFFER_HEADER_H

#include "Log.h"
#include "Queue.h"


class LogBuffer
{
public:

	~LogBuffer() {}

	bool AddLog(char* data);//Will return true if adds and false if dont have space.
	LogBuffer(int maxSize) : _mLogBuffer(maxSize), _mMaximumSize(maxSize) {}

	const char* PeekTimeStamp(int index);

	char* PeekData(int index);

	int PeekSize() { return _mLogBuffer.GetSize(); }

protected:
	


private:
	Queue<Log> _mLogBuffer;
	int _mMaximumSize;

};






#endif // !LOGBUFFER_HEADER_h

