#pragma once
#include "Station.h"
class VIP_Station :
	public Station
{
private:
	Pqueue<Order*>* VIPWaitingQueue;

public:
	void setVIPWaitingQueue(Pqueue<Order*>*);
	virtual void Execute(Kitchen* pKitchen);
	~VIP_Station();
};

