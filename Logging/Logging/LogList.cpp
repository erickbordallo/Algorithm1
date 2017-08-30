#include "LogList.h"


LogList::LogList(int bufferSize)
{
	LogBuffer newBuffer = LogBuffer(bufferSize);
	_mPartition.Insert(newBuffer);
}


void LogList::CreatePartition(int bufferSize)
{
	LogBuffer newBuffer = LogBuffer(bufferSize);
	_mPartition.Insert(newBuffer);
}

void LogList::AddData(char* data)
{
	if (!_mPartition.last->_mData.AddLog(data))
	{
		CreatePartition(5);
		_mPartition.last->_mData.AddLog(data);
	}
}


void LogList::PrintLogs()
{
	Node<LogBuffer>* current = nullptr;
	Node<LogBuffer>* previous = nullptr;

	current = _mPartition.first;

	if (current == nullptr)
	{
		cout << "There isn't any logs to print." << endl;
		return;
	}
	int index = 0;

	while (current != nullptr)
	{
		for (int i = 0; i < current->_mData.PeekSize(); i++)
		{
			index++;
			cout << index << ") " << current->_mData.PeekTimeStamp(i) << " - " << current->_mData.PeekData(i) << endl;
			cout << endl;
		}

		previous = current;
		current = previous->_mNextPtr;
	}

}

void LogList::SaveToFile()
{
	ofstream logFile;

	Node<LogBuffer>* current = nullptr;
	Node<LogBuffer>* previous = nullptr;

	current = _mPartition.first;


	try
	{
		logFile.open("Log.txt");

		if (current == nullptr)
		{
			logFile << "EMPTY LOG ERROR." << endl;
			return;
		}
		
		int index = 0;

		while (current != nullptr)
		{
			for (int i = 0; i < current->_mData.PeekSize(); i++)
			{
				index++;
				logFile << index << ") " << current->_mData.PeekTimeStamp(i) << " - " << current->_mData.PeekData(i) << endl;
				logFile << endl;
			}

			previous = current;
			current = previous->_mNextPtr;
		}
		
		logFile.close();
	}
	catch (exception ex)
	{
		cout << "Exception: " << ex.what();
	}
	
}