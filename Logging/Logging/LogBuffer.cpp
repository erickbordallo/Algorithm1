#include "LogBuffer.h"

bool LogBuffer::AddLog(char* data)
{
	Log newLog = Log(data);

	if (_mLogBuffer.GetSize() < _mMaximumSize)
	{
		_mLogBuffer.Enqueue(newLog);
		return true;
	}
	return false;
}

const char* LogBuffer::PeekTimeStamp(int index)
{
	return _mLogBuffer[index].GetTS();
}


char* LogBuffer::PeekData(int index)
{
	return _mLogBuffer[index].GetLog();
}
