#include "linkedlist.h"

template<typename T>
class LLStack 
{
public:

	void clear()				//clears stack
	{
		list.clear();
	}

	bool isEmpty()				//returns if stack is empty
	{
		return list.isEmpty();
	}

	void peek(T& out)			//gets top element
	{
		list.peek(out);
	}

	void pop(T& out)			//gets and pops top element
	{
		list.peek(out);
		list.remove();
	}

	void push(const T& data)		//pushes new element
	{
		list.insert(data);
	}

	void print()				//prints stack
	{
		list.print();
	}

	LLStack() {}
	~LLStack() {}

private:

	LinkedList<T> list;

};
