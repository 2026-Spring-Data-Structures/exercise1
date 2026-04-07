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
		// dev: allocate sentinels; empty list is head <-> tail
		head = new MyNode<T>();
		tail = new MyNode<T>();
		head->set(nullptr);
		tail->set(nullptr);
		head->setNext(tail);
		head->setPrev(nullptr);
		tail->setPrev(head);
		tail->setNext(nullptr);
		isize = 0;
	}

	~MyDoublyLinkedList()
	{
		// dev: remove all data nodes between sentinels, then sentinels
		MyNode<T>* cur = head->getNext();
		while (cur != tail)
		{
			MyNode<T>* next = cur->getNext();
			T* elem = cur->get();
			if (elem != nullptr)
			{
				delete elem;
			}
			delete cur;
			cur = next;
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
		if (isEmpty())
		{
			return nullptr;
		}
		return head->getNext();
	}

	MyNode<T>* getTailNode()
	{
		if (isEmpty())
		{
			return nullptr;
		}
		return tail->getPrev();
	}

	void addToHead(T* in)
	{
		MyNode<T>* node = new MyNode<T>();
		node->set(in);
		MyNode<T>* oldFirst = head->getNext();
		node->setNext(oldFirst);
		node->setPrev(head);
		head->setNext(node);
		oldFirst->setPrev(node);
		isize++;
	}

	void removeFromHead()
	{
		if (isEmpty())
		{
			return;
		}
		MyNode<T>* first = head->getNext();
		MyNode<T>* next = first->getNext();
		head->setNext(next);
		next->setPrev(head);
		T* elem = first->get();
		if (elem != nullptr)
		{
			delete elem;
		}
		delete first;
		isize--;
	}


	void addToTail(T* in)
	{
		MyNode<T>* node = new MyNode<T>();
		node->set(in);
		MyNode<T>* oldLast = tail->getPrev();
		node->setPrev(oldLast);
		node->setNext(tail);
		oldLast->setNext(node);
		tail->setPrev(node);
		isize++;
	}

	void removeFromTail()
	{
		if (isEmpty())
		{
			return;
		}
		MyNode<T>* last = tail->getPrev();
		MyNode<T>* prev = last->getPrev();
		tail->setPrev(prev);
		prev->setNext(tail);
		T* elem = last->get();
		if (elem != nullptr)
		{
			delete elem;
		}
		delete last;
		isize--;
	}
};
