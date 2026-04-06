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
	    this->head->setNext(tail);
		this->head->setPrev(NULL);
		this->tail->setPrev(head);
		this->tail->setNext(NULL);
		this->isize = 0;
	}

	~MyDoublyLinkedList()
	{
		// while( ! this->empty() )
		// 	removeFromHead();
	}

	bool isEmpty()
	{
		return (this->isize == 0);
	}

	int getSize()
	{
		return this->isize;
	}


	MyNode<T>* getHeadNode()
	{
		if( this->head->getNext() != NULL )
			return this->head->getNext();
		else
			return NULL;
	}

	MyNode<T>* getTailNode()
	{
		if( this->tail->getPrev() != NULL )
			return this->tail->getPrev();
		else
			return NULL;
	}

	void addToHead(T* in)
	{
		MyNode<T>* newNode = new MyNode<T>();
		newNode->set(in);
		newNode->setNext(this->head->getNext());
		this->head->getNext()->setPrev(newNode);
		this->head->setNext(newNode);
		newNode->setPrev(this->head);

		this->isize += 1;
	}

	void removeFromHead()
	{
		MyNode<T>* temp = this->head->getNext();

		this->head->setNext(this->head->getNext()->getNext());
		this->head->getNext()->setPrev(this->head);

		delete temp;

		this->isize -= 1;
	}


	void addToTail(T* in)
	{
		MyNode<T>* newNode = new MyNode<T>();
		newNode->set(in);
		newNode->setNext(this->tail);
		newNode->setPrev(this->tail->getPrev());
		this->tail->getPrev()->setNext(newNode);
		this->tail->setPrev(newNode);

		this->isize += 1;
	}

	void removeFromTail()
	{
	    MyNode<T>* temp = this->tail->getPrev();

		MyNode<T>* newPrev = this->tail->getPrev()->getPrev();

		newPrev->setNext(this->tail);
	    this->tail->setPrev(newPrev);

	    delete temp;

	    this->isize -= 1;
	}
};
