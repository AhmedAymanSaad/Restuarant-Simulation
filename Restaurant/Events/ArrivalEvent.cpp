#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"
#include "../Pqueue.h"


ArrivalEvent::ArrivalEvent(int eTime, int oID, ORD_TYPE oType):Event(eTime, oID)
{
	OrdType = oType;
	OrdDistance = 0;
}

ArrivalEvent::ArrivalEvent(int eTime, int oID, ORD_TYPE oType,double Money,int Size) : Event(eTime, oID)
{
	OrdType = oType;
	OrdDistance = 0;
	OrdMoney = Money;
	OrdSize = Size;
}

void ArrivalEvent::Execute(Restaurant* pRest)
{
	Order* NewOrder = new Order(OrdType,EventTime,OrderID,OrdSize,OrdMoney);
	if (OrdType == TYPE_VIP)
		pRest->GetVIPWaitingQueue()->enqueue(NewOrder,NewOrder->GetPriority());
	if (OrdType == TYPE_VGAN)
		pRest->GetVGNWaitingQueue()->enqueue(NewOrder);
	if (OrdType == TYPE_NRM)
		pRest->GetNRMWaitingList()->addend(NewOrder);
}
