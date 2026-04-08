#include <iostream>

using namespace std;

template<typename T>
class MyNode
{
private:
    T* e;
    MyNode<T>* n;
    MyNode<T>* p;

public:
    MyNode<T>(){
	    e = NULL;
	    n = NULL;
	    p = NULL;
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
        this->head = NULL;
        this->tail = NULL; 
        isize = 0;
    }

    ~MyDoublyLinkedList()
    {
        while (!this->isEmpty()) removeFromHead();
    }

    bool isEmpty()                                                          
    {
        if (this->head == NULL) return true;
        else return false;
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
        MyNode<T>* newNode = new MyNode<T>();
        newNode->set(in);

        if (this->isEmpty()) {
            this->head = newNode;
            this->tail = newNode;
            isize++;
            return;
        }

        newNode->setNext(this->head);
        this->head->setPrev(newNode);
        this->head = newNode;
        isize++;
    }

    void removeFromHead()
    {
	if(this->isEmpty()) return;

        MyNode<T>* temp = this->head;
        if (isize == 1) {
            this->head = NULL;
            this->tail = NULL;
            isize--;
            delete temp;
            return;
        }

        this->head = this->head->getNext();
	this->head->setPrev(NULL);
        delete temp;
        isize--;
    }


    void addToTail(T* in)
    {
        MyNode<T>* newNode = new MyNode<T>();
        newNode->set(in);
        if (this->isEmpty()) {
            this->head = newNode;
            this->tail = newNode;
            isize++;
            return;
        }

        newNode->setPrev(this->tail);
        this->tail->setNext(newNode);
        this->tail = newNode;
        isize++;
    }

    void removeFromTail()
    {
	if(this->isEmpty()) return;
        MyNode<T>* temp = this->tail;
        if (isize == 1) {
            this->head = NULL;
            this->tail = NULL;
            isize--;
            delete temp;
            return;
        }

        this->tail = this->tail->getPrev();
	this->tail->setNext(NULL);
        delete temp;
        isize--;
    }
};
