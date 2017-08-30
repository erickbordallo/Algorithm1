#ifndef NODE_HEADER_H
#define NODE_HEADER_H

template<typename T>
class Node
{
public:
	Node(T data) :_mData(data)
	{
		_mNextPtr = nullptr;
	}

	~Node()
	{
		_mNextPtr = nullptr;
		delete _mNextPtr;
	}

	T _mData;
	Node *_mNextPtr;
};


#endif // !NODE_HEADER_H

