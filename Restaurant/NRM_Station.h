#pragma once
#include "Station.h"
class NRM_Station :
	public Station
{
private:
	LinkedList<Order*>* NRMWaitingList;

public:
	void setNRMWaitingList(LinkedList<Order*>*);
	virtual void Execute(Kitchen* pKitchen);
	~NRM_Station();
};

