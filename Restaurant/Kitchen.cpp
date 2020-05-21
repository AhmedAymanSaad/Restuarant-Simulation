#include "Kitchen.h"
#include "POS_System.h"
#include"Rest/Restaurant.h"

Kitchen::Kitchen()
{
	InServiceCooks = new LinkedList<Cook*>;
}

void Kitchen::SetPOS(POS_System& POS)
{
	pPOS = &POS;
}

void Kitchen::setCookCounts(int * LoadCookCounts)
{
	CookCounts = LoadCookCounts;
}

void Kitchen::setCooksSpeed(int* LoadCooksSpeed)
{
	CooksSpeed = LoadCooksSpeed;
}

void Kitchen::setOrdersBeforeBreak(int LoadOrdersBeforeBreak)
{
	OrdersBeforeBreak = LoadOrdersBeforeBreak;
}

void Kitchen::setCookBreakDur(int* LoadCookBreakDur)
{
	CookBreakDur = LoadCookBreakDur;
}

void Kitchen::setInjProb(double Load)
{
	InjProb = Load;
}

void Kitchen::setRestPrd(int Load)
{
	RestPrd = Load;
}

void Kitchen::setAutoProm(int LoadAutoProm)
{
	AutoProm = LoadAutoProm;
}

void Kitchen::setVIPWait(int LoadVIPWait)
{
	VIPWait = LoadVIPWait;
}

void Kitchen::FillKitchen()
{
	Station* pStation;
	pStation = &StationNRM;
	ORD_TYPE OrdType = TYPE_NRM;
	for (int i = 0;i < TYPE_CNT;i++)
	{
		pStation->FillStation(CookCounts[i], CooksSpeed[2 * i], CooksSpeed[2 * i + 1], CookBreakDur[2 * i], CookBreakDur[2 * i + 1], OrdType);
		pStation = GetNextStation(pStation);
		OrdType = ORD_TYPE(OrdType + 1);
	}
	StationNRM.setNRMWaitingList(pPOS->GetNRMWaitingList());
	StationVGN.setVGNWaitingQueue(pPOS->GetVGNWaitingQueue());
	StationVIP.setVIPWaitingQueue(pPOS->GetVIPWaitingQueue());
}

Station* Kitchen::GetNextStation(Station* CurrStation)
{
	Station* RetStation;
	NRM_Station* pStationNRM = dynamic_cast<NRM_Station*>(CurrStation);
	if (pStationNRM)
	{
		RetStation = &StationVIP;
		return RetStation;
	}
	VGN_Station* pStationVGN = dynamic_cast<VGN_Station*>(CurrStation);
	if (pStationVGN)
	{
		RetStation = &StationNRM;
		return RetStation;
	}
	VIP_Station* pStationVIP = dynamic_cast<VIP_Station*>(CurrStation);
	if (pStationVIP)
	{
		RetStation = &StationVGN;
		return RetStation;
	}
}

void Kitchen::Execute(Restaurant* pRest)
{
	setCurrentTimeStep(pRest->GetTimeStep());
	ExecuteInService(); //Goes through all the orders to check which ones are finished
	CheckUnavailableCooks(); //Break Handling, checks of cook has finished break or not, and has reste from injury or not
	ExecuteAllStations(); //Goes through waiting lists
}

void Kitchen::ExecuteInService()
{
	
}

void Kitchen::CheckUnavailableCooks()
{

}

void Kitchen::ExecuteAllStations()
{
	Station* pStation;
	pStation = &StationVIP;
	for (int i = 0;i < TYPE_CNT;i++)
	{
		pStation->Execute(this);
		pStation = GetNextStation(pStation);
	}
}

int Kitchen::GetCookCount()
{
	int totalCooks = 0;
	for (int i = 0;i < TYPE_CNT;i++)
	{
		totalCooks += CookCounts[i];
	}
	return totalCooks;
}

Cook** Kitchen::GetCooksList()
{
	int totalCooks =GetCookCount();
	Cook** CookArray = new Cook*[totalCooks];
	Station* pStation;
	pStation = &StationNRM;
	Queue<Cook*>* pList;
	Cook** TypesArray;
	int count = 0;
	int x = 0;
	for (int i = 0;i < TYPE_CNT;i++)
	{
		pList = pStation->GetCooksList();
		for (int j = 0;j < CookCounts[i];j++)
		{
			TypesArray = pList->toArray(x);
			CookArray[count] = TypesArray[j];
			count++;
		}
		pStation = GetNextStation(pStation);
	}
	return CookArray;
	
}

int* Kitchen::GetCooksCounts()
{
	return CookCounts;
}

Queue<Cook*>* Kitchen::getAvNRMcook() {
	return StationNRM.GetCooksList();
}
Queue<Cook*>* Kitchen::getAvVGNcook() {
	return StationVGN.GetCooksList();
}
Queue<Cook*>* Kitchen::getAvVIPcook() {
	return StationNRM.GetCooksList();
}
LinkedList<Cook*>* Kitchen::getInServiceCook() {
	return InServiceCooks;
}

int Kitchen::getCurrentTimeStep() {
	return timestep;
}

void Kitchen::setCurrentTimeStep(int ts) {
	timestep = ts;
}

Kitchen::~Kitchen()
{

}
POS_System* Kitchen::getpPOS(){
return pPOS;
}
