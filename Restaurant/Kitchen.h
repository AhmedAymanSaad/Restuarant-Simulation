#pragma once
#include "VIP_Station.h"
#include "VGN_Station.h"
#include "NRM_Station.h"
#include "Generic_DS/Queue.h"
#include "Rest/Order.h"
#include "Rest/Cook.h"

class Restaurant;
class POS_System;

class Kitchen
{
private:
	POS_System* pPOS;
	VIP_Station StationVIP;
	NRM_Station StationNRM;
	VGN_Station StationVGN;
	

	LinkedList<Cook*>* InServiceCooks;
	int* CookCounts;      //Dynamically allocated array containing the counts of all the different types of cooks
	double InjProb;
	int RestPrd;
	int AutoProm;         //Number of timesteps requiered before a free promote
	int VIPWait;
	int* CooksSpeed;      //Dynamically allocated array containing the speeds of all the different types of cooks
	int OrdersBeforeBreak;
	int* CookBreakDur;    //Dynamically allocated array containing the Break Duration of all the different types of cooks
	int timestep;
public:
	Kitchen();
	void FillKitchen();
	Station* Kitchen::GetNextStation(Station*);
	void SetPOS(POS_System&);
	void Execute(Restaurant*);
	int GetCookCount();
	Cook** GetCooksList(); // Returns an array of all the cooks
	int* GetCooksCounts();
	void setCookCounts(int* LoadCookCounts);
	void setCooksSpeed(int* LoadCooksSpeed);
	void setCookBreakDur(int* LoadCookBreakDur);
	void setOrdersBeforeBreak(int OrdersBeforeBreak);
	void setInjProb(double);
	void setRestPrd(int);
	void setAutoProm(int);
	void setVIPWait(int);
	void ExecuteInService();
	void ExecuteAllStations();
	void CheckUnavailableCooks();
	Queue<Cook*>* getAvNRMcook();
	Queue<Cook*>* getAvVGNcook();
    Queue<Cook*>* getAvVIPcook();
	LinkedList<Cook*>* getInServiceCook();
	int getCurrentTimeStep();
	void setCurrentTimeStep(int);
	POS_System*getpPOS();
	~Kitchen();

};

