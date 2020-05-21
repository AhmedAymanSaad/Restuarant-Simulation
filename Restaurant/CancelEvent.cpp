#include "CancelEvent.h"
#include "Rest/Restaurant.h"

CancelEvent::CancelEvent(int eTime, int oID) :Event(eTime, oID)
{

}

void CancelEvent::Execute(Restaurant* pRest)
{
	LinkedList<Order*>* x = pRest->GetNRMWaitingList();
	int NRMwaitingCount = 0;
	Order** NRMWaitingArray = x->toArray(NRMwaitingCount);
	for (int i = 0;i < NRMwaitingCount;i++)
	{
		if (NRMWaitingArray[i]->GetID() == OrderID)
		{
			x->remove(NRMWaitingArray[i]);
		}
	}
}

CancelEvent::~CancelEvent()
{

}