#include "Cook.h"
#include "Order.h"


int Cook::IDCount = 0;

Cook::Cook()
{
	IDCount++;
	this->ID = (type + 1) * 100 + IDCount;
	AssignedOrder = nullptr;
}


Cook::~Cook()
{
}


int Cook::GetID() const
{
	return ID;
}


ORD_TYPE Cook::GetType() const
{
	return type;
}


void Cook::setID(int id)
{
	ID = id;
}

void Cook::setType(ORD_TYPE t)
{
	type = t;
}

Cook::Cook(ORD_TYPE type, int speed, int breakdur)
{
	IDCount++;
	this->type = type;
	this->speed = speed;
	BreakDur = breakdur;
	this->ID = (type+1)*100 + IDCount;
	status = AVAILABLE;
	AssignedOrder = nullptr;
}
void Cook::setStatus(COOK_STATUS cs){
	status=cs;
}

COOK_STATUS Cook::getStatus(){
return status;
}
void Cook::incrementOrdersFinished(){
OrdersFinished++;
}
int Cook::getSpeed(){
return speed;
}
bool Cook::finish(int currenttimestep){
	
	if(speed>=1 && AssignedOrder->getservicetime()<currenttimestep){
	return true;
	}
	else{
	return false; 
	}
}
Order* Cook::getAssignedOrder(){
return AssignedOrder;
}
void Cook::setAssignedOrder(Order*p){
	AssignedOrder=p;

}