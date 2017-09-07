
#include "LogList.h"
void LogTest();

int main()
{
	LogTest();

	system("pause");
	return 0;
}


void LogTest()
{
	//Create Log with buffer size of 5 elements
	LogList myLogs = LogList(5);

	myLogs.Log("Hello World1");
	myLogs.Log("Hello World2");
	myLogs.Log("Hello World3");
	myLogs.Log("Hello World4");
	myLogs.Log("Hello World5");

	//Filled the entire buffer, the log expands by itself.
	myLogs.Log("Hello World6");
	myLogs.Log("Hello World7");
	myLogs.Log("Hello World8");

	//Just to see all the logs on screen.
	myLogs.PrintLogs();
}