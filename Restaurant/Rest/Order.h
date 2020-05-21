#ifndef __ORDER_H_
#define __ORDER_H_

#include "..\Defs.h"

class Cook;

class Order
{

protected:
	int ID;         //Each order has a unique ID (from 1 --> 999 )
	ORD_TYPE type;		//order type: Normal, vegan, VIP
	ORD_STATUS status;	//waiting, in-service, done
	int Distance;	//The distance (in meters) between the order location and the resturant 
	
	double totalMoney;	//Total order money

	int ArrTime, ServTime, FinishTime, WaitTime;	//arrival, service start, and finish times
	int OrdSize;
	double Priority;
	Cook* AssignedCook;
	bool Promoted;

public:
	Order(int ID, ORD_TYPE r_Type);
	Order(ORD_TYPE typ, int arrivaltime, int id, int size, double money);
	virtual ~Order();

	int GetID();

	ORD_TYPE GetType() const;

	void SetDistance(int d);
	int GetDistance() const;

	void setStatus(ORD_STATUS s);
	ORD_STATUS getStatus() const;

	void SetPriority();
	double GetPriority();

	bool InServiceExecute(int);
	void AssignExecute();

	Cook* GetAssignedCook();
	
};

#endif