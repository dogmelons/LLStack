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

	bool startFromHead(const unsigned int& pos)
	{
			return pos < (m_size/2);
	}

	bool isEmpty()					//tests if list is empty
	{
		return head->next == tail;
	}

	void insert(const T& data, const unsigned int& pos)	//inserts new node w/data at specified position
	{
		if (!(pos <= m_size)) {
			std::cout << "error: out of bounds" << std::endl;
			return;
		}
		nodePtr n = new node;

		if(startFromHead(pos))
		{
			current = head->next;
			unsigned int i = 0;
			while(i++<pos) 
			{
				current = current->next;
			}

		}
		else
		{
			current = tail;
			unsigned int i = m_size;
			while(i-->pos)
			{
				current = current->prev;
			}
		}

		n->next = current;
		n->prev = current->prev;
		n->prev->next = n;
		current->prev = n;

		n->info = data;
		m_size++;
	}

	void insert(const T& data)			//inserts new node w/data at end of list
	{
		insert(data, m_size);
	}

	void remove(const unsigned int& pos)		//removes node from specified position
	{
		if(m_size == 0) {
			return;
		}
		if (pos > m_size) {
			std::cout << "error: out of bounds" << std::endl;
			return;
		}

		if(startFromHead(pos))
		{
			unsigned int i = 0;
			current = head->next;
			while(i++ < pos) 
			{
				current = current->next;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
		}
		else
		{
			unsigned int i = m_size;
			current = tail->prev;
			while(i-- > pos) 
			{
				current = current->prev;
			}
			current->prev->next = current->next;
			current->next->prev = current->prev;
			delete current;
		}

		m_size--;
	}

	void remove()					//removes node from end of list
	{
		remove(m_size);
	}

	void clear()					//clears list of all nodes
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

	void print()					//prints list
	{
		if(head->next == tail) {
			return;
		}
		current = head->next;
		while(current != tail) {
			std::cout << current->info << std::endl;
			current = current->next;
		}
	}

	unsigned int peek(T& out)			//gets data of last node
	{
		if(head->next == tail)
		{
			return 0;
		}
		out = tail->prev->info;
		return 1;
	}

	unsigned int size()				//returns size of list
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
