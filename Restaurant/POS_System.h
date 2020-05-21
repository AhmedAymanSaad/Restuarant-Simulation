#pragma once
#include "Generic_DS/Queue.h"
#include "LinkedList.h"
#include "Rest/Order.h"
#include "../Restaurant/Pqueue.h"

class Restaurant;
class Kitchen;

class POS_System
{
private:
	Kitchen* pKitchen;
	LinkedList<Order*>* InServiceList;
	Queue<Order*>* ServicedQueue; 
	Queue<Order*>* VGNWaitingQueue;
	Pqueue<Order*>* VIPWaitingQueue;
	LinkedList<Order*>* NRMWaitingList;
	
public:
	POS_System();
	void SetKitchen(Kitchen&);
	LinkedList<Order*>* GetNRMWaitingList();
	Pqueue<Order*>* GetVIPWaitingQueue();
	Queue<Order*>* GetVGNWaitingQueue();
	void Execute(Restaurant*);
	bool KitchenIsActive();
	int GetCookCount();   //Returns ntotal number of cooks
	Cook** GetCooksList(); // Returns an array of all the cooks
	Order** GetOrdersList(int& ArrayCount);
	int GetWaitingQueueTotalCount(); // Returns number of orders waiting
	int* GetWaitingQueueCounts();    //Returns the number of orders waiting for each type
	int* GetCooksCounts(); //Returns number of cooks f each type
	LinkedList<Order*>* getInServiceList();
	Queue<Order*>* getServicedQueue();
};

