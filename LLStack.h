#include "linkedlist.h"

template<typename T>
class LLStack 
{
public:

	void clear()
	{
		list.clear();
	}

	bool isEmpty()
	{
		return list.isEmpty();
	}

	void peek(T& out)
	{
		list.peek(out);
	}
	
	void pop(T& out)
	{
		list.peek(out);
		list.remove();
	}

	void push(const T& data)
	{
		list.insert(data);
	}

	void print()
	{
		list.print();
	}

	LLStack() {}
	~LLStack() {}

private:

	LinkedList<T> list;

};