#include "Cook.h"

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

