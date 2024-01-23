#pragma once

#include "Event.h"

class CancelEvent:public Event
{
	int ID;

public:


	//     OVERLOADED EXECUTE FUNCTION


	bool Execute(Company& Comp);



	//     FUNCTION TO SET DATA MEMEBERS OF THE EVENT


	void SetParameters(int id);

};

