
#ifndef __BAG_H_
#define __BAG_H_
#include "Generic_DS/Node.h"


template <typename T>
class LinkedList
{
	Node<T>* Head;
	int itemcount;

	public:
	LinkedList<T>();
	LinkedList<T>(const LinkedList<T> & abag);
	bool isEmpty();
	bool add (const T& newentry);
	bool addend(const T& newentry);
	bool remove(const T& anentry);
	void clear();
	Node<T>* GetFirst();
	Node<T>* GetLast();
	Node<T>*getpointerto(const T &item);
	LinkedList operator=(LinkedList);
	T* toArray(int &);
	~LinkedList();
};

template <typename T>
LinkedList<T>::LinkedList<T>()
{
	itemcount = 0;
	Head = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList<T>(const LinkedList<T> & abag)
{
	Node<T>* nptr = abag.Head;
	for (int i = 0;i < abag.itemcount;i++)
	{
		this.add(nptr->getItem());
		nptr = nptr->getnext();
	}
}

template <typename T>
bool LinkedList<T>::add(const T &newentry)
{
	Node<T>*newnode=new Node<T>();
	newnode->setItem(newentry);
	if (Head)
		newnode->setNext(Head);
	Head=newnode;
	itemcount++;
	return true;

}

template <typename T>
bool LinkedList<T>::addend(const T& newentry)
{
	Node<T>* pNode = this->GetLast();
	Node<T>* NewNode = new Node<T>();
	NewNode->setItem(newentry);
	if (pNode)
		pNode->setNext(NewNode);
	else Head = NewNode;
	itemcount++;
	return true;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	return itemcount==0;
}

template <typename T>
Node<T>* LinkedList<T>::getpointerto(const T &item)
{
	bool found =false;
	Node<T>*cur=Head;
	while(!found &&(cur!=nullptr))
	{
		if(item==cur->getItem())
			found=true;
		else
			cur=cur->getNext();
	}
	return cur;
}

template <typename T>
bool LinkedList<T>::remove(const T &anentry)
{
	Node<T>*p1=getpointerto(anentry);
	if (!p1)
		return false;
	p1->setItem(Head->getItem());
	Node<T>*del=Head;
	Head=Head->getNext();
	del->setNext(nullptr);
	delete del;
	del=nullptr;
	itemcount--;
	return true;
}



template <typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template <typename T>
void LinkedList<T>::clear()
{
	while(Head!=nullptr)
	{
		Node<T>*del=Head;
		Head=Head->getNext();
		del->setNext(nullptr);
		delete del;
	
	}
	del=nullptr;
	itemcount=0;

}

template <typename T>
LinkedList<T> LinkedList<T>::operator=(LinkedList List)
{
	LinkedList<T> ret(List);
	return ret;
}

template <typename T>
Node<T>* LinkedList<T>::GetFirst()
{
	if (Head)
		return Head;
	return nullptr;
}

template <typename T>
T* LinkedList<T>::toArray(int& count)
{
	count = itemcount;
	T* Array = new T[itemcount];
	Node<T>* nptr = Head;
	for (int i = 0;i < itemcount;i++)
	{
		Array[i] = nptr->getItem();
		nptr = nptr->getNext();
	}
	return Array;
}

template <typename T>
Node<T>* LinkedList<T>::GetLast()
{
	if (!Head)
		return nullptr;
	Node<T>* nptr = Head;
	while (nptr->getNext())
		nptr = nptr->getNext();
	return nptr;
}

#endif