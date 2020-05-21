#include "VIP_Station.h"
#include"Kitchen.h"
#include"POS_System.h"

void VIP_Station::setVIPWaitingQueue(Pqueue<Order*>* List)
{
	VIPWaitingQueue = List;
}

void VIP_Station::Execute(Kitchen* pKitchen)
{
	LinkedList<Order*>* inserviceo=pKitchen->getpPOS()->getInServiceList();
	Queue<Cook*>* nrmc=pKitchen->getAvVGNcook();
	Queue<Cook*>*vgnc=pKitchen->getAvVGNcook();
    Queue<Cook*>*vipc=GetCooksList();
	LinkedList<Cook*>*inservicec=pKitchen->getInServiceCook();
	Cook*cptr;
	Order*optr;
	while (!VIPWaitingQueue->isEmpty()) {
		if (vipc->isEmpty() && !nrmc->isEmpty()) {
			VIPWaitingQueue->dequeue(optr);
			nrmc->dequeue(cptr);
			inserviceo->add(optr);
			inservicec->addend(cptr);
			optr->AssignExecute(cptr, pKitchen->getCurrentTimeStep());
			cptr->setAssignedOrder(optr);
			optr->setStatus(SRV);
			cptr->setStatus(BUSY);
		}
		else if (vipc->isEmpty() && !vgnc->isEmpty()) {
			VIPWaitingQueue->dequeue(optr);
			vgnc->dequeue(cptr);
			inserviceo->add(optr);
			inservicec->addend(cptr);
			optr->AssignExecute(cptr, pKitchen->getCurrentTimeStep());
			cptr->setAssignedOrder(optr);
			optr->setStatus(SRV);
			cptr->setStatus(BUSY);
		}
		else if (!vipc->isEmpty()) {
			VIPWaitingQueue->dequeue(optr);
			vipc->dequeue(cptr);
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

VIP_Station::~VIP_Station()
{
	
}