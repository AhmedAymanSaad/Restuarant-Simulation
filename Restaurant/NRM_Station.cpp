#include "NRM_Station.h"

void NRM_Station::setNRMWaitingList(LinkedList<Order*>* List)
{
	NRMWaitingList = List;
}

void NRM_Station::Execute(Kitchen* pKitchen)
{

}

NRM_Station::~NRM_Station()
{

}