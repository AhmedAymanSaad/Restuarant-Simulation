#ifndef __PNODE_H_
#define __PNODE_H_

template < typename T>
class Pnode
{
private :
	T item; // A data item
	Pnode<T>* next; // Pointer to next node
	int Priority;    // the higher the number of priority the higher the priority
public :
	Pnode();
	Pnode( const T & r_Item,int p);	//passing by const ref.
	Pnode( const T & r_Item, Pnode<T>* nextNodePtr);
	void setItem( const T & r_Item);
	void setNext(Pnode<T>* nextNodePtr);
	T getItem() const ;
	Pnode<T>* getNext() const ;

	int getP();
	void setP(int p);
}; // end Node


template < typename T>
Pnode<T>::Pnode() 
{
	next = nullptr;
} 

template < typename T>
Pnode<T>::Pnode( const T& r_Item,int p)
{
	item = r_Item;
	Priority=p;
	next = nullptr;
} 

template < typename T>
Pnode<T>::Pnode( const T& r_Item, Pnode<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}
template < typename T>
void Pnode<T>::setItem( const T& r_Item)
{
	item = r_Item;
} 

template < typename T>
void Pnode<T>::setNext(Pnode<T>* nextNodePtr)
{
	next = nextNodePtr;
} 

template < typename T>
T Pnode<T>::getItem() const
{
	return item;
} 

template < typename T>
Pnode<T>* Pnode<T>::getNext() const
{
	return next;
} 


template < typename T>

int Pnode<T>::getP() 
{
	return Priority;

} 
template < typename T>
void Pnode<T>::setP(int p)
{
	Priority=p;
} 





#endif