#ifndef LOG_LIST_HEADER_H
#define LOG_LIST_HEADER_H
#include <fstream>
#include <iostream>
//Libraries
#include "LogBuffer.h"
#include "LinkedList.h"

class LogList
{
public:

	//Ctors-------------------------------------
	LogList(int bufferSize);
	//Dtors-------------------------------------
	~LogList();

	//Functions

	void Log(char* data);
	void PrintLogs();
	

private:
	LinkedList<LogBuffer> _mPartition;

	//Private functions
	void CreatePartition(int bufferSize);
};







#endif // !LOG_LIST_HEADER_H

