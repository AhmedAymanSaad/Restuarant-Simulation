#pragma once
#include "Events/Event.h"


class CancelEvent :
	public Event
{

public:
	CancelEvent(int eTime, int oID);
	virtual void Execute(Restaurant* pRest);
	virtual ~CancelEvent();

};

