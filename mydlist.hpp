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
	MyDoublyLinkedList() : head(nullptr), tail(nullptr), isize(0)
	{
		// dev: sentinels only; empty list is head <-> tail (O(1) setup)
		head = new MyNode<T>();
		tail = new MyNode<T>();
		head->set(nullptr);
		tail->set(nullptr);
		head->setNext(tail);
		head->setPrev(nullptr);
		tail->setPrev(head);
		tail->setNext(nullptr);
	}

	~MyDoublyLinkedList()
	{
		// dev: single forward walk; delete nullptr is well-defined (no extra branch)
		for (MyNode<T>* cur = head->getNext(); cur != tail; )
		{
			MyNode<T>* next = cur->getNext();
			delete cur->get();
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
		MyNode<T>* n = head->getNext();
		return (n == tail) ? nullptr : n;
	}

	MyNode<T>* getTailNode()
	{
		MyNode<T>* n = tail->getPrev();
		return (n == head) ? nullptr : n;
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
		if (head->getNext() == tail)
		{
			return;
		}
		MyNode<T>* first = head->getNext();
		MyNode<T>* next = first->getNext();
		head->setNext(next);
		next->setPrev(head);
		delete first->get();
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
		if (tail->getPrev() == head)
		{
			return;
		}
		MyNode<T>* last = tail->getPrev();
		MyNode<T>* prev = last->getPrev();
		tail->setPrev(prev);
		prev->setNext(tail);
		delete last->get();
		delete last;
		isize--;
	}
};
