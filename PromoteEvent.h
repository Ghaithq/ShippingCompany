#pragma once

#include "Event.h"

class PromoteEvent:public Event
{
	int ID;
	int ExtraCost;
public:

	//     OVERLOADED EXECUTE FUNCTION


	bool Execute(Company& C);



	//     FUNCTION TO SET DATA MEMEBERS OF THE EVENT


	void SetParameters(int id, int EC);



};

