#pragma once
#include "../Restaurant/LinkedList.h"
#include "Generic_DS/Queue.h"
#include "Pqueue.h"
#include"Rest/Cook.h"

class Kitchen;

class Station
{
private:
	Queue<Cook*>* CooksList;

public:
	Station();
	void FillStation(int,int,int,int,int,ORD_TYPE);
	virtual void Execute(Kitchen* pKitchen);
	Queue<Cook*>* GetCooksList();
	virtual ~Station();
};

