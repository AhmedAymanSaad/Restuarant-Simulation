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
	Queue<Order*>* servicedo=pKitchen->getpPOS()-> getServicedQueue();
	Queue<Cook*> nrmc=pKitchen->getAvNRMcook();
	Queue<Cook*>vgnc=pKitchen->getAvVGNcook();
    Queue<Cook*>vipc=pKitchen->getAvVIPcook();
	Queue<Cook*>inservicec=pKitchen->getInServiceCook();
	Cook*cptr;
	
	Order*optr;
	
	Cook*cookptr;
	int c;
	int time;
	while(!VGNWaitingQueue->isEmpty()){
	if(!vgnc.isEmpty()){
	VGNWaitingQueue->dequeue(optr);

 
   
	
	vgnc.dequeue(cptr);
	optr->AssignExecute(cptr,pKitchen->getCurrentTimeStep());
	cptr->setAssignedOrder(optr);
	inserviceo->add(optr);
	inservicec.enqueue(cptr);
	optr->setStatus(SRV);
	cptr->setStatus(BUSY);}
	while(!(inserviceo->isEmpty())){
  Cook** arr= inservicec.toArray(c);
	for(int i=0;i<c;i++){
		time=pKitchen->getCurrentTimeStep();
	if(arr[i]->finish(time)){
	arr[i]->incrementOrdersFinished();
	inserviceo->remove(arr[i]->getAssignedOrder());
	servicedo->enqueue(arr[i]->getAssignedOrder()); 
	if(arr[i]->GetType==TYPE_NRM)
	nrmc.enqueue(arr[i]);
	else if(arr[i]->GetType==TYPE_VIP)
	{vipc.enqueue(arr[i]);}
	else {vgnc.enqueue(arr[i]);}
	arr[i]->setStatus(AVAILABLE);
	arr[i]->getAssignedOrder()->setStatus(DONE);
	inservicec.dequeue(arr[i]); 
	}
	}
	
	}


	

	}
}

VGN_Station::~VGN_Station()
{


}