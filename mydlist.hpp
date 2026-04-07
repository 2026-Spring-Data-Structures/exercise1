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
		head = new MyNode<T>();
		tail = new MyNode<T>();
		head->setNext(tail);
		head->setPrev(nullptr);
		tail->setPrev(head);
		tail->setNext(nullptr);
		isize = 0;
	}

	~MyDoublyLinkedList()
	{
		while (!isEmpty())
		{
			removeFromHead();
		}
		delete head;
		delete tail;
	}

	bool isEmpty()
	{
		return isize == 0;
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
		MyNode<T>* newNode = new MyNode<T>();
		newNode->set(in);
		newNode->setNext(head->getNext());
		newNode->setPrev(head);
		head->getNext()->setPrev(newNode);
		head->setNext(newNode);
		isize++;
	}

	void removeFromHead()
	{
		if (isEmpty()) return;
		MyNode<T>* target = head->getNext();
		head->setNext(target->getNext());
		target->getNext()->setPrev(head);
		delete target;
		isize--;
	}


	void addToTail(T* in)
	{
		MyNode<T>* newNode = new MyNode<T>();
		newNode->set(in);
		newNode->setPrev(tail->getPrev());
		newNode->setNext(tail);
		tail->getPrev()->setNext(newNode);
		tail->setPrev(newNode);
		isize++;
	}

	void removeFromTail()
	{
		if (isEmpty()) return;
		MyNode<T>* target = tail->getPrev();
		tail->setPrev(target->getPrev());
		target->getPrev()->setNext(tail);
		delete target;
		isize--;
	}
};
