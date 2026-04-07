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
	int size;

public:
	MyDoublyLinkedList()
	{
		head = new MyNode<T>();
		tail = new MyNode<T>();
		head->setNext(tail);
		tail->setPrev(head);
		size = 0;

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
		return size == 0;
	}

	int getSize()
	{
		return size;
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
		size++;
	}

	void removeFromHead()
	{
		if (!isEmpty())
		{
			MyNode<T>* nodeToRemove = head->getNext();
			head->setNext(nodeToRemove->getNext());
			nodeToRemove->getNext()->setPrev(head);
			delete nodeToRemove;
			size--;
		}
	}


	void addToTail(T* in)
	{
		MyNode<T>* newNode = new MyNode<T>();
		newNode->set(in);
		newNode->setNext(tail);
		newNode->setPrev(tail->getPrev());
		tail->getPrev()->setNext(newNode);
		tail->setPrev(newNode);
		size++;
	}

	void removeFromTail()
	{
		if (!isEmpty())
		{
			MyNode<T>* nodeToRemove = tail->getPrev();
			tail->setPrev(nodeToRemove->getPrev());
			nodeToRemove->getPrev()->setNext(tail);
			delete nodeToRemove;
			size--;
		}
	}
};
