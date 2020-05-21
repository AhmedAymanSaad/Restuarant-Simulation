#pragma once
#include "Pnode.h"
template <typename T>
class Pqueue
{
private :
	
	Pnode<T>* backPtr;
	Pnode<T>* frontPtr;
public :
	Pqueue();
	Pqueue(Pqueue<T>& );
	bool isEmpty() const ;
	bool enqueue(const T& newEntry,int);
	bool dequeue(T& frntEntry);  
	bool peekFront(T& frntEntry)  const;
	T* toArray(int& count);	//returns array of T (array if items)
	~Pqueue();
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
Pqueue<T>::Pqueue()
{
	backPtr=nullptr;
	frontPtr=nullptr;

}

template <typename T>
Pqueue<T>::Pqueue(Pqueue<T>& copyQueue)
{
	backPtr = nullptr;
	frontPtr = nullptr;
	if (copyQueue.isEmpty())
		return;
	Pnode<T>* nptr = copyQueue.frontPtr;
	while (nptr)
	{
		enqueue(nptr->getItem());
		nptr = nptr->getNext();
	}
}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool Pqueue<T>::isEmpty() const
{
	if(frontPtr==nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool Pqueue<T>::enqueue( const T& newEntry,int p)                     //The enqueue here will differ
{
	Pnode<T>* newNodePtr = new Pnode<T>(newEntry,p);
	// Insert the new node
	if (isEmpty())
	{
		frontPtr = newNodePtr; // 
		backPtr = newNodePtr;
	}
	else if(newNodePtr->getP()>frontPtr->getP())
	{
		newNodePtr->setNext(frontPtr);
		frontPtr = newNodePtr; 
	}
	else
	{
		Pnode<T>* curr  = frontPtr;
	while (curr->getNext()!= nullptr)
	{  
		if(curr->getNext()->getP()>= newNodePtr->getP())
		{
			curr=curr->getNext();
		}
		else
		{
			newNodePtr->setNext(curr->getNext());
			curr->setNext(newNodePtr);
			break;
		}
	}
	if (!curr->getNext())
	{
		curr->setNext(newNodePtr);
	}
	if (!newNodePtr->getNext())
		backPtr = newNodePtr;
	}
	return true ;

} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool Pqueue<T>:: dequeue(T& frntEntry)  
{
	if(isEmpty())
		return false;

	Pnode<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == backPtr)	 // Special case: one node in queue
		backPtr = nullptr ;	
		
	// Free memory reserved by the dequeued node
	delete nodeToDeletePtr;


	return true;

}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peekFront
gets the front of this queue. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
return: flase if Queue is empty
*/
template <typename T>
bool Pqueue<T>:: peekFront(T& frntEntry) const 
{
	if(isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////

template <typename T>
Pqueue<T>::~Pqueue()
{
}

template <typename T>
T* Pqueue<T>::toArray(int& count)
{
	count = 0;

	if (!frontPtr)
		return nullptr;
	//counting the no. of items in the Queue
	Pnode<T>* p = frontPtr;
	while (p)
	{
		count++;
		p = p->getNext();
	}


	T* Arr = new T[count];
	p = frontPtr;
	for (int i = 0; i < count;i++)
	{
		Arr[i] = p->getItem();
		p = p->getNext();
	}
	return Arr;
}

/////////////////////////////////////////////////////////////////////////////////////////

