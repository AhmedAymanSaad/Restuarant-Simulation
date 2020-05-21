#ifndef __PROMOTION_EVENT_H_
#define __PROMOTION_EVENT_H_

#include "Events/Event.h"


class PromotionEvent: public Event
{
	
		                
	double ExMony;	
public:
	PromotionEvent(int eTime, int oID, double extramoney);
	
	
	virtual void Execute(Restaurant *pRest);	//override execute function

};

#endif