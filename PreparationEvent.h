#pragma once

#include "Event.h"

class PreparationEvent:public Event
{
	char CargoType;
	Time EventTime;
	int Distance;
	int LoadTime;
	int Cost;
	int ID;

public:

	//     OVERLOADED EXECUTE FUNCTION


	bool Execute( Company& Comp);


	//     FUNCTION TO SET DATA MEMEBERS OF THE EVENT


	void SetParameters(char CT, Time ET, int D, int LT, int C,int id);


};

