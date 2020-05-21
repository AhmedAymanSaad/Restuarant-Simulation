#include "POS_System.h"
#include "Kitchen.h"
#include "Rest/Restaurant.h"
#include "../Restaurant/Pqueue.h"

POS_System::POS_System()
{
	VGNWaitingQueue = new Queue<Order*>;
	VIPWaitingQueue = new Pqueue<Order*>;
	NRMWaitingList = new LinkedList<Order*>;
	InServiceList = new LinkedList<Order*>;
	ServicedQueue = new Queue<Order*>;
}

void POS_System::SetKitchen(Kitchen& RestKitchen)
{
	pKitchen = &RestKitchen;
}

LinkedList<Order*>* POS_System::GetNRMWaitingList()
{
	return NRMWaitingList;
}

Pqueue<Order*>* POS_System::GetVIPWaitingQueue()
{
	return VIPWaitingQueue;
}

Queue<Order*>* POS_System::GetVGNWaitingQueue()
{
	return VGNWaitingQueue;
}

void POS_System::Execute(Restaurant* pRest)
{
	pRest->ExecuteEvents(pRest->GetTimeStep());
	pKitchen->Execute(pRest);
}

bool POS_System::KitchenIsActive()
{
	if (VGNWaitingQueue->isEmpty() && VIPWaitingQueue->isEmpty() && NRMWaitingList->isEmpty() && InServiceList->isEmpty())
		return false;
	return true;
}

int POS_System::GetCookCount()
{
	return pKitchen->GetCookCount();
}

Cook** POS_System::GetCooksList()
{
	return pKitchen->GetCooksList();
}

Order** POS_System::GetOrdersList(int & ArrayCount)
{
	ArrayCount = 0;
	int VGNwaitingCount = 0;
	int VIPwaitingCount = 0;
	int NRMwaitingCount = 0;
	int inServiceCount = 0;
	int servicedCount = 0;
	Order** VGNWaitingArray = VGNWaitingQueue->toArray(VGNwaitingCount);
	Order** VIPWaitingArray = VIPWaitingQueue->toArray(VIPwaitingCount);
	Order** NRMWaitingArray = NRMWaitingList->toArray(NRMwaitingCount);
	Order** inServiceArray = InServiceList->toArray(inServiceCount);
	Order** ServicedArray = ServicedQueue->toArray(servicedCount);
	Order** OrdersArray = new Order * [VIPwaitingCount+ VGNwaitingCount + NRMwaitingCount + inServiceCount + servicedCount];
	for (int i = 0; i < VIPwaitingCount;i++)
	{
		OrdersArray[ArrayCount] = VIPWaitingArray[i];
		ArrayCount++;
	}
	for (int i = 0; i < VGNwaitingCount;i++)
	{
		OrdersArray[ArrayCount] = VGNWaitingArray[i];
		ArrayCount++;
	}
	for (int i = 0; i < NRMwaitingCount;i++)
	{
		OrdersArray[ArrayCount] = NRMWaitingArray[i];
		ArrayCount++;
	}
	for (int i = 0; i < inServiceCount;i++)
	{
		OrdersArray[ArrayCount] = inServiceArray[i];
		ArrayCount++;
	}
	for (int i = 0; i < servicedCount;i++)
	{
		OrdersArray[ArrayCount] = ServicedArray[i];
		ArrayCount++;
	}
	return OrdersArray;
}

int POS_System::GetWaitingQueueTotalCount()
{
	int VGNwaitingCount = 0;
	int VIPwaitingCount = 0;
	int NRMwaitingCount = 0;
	Order** VGNWaitingArray = VGNWaitingQueue->toArray(VGNwaitingCount);
	Order** VIPWaitingArray = VIPWaitingQueue->toArray(VIPwaitingCount);
	Order** NRMWaitingArray = NRMWaitingList->toArray(NRMwaitingCount);
	return VIPwaitingCount + VGNwaitingCount + NRMwaitingCount;
}

int* POS_System::GetCooksCounts()
{
	return pKitchen->GetCooksCounts();
}

int* POS_System::GetWaitingQueueCounts()
{
	int VGNwaitingCount = 0;
	int VIPwaitingCount = 0;
	int NRMwaitingCount = 0;
	Order** VGNWaitingArray = VGNWaitingQueue->toArray(VGNwaitingCount);
	Order** VIPWaitingArray = VIPWaitingQueue->toArray(VIPwaitingCount);
	Order** NRMWaitingArray = NRMWaitingList->toArray(NRMwaitingCount);
	int* ret = new int[TYPE_CNT];
	ret[0] = NRMwaitingCount;
	ret[1] = VGNwaitingCount;
	ret[2] = VIPwaitingCount;
	return ret;
}
LinkedList<Order*>* POS_System::getInServiceList(){

return InServiceList;
	
}
Queue<Order*>*POS_System:: getServicedQueue(){
return ServicedQueue; 
}