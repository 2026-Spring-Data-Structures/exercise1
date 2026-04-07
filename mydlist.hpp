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
		this->head = NULL;
		this->tail = NULL;
	}

	~MyDoublyLinkedList()
	{
		while(!this->isEmpty()) removeFromHead();
	}

	bool isEmpty()
	{
		if(this->head) return false;
		else return true;
	}

	int getSize()
	{
		return isize;
	}


	MyNode<T>* getHeadNode()
	{
		return this->head;
	}

	MyNode<T>* getTailNode()
	{
		return this->tail;
	}

	void addToHead(T* in)
	{
		MyNode<T>* newNode = new myNode<T>();
		newNode->set(in);
		newNode->setNext(this->head);
		this->head->setPrev(newNode);
		this->head = newNode;
		isize++;

	}

	void removeFromHead()
	{
		MyNode<T>* temp = this->head;
		this->head = this->head->getNext();
		delete temp;
		isize--;
	}


	void addToTail(T* in)
	{
		MyNode<T>* newNode = new myNode<T>();
		newNode->set(in);
		newNode->setPrev(this->tail);
		this->tail->setPrev(newNode);
		this->tail = newNode;
		isize++;
	}

	void removeFromTail()
	{
		MyNode<t>* temp = this->tail;
		this->tail = this->tail.getPrev();
		delete temp;
		isize--;
	}
};
