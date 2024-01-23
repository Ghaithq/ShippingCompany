#include "Event.h"

Event::Event()
{
	EventTime.day=0;
	EventTime.hour = 0;
}

Time Event::GetEventTime()
{
	return EventTime;
}

void Event::SetEventTime(Time ET)
{
	EventTime = ET;
}

