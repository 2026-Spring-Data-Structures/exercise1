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
	int isize = 0;

public:
	MyDoublyLinkedList()
	{
		head = new MyNode<T>();
		tail = new MyNode<T>();
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
		MyNode<T> *newNode = new MyNode<T>();
		newNode->set(in);
		newNode->setNext(head->getNext());
		head->getNext()->setPrev(newNode);
		head->setNext(newNode);
		newNode->setPrev(head);
		isize++;
	}

	void removeFromHead()
	{
		MyNode<T>* temp = head->getNext();
		head->setNext(temp->getNext());
		temp->getNext()->setPrev(head);
		delete temp;
		isize--;
	}


	void addToTail(T* in)
	{
		MyNode<T> *newNode = new MyNode<T>();
		newNode->set(in);
		newNode->setPrev(tail->getPrev());
		tail->getPrev()->setNext(newNode);
		tail->setPrev(newNode);
		newNode->setNext(tail);
		isize++;
	}

	void removeFromTail()
	{
		MyNode<T> *temp = tail->getPrev();
		tail->setPrev(temp->getPrev());
		temp->getPrev()->setNext(tail);
		delete temp;
		isize--;
	}
};
