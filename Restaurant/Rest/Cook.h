#pragma once

#include "..\Defs.h"

class Order;

class Cook
{
	int ID;
	ORD_TYPE type;	//for each order type there is a corresponding type (VIP, Normal, Vegan)
	int speed;		//dishes it can prepare in one clock tick (in one timestep)
	int BreakDur; //Consecutive orders finished
	int OrdersFinished;
	static int IDCount;
	COOK_STATUS status;
	Order* AssignedOrder;

public:
	Cook();
	Cook(ORD_TYPE type,int,int);
	virtual ~Cook();
	int GetID() const;
	ORD_TYPE GetType() const;
	void setID(int);
	void setType(ORD_TYPE) ;

};
