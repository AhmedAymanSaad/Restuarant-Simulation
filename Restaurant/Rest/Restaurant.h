#ifndef __RESTAURANT_H_
#define __RESTAURANT_H_

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"
#include "..\Generic_DS\Queue.h"
#include "..\Events\Event.h"
#include "../Pqueue.h"


#include "Order.h"
#include "../POS_System.h"
#include "../Kitchen.h"

// it is the maestro of the project
class Restaurant  
{	
private:
	
	GUI *pGUI;
	Queue<Event*> EventsQueue;	//Queue of all events that will be loaded from file
	POS_System Cashier;
	Kitchen RestKitchen;

	int TimeStep;
	int EventCount;       //Number of events during this simulation
	

public:
	
	Restaurant();
	~Restaurant();
	
	void ExecuteEvents(int TimeStep);	//executes all events at current timestep
	void RunSimulation();
	void RUN_MODE_INTR();
	void FillDrawingList();
	void ReadFile(ifstream&);
	int GetTimeStep();
	void incrementTimeStep();
	LinkedList<Order*>* GetNRMWaitingList();
	Pqueue<Order*>* GetVIPWaitingQueue();
	Queue<Order*>* GetVGNWaitingQueue();

};

#endif