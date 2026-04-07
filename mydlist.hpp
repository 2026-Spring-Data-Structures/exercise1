#include <iostream>

template<typename T>
class MyNode
{
private:
	T* e;
	MyNode<T>* n;
	MyNode<T>* p;

public:
	MyNode()
    	{
        	e = nullptr;
        	n = nullptr;
       		p = nullptr;
    	}


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
        	tail->setPrev(head);
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
        	MyNode<T>* first = head->getNext();

        	newNode->set(in);
        	newNode->setPrev(head);
        	newNode->setNext(first);

        	head->setNext(newNode);
        	first->setPrev(newNode);

        	isize++;
	}

	void removeFromHead()
	{
        	if (isEmpty())
        	{
            		return;
        	}

        	MyNode<T>* first = head->getNext();
        	MyNode<T>* second = first->getNext();

        	head->setNext(second);
        	second->setPrev(head);

        	delete first;
        	isize--;
	}


	void addToTail(T* in)
	{
		MyNode<T>* newNode = new MyNode<T>();
        	MyNode<T>* last = tail->getPrev();

        	newNode->set(in);
        	newNode->setNext(tail);
        	newNode->setPrev(last);

        	last->setNext(newNode);
        	tail->setPrev(newNode);

        	isize++;
	}

	void removeFromTail()
	{
		if (isEmpty())
        	{
           		 return;
        	}

        	MyNode<T>* last = tail->getPrev();
        	MyNode<T>* beforeLast = last->getPrev();

        	beforeLast->setNext(tail);
        	tail->setPrev(beforeLast);

        	delete last;
        	isize--;
	}
};
