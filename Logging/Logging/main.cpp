
#include "LogList.h"

int main()
{
	LogList myLogs = LogList(5);
	myLogs.AddData("Hello World1");
	myLogs.AddData("Hello World2");
	myLogs.AddData("Hello World3");
	myLogs.AddData("Hello World4");
	myLogs.AddData("Hello World5");
	myLogs.AddData("Hello World6");
	myLogs.AddData("Hello World7");
	myLogs.AddData("Hello World8");


	myLogs.PrintLogs();

	cout << "Saving..." << endl;
	myLogs.SaveToFile();

	cout << endl;

	cout << "Done." << endl;

	system("pause");
	return 0;
}