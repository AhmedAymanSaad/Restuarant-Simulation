#include "VGN_Station.h"
#include "Kitchen.h"

void VGN_Station::setVGNWaitingQueue(Queue<Order*>* List)
{
	VGNWaitingQueue = List;
}

void VGN_Station::Execute(Kitchen* pKitchen)
{

}

VGN_Station::~VGN_Station()
{

}