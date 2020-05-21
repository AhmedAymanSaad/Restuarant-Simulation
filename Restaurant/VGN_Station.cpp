#include "VGN_Station.h"

#include"Rest\Order.h"
#include "Kitchen.h"
#include"POS_System.h"
void VGN_Station::setVGNWaitingQueue(Queue<Order*>* List)
{
	VGNWaitingQueue = List;
}

void VGN_Station::Execute(Kitchen* pKitchen)
{
	LinkedList<Order*>* inserviceo=pKitchen->getpPOS()->getInServiceList();
	Queue<Cook*>*vgnc=GetCooksList();
	LinkedList<Cook*>*inservicec=pKitchen->getInServiceCook();
	Cook*cptr;
	Order*optr;
	while (!VGNWaitingQueue->isEmpty()) {
		if (!vgnc->isEmpty()) {
			VGNWaitingQueue->dequeue(optr);
			vgnc->dequeue(cptr);
			optr->AssignExecute(cptr, pKitchen->getCurrentTimeStep());
			cptr->setAssignedOrder(optr);
			inserviceo->add(optr);
			inservicec->addend(cptr);
			optr->setStatus(SRV);
			cptr->setStatus(BUSY);
		}
		else return;
	}
}

VGN_Station::~VGN_Station()
{


}