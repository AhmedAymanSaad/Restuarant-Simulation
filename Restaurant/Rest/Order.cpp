#include "Order.h"

Order::Order(int id, ORD_TYPE r_Type)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	type = r_Type;
	status = WAIT;
	AssignedCook = nullptr;
	Promoted = false;
}

Order::Order(ORD_TYPE typ, int arrivaltime, int id, int size, double money) 
{
	ID = (id > 0 && id < 1000) ? id : 0;	//1<ID<999
	status = WAIT;
	type = typ;
	Promoted = false;
	ArrTime = arrivaltime;
	ID = id;
	OrdSize = size;
	totalMoney = money;
	ServTime = 0;
	WaitTime = 0;
	AssignedCook = nullptr;
	if(typ==TYPE_VGAN || typ==TYPE_NRM)
	{
		Priority=0;
	}
	else
	{
		Priority=totalMoney / ArrTime * OrdSize;       //The more the money the higher the p the bigger the order sixe the lower the p and the later arrival time the lower the p
	}



}



Order::~Order()
{
}

int Order::GetID()
{
	return ID;
}


ORD_TYPE Order::GetType() const
{
	return type;
}


void Order::SetDistance(int d)
{
	Distance = d>0?d:0;
}

int Order::GetDistance() const
{
	return Distance;
}


void Order::setStatus(ORD_STATUS s)
{
	status = s;
}

ORD_STATUS Order::getStatus() const
{
	return status;
}

void Order::SetPriority()
{
	if (type == TYPE_VIP)
		Priority=totalMoney / ArrTime * OrdSize;    //The more the money the higher the p the bigger the order sixe the lower the p and the later arrival time the lower the p

	else Priority = 0;
}

double Order::GetPriority() 
{
	return Priority;
}

bool Order::InServiceExecute(int TimeStep)
{
	setStatus(DONE);
	FinishTime=TimeStep;
	WaitTime=FinishTime-ServTime;
}

void Order::AssignExecute(Cook*cptr,int TimeStep)
{
	AssignedCook=cptr;
	ServTime=TimeStep;
}

Cook* Order::GetAssignedCook()
{
	return AssignedCook;
}
int Order::getservicetime(){
return ServTime;
}



