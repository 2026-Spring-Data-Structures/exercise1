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
		head = nullptr;
		tail = nullptr;
		head->setNext(tail);
		tail->setPrev(head);
	}

	~MyDoublyLinkedList()
	{
		delete head;
		delete tail;
	}

	bool isEmpty()
	{
		return getSize() == 0;
	}

	int getSize()
	{
		return isize;
	}


	MyNode<T>* getHeadNode()
	{
		return head->getNext();
	}

	MyNode<T>* getTailNode()
	{
		return tail->getPrev();
	}

	void addToHead(T* in)
	{
		MyNode<T> newNode = new MyNode<T>();
		newNode.set(in);
		head->setNext(newNode);
		isize += 1;
	}

	void removeFromHead()
	{
		MyNode<T> temp = head->getNext()->getNext();
		head->setNext(temp);
		isize -= 1;
	}


	void addToTail(T* in)
	{
		MyNode<T> newNode = new MyNode<T>();
		newNode.set(in);
		tail->setPrev(newNode);
		isize += 1;
	}

	void removeFromTail()
	{
		MyNode<T> temp = tail->getPrev()->getPrev();
		tail->setPrev(temp);
		isize -= 1;
	}
};
