#include <iostream>

template<typename T>
class LinkedList {
public: 

	LinkedList() 
	{
		head = new node;
		tail = new node;

		head->prev = 0;
		head->next = tail;

		tail->next = 0;
		tail->prev = head;

		current = 0;
		m_size = 0;
	}

	~LinkedList() 
	{
		current = head->next;
		while(current != tail) {
			head->next = current->next;
			delete current;
			current = head->next;
		}
		delete head;
		delete tail;
	}

	bool isEmpty()
	{
		return head->next == tail;
	}

	void insert(const T& data, const unsigned int& pos)
	{
		if (!(pos <= m_size)) {
			std::cout << "error: out of bounds";
			return;
		}
		nodePtr n = new node;
		current = head->next;
		unsigned int i = 0;
		while(i++<pos) {
			current = current->next;
		}
		n->next = current;		//rearrange links so n is inserted at specified position
		n->prev = current->prev;
		n->prev->next = n;
		current->prev = n;

		n->info = data;
		m_size++;
	}

	void insert(const T& data)
	{
		insert(data, m_size);
	}

	void remove(const unsigned int& pos)
	{
		if(m_size == 0) {
			return;
		}
		if (!(pos <= m_size)) {
			std::cout << "error: out of bounds";
			return;
		}
		unsigned int i = 0;
		current = head->next;
		while(i++ < pos) {
			current = current->next;
		}
		current->prev->next = current->next;
		current->next->prev = current->prev;
		delete current;
		m_size--;
	}

	void remove()
	{
		remove(m_size-1);
	}

	void clear()
	{
		current = head->next;
		while(current != tail) {
			head->next = current->next;
			delete current;
			current = head->next;
		}
		tail->prev = head;
		m_size = 0;
	}

	void print()
	{
		if(head->next == tail) {
			return;
		}
		current = head->next;
		while(current->next != tail->next) {
			std::cout << current->info << "\n";
			current = current->next;
		}
	}

	unsigned int peek(T& out)
	{
		if(head->next == tail)
		{
			return 0;
		}
		out = tail->prev->info;
		return 1;
	}

	unsigned int size()
	{
		return m_size;
	}

private: 
	typedef struct node {
		T info;
		node* next;
		node* prev;
	}*nodePtr;

	nodePtr head;
	nodePtr tail;
	nodePtr current;
	unsigned int m_size;

};