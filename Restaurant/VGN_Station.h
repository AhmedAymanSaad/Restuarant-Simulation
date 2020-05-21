#pragma once
#include "Station.h"
class VGN_Station :
	public Station
{
private:
	Queue<Order*>* VGNWaitingQueue;

public:
	void setVGNWaitingQueue(Queue<Order*>*);
	virtual void Execute(Kitchen* pKitchen);
	~VGN_Station();
};

