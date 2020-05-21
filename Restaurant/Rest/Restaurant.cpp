#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
using namespace std;

#include "Restaurant.h"
#include "..\Events\ArrivalEvent.h"
#include "..\CancelEvent.h"
#include "..\PromotionEvent.h"



Restaurant::Restaurant() 
{
	pGUI = NULL;
	TimeStep = 0;
	ifstream ifile;
	ReadFile(ifile);;
	RestKitchen.SetPOS(Cashier);
	Cashier.SetKitchen(RestKitchen);
	RestKitchen.FillKitchen();
}

void Restaurant::ReadFile(ifstream& ifile)
{
	ifile.open("Read.txt", ios::out);

	int* CookCounts = new int[TYPE_CNT];
	for (int i = 0;i < TYPE_CNT;i++)
	{
		ifile >> CookCounts[i];
	}
	RestKitchen.setCookCounts(CookCounts);

	int* CooksSpeed = new int[2 * TYPE_CNT];
	for (int i = 0;i < 2*TYPE_CNT;i++)
	{
		ifile >> CooksSpeed[i];
	}
	RestKitchen.setCooksSpeed(CooksSpeed);

	int OrdersBeforeBreak;
	ifile >> OrdersBeforeBreak;
	RestKitchen.setOrdersBeforeBreak(OrdersBeforeBreak);

	int* CookBreakDur = new int[2 * TYPE_CNT];
	for (int i = 0;i < 2*TYPE_CNT;i++)
	{
		ifile >> CookBreakDur[i];
	}
	RestKitchen.setCookBreakDur(CookBreakDur);

	double InjProb;
	int RestPrd;
	ifile >> InjProb;
	ifile >> RestPrd;
	RestKitchen.setInjProb(InjProb);
	RestKitchen.setRestPrd(RestPrd);

	int AutoProm, VIPWait;
	ifile >> AutoProm;
	ifile >> VIPWait;
	RestKitchen.setAutoProm(AutoProm);
	RestKitchen.setVIPWait(VIPWait);

	ifile >> EventCount;

	char EventType, TYP;
	ORD_TYPE OrdType;
	int ArrivalTime, oID, DishNum, Money, ExMoney;
	for (int i = 0;i < EventCount;i++)
	{
		Event* NewEvent;
		ifile >> EventType;
		switch (EventType)
		{
		case 'R':
			ifile >> TYP >> ArrivalTime >> oID >> DishNum >> Money;
			switch (TYP)
			{
			case 'N':
				OrdType = TYPE_NRM;
				break;
			case 'G':
				OrdType = TYPE_VGAN;
				break;
			case 'V':
				OrdType = TYPE_VIP;
				break;
			}
			NewEvent = new ArrivalEvent(ArrivalTime, oID, OrdType);
			EventsQueue.enqueue(NewEvent);
			break;

		case 'X':
			ifile >> ArrivalTime >> oID;
			NewEvent = new CancelEvent(ArrivalTime, oID);
			EventsQueue.enqueue(NewEvent);
			break;

		case 'P':
			ifile >> ArrivalTime >> oID >> ExMoney;
			NewEvent = new PromotionEvent(ArrivalTime, oID, ExMoney);
			EventsQueue.enqueue(NewEvent);
			break;
		}
	}
	ifile.close();
}

int Restaurant::GetTimeStep()
{
	return TimeStep;
}

LinkedList<Order*>* Restaurant::GetNRMWaitingList()
{
	return Cashier.GetNRMWaitingList();
}

Pqueue<Order*>* Restaurant::GetVIPWaitingQueue()
{
	return Cashier.GetVIPWaitingQueue();
}

Queue<Order*>* Restaurant::GetVGNWaitingQueue()
{
	return Cashier.GetVGNWaitingQueue();
}

void Restaurant::RunSimulation()
{
	pGUI = new GUI;
	PROG_MODE	mode = pGUI->getGUIMode();
		
	switch (mode)	//Add a function for each mode in next phases
	{
	case MODE_INTR:
		RUN_MODE_INTR();
		break;
	case MODE_STEP:
		break;
	case MODE_SLNT:
		break;

	};

}

void Restaurant::RUN_MODE_INTR()
{
	Event* pE;
	while (EventsQueue.peekFront(pE) || Cashier.KitchenIsActive())
	{
		pGUI->waitForClick();
		Cashier.Execute(this);
		incrementTimeStep();
	}
	pGUI->waitForClick();
}

void Restaurant::incrementTimeStep()
{
	TimeStep++;
	string msg = "TimeStep: " + to_string(TimeStep - 1);
	msg += "\nWaiting Orders: Normal= " + to_string(Cashier.GetWaitingQueueCounts()[TYPE_NRM]) + " ,Vegan= " + to_string(Cashier.GetWaitingQueueCounts()[TYPE_VGAN]) + " ,VIP= " + to_string(Cashier.GetWaitingQueueCounts()[TYPE_VIP]);
	msg += "\nAvailable Cooks: Normal= " + to_string(Cashier.GetCooksCounts()[TYPE_NRM]) + " ,Vegan= " + to_string(Cashier.GetCooksCounts()[TYPE_VGAN]) + " ,VIP= " + to_string(Cashier.GetCooksCounts()[TYPE_VIP]);
	pGUI->PrintMessage(msg);
	pGUI->ResetDrawingList();
	FillDrawingList();
	pGUI->UpdateInterface();
}

//////////////////////////////////  Event handling functions   /////////////////////////////

//Executes ALL events that should take place at current timestep
void Restaurant::ExecuteEvents(int CurrentTimeStep)
{
	Event *pE;
	while( EventsQueue.peekFront(pE) )	//as long as there are more events
	{
		if(pE->getEventTime() > CurrentTimeStep )	//no more events at current timestep
			return;

		pE->Execute(this);
		EventsQueue.dequeue(pE);	//remove event from the queue
		delete pE;		//deallocate event object from memory
	}

}


Restaurant::~Restaurant()
{
		if (pGUI)
			delete pGUI;
}

void Restaurant::FillDrawingList()
{
	//This function should be implemented in phase1
	//It should add ALL orders and Cooks to the drawing list
	//It should get orders from orders lists/queues/stacks/whatever (same for Cooks)
	//To add orders it should call function  void GUI::AddToDrawingList(Order* pOrd);
	//To add Cooks it should call function  void GUI::AddToDrawingList(Cook* pCc);
	Cook** CookList = Cashier.GetCooksList();
	int CookListSize = Cashier.GetCookCount();
	for (int i = 0;i <CookListSize ;i++)
	{
		pGUI->AddToDrawingList(CookList[i]);
	}
	int OrderListSize = 0;
	Order** OrderList = Cashier.GetOrdersList(OrderListSize);
	for (int i = 0;i < OrderListSize;i++)
	{
		pGUI->AddToDrawingList(OrderList[i]);
	}
}







