 #include "NRM_Station.h"
#include"Kitchen.h"
#include"POS_System.h"
void NRM_Station::setNRMWaitingList(LinkedList<Order*>* List)
{
	NRMWaitingList = List;
}

void NRM_Station::Execute(Kitchen* pKitchen)
{
	LinkedList<Order*>* inserviceo = pKitchen->getpPOS()->getInServiceList();
	Queue<Cook*>* nrmc = GetCooksList();
	Queue<Cook*>* vipc = pKitchen->getAvVIPcook();
	LinkedList<Cook*>* inservicec = pKitchen->getInServiceCook();
	Cook* cptr;

	Node<Order*>* nptr;
	Order* optr;

	Cook* cookptr;
	while (!NRMWaitingList->isEmpty()) {
		nptr = NRMWaitingList->GetFirst();
		optr = nptr->getItem();
		if (nrmc->isEmpty() && !vipc->isEmpty()) {
			vipc->dequeue(cptr);
			inserviceo->add(optr);
			NRMWaitingList->remove(optr);
			inservicec->addend(cptr);
			optr->AssignExecute(cptr, pKitchen->getCurrentTimeStep());
			cptr->setAssignedOrder(optr);
			optr->setStatus(SRV);
			cptr->setStatus(BUSY);
		}
		else if (!nrmc->isEmpty()) {
			nrmc->dequeue(cptr);
			optr->AssignExecute(cptr, pKitchen->getCurrentTimeStep());
			cptr->setAssignedOrder(optr);
			inserviceo->add(optr);
			NRMWaitingList->remove(optr);
			inservicec->addend(cptr);
			optr->setStatus(SRV);
			cptr->setStatus(BUSY);
		}
		else return;
	}
}

NRM_Station::~NRM_Station()
{

}