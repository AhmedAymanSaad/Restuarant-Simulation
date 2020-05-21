#include "PromotionEvent.h"
#include "Rest/Restaurant.h"
#include "Events/Event.h"
#include "Generic_DS/Queue.h"
#include "Rest/Order.h"

PromotionEvent::PromotionEvent(int eTime, int oID,double extramoney):Event(eTime,oID)
{
	ExMony=extramoney;
	
}

void PromotionEvent::Execute(Restaurant* pRest)
{
	//TODO
}
	
