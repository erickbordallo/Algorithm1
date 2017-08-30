#ifndef QUEUE_HEADER_H
#define QUEUE_HEADER_H
#include <iostream>

using namespace std;

template<typename T>

class Queue
{
public:

	Queue(int maxSize) : _mMaxSize(maxSize)
	{
		_mArray = new T[_mMaxSize];
		_mHead = 0;
		_mTail = 0;
		_mSize = 0;
	};



	~Queue() {}

	T& operator[](int index) { return _mArray[index]; }

	int GetSize() { return _mSize; }

	int GetMaxSize() { return _mMaxSize; }

	void Enqueue(T element)
	{
		try
		{
			if (_mSize == _mMaxSize)
			{
				Expand();
				
			}
			_mArray[_mTail] = element;
			_mTail++;
				
			_mSize++;
		}
		catch (exception ex)
		{
			cout << "Exception: " << ex.what();
		}

	}


	T Dequeue()
	{
		T element;
		try
		{
			if (_mSize == 0)
			{
				throw "Your queue is empty.";
			}
			element = _mArray[_mHead];

			if (_mHead == _mMaxSize - 1)
			{
				_mHead = 0;
			}
			else
			{
				_mHead++;
			}

			_mSize--;

			return element;
		}
		catch (char* ex)
		{
			std::cout << "Exception: " << ex;
		}
		

	}


	T Peek()
	{
		if (!isEmpty())
		{
			return _mArray[_mHead];
		}
	}




	bool isEmpty() const
	{
		if (_mSize == 0)
		{
			return true;
		}
		return false;
	}



	bool isFull() const
	{
		if (_mSize == _mMaxSize)
		{
			return true;
		}

		return false;
	}


	void Clear()
	{
		if (!isEmpty())
		{
			_mHead = 0;
			_mTail = 0;
			_mSize = 0;
		}
		
	}



	void PrintElements()
	{
		if (isEmpty())
		{
			cout << "Your Queue is Empty." << endl;
		}
		else
		{
			for (int i = 0; i < _mSize; ++i)
			{
				int index = (i + _mHead) % (_mSize + _mHead);
				cout << _mArray[index] << " ";
			}
		}

		cout << endl;
	}



	void Expand()
	{
		_mMaxSize += _mMaxSize;
		T *tempArray = new T[_mMaxSize];


		for (int i = 0; i < _mSize; ++i)
		{
			int index = (i + _mHead) % (_mSize + _mHead);
			tempArray[i] = _mArray[index];
		}

		_mArray = tempArray;
		_mHead = 0;

		tempArray = nullptr;

		delete tempArray;
	}

	

private:
	T* _mArray;
	int _mHead;
	int _mTail;
	int _mSize;
	int _mMaxSize;
};


#endif // !QUEUE_HEADER_H


