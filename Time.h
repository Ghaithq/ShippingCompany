#pragma once

//    Class Time to Store Day and Hour of the EventTime and PreparationTime
class Time 
{
public:
	int hour;
	int day;
	Time() 
	{
		hour = 0;
		day = 0;
	}
	Time(int h, int d) 
	{
		hour = h;
		day = d;
	}
};


