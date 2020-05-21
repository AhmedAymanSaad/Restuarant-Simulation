#include "VIP_Station.h"

void VIP_Station::setVIPWaitingQueue(Pqueue<Order*>* List)
{
	VIPWaitingQueue = List;
}

void VIP_Station::Execute(Kitchen* pKitchen)
{

}

VIP_Station::~VIP_Station()
{

}