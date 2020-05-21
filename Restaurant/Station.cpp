#include "Station.h"
#include "Kitchen.h"
#include <stdlib.h> 
#include<time.h> 

Station::Station()
{
	CooksList= new Queue<Cook*>();
}

void Station::FillStation(int CookCount, int minSpeed, int maxSpeed, int minBreakDur, int maxBreakDur, ORD_TYPE OrdType)
{
	srand(time(0));
	for (int j = 0; j < CookCount;j++)
	{
		int CookSpeed = minSpeed + rand() % (maxSpeed - minSpeed + 1);
		int BreakDur = minBreakDur + rand() % (maxBreakDur - minBreakDur + 1);
		Cook* pCo = new Cook(OrdType, CookSpeed, BreakDur);
		CooksList->enqueue(pCo);
	}
}

Queue<Cook*>* Station::GetCooksList()
{
	return CooksList;
}

void Station::Execute(Kitchen* pKitchen)
{
	
}

Station::~Station()
{

}