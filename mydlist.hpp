#include <iostream>

template<typename T>
class MyNode
{
private:
	T* e;
	MyNode<T>* n;
	MyNode<T>* p;

public:
	void set(T* in) { this->e = in; }
	T* get() { return this->e; }
	void setNext(MyNode<T>* newnext) { n = newnext; }
	MyNode<T>* getNext() { return this->n; }
	void setPrev(MyNode<T>* newprev) { p = newprev; }
	MyNode<T>* getPrev() { return this->p; }
};

template<typename T>
class MyDoublyLinkedList
{
private:
	MyNode<T>* head;  // sentinel
	MyNode<T>* tail;  // sentinel
	int isize;

public:
	MyDoublyLinkedList()
	{
		this->head = new MyNode<T>();
		this->tail = new MyNode<T>();
	}

	~MyDoublyLinkedList()
	{
	}

	bool isEmpty()
	{
		return true;
	}

	int getSize()
	{
		return 0;
	}


	MyNode<T>* getHeadNode()
	{
	}

	MyNode<T>* getTailNode()
	{
	}

	void addToHead(T* in)
	{
	}

	void removeFromHead()
	{
		
	}


	void addToTail(T* in)
	{
	}

	void removeFromTail()
	{
	}
};
