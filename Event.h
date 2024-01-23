#pragma once
#include "Time.h"
class Company;

class Event
{
protected:
	Time EventTime;
public:
	//      CONSTRUCTORS

	Event();

	//-----------------------------------------------------//

	//      PURE VIRTUAL EXECUTE FUNCTION OVERLOADED IN EACH CLASS

	virtual bool Execute(Company &Comp) = 0;

	//-----------------------------------------------------//


	//      GETTERS

	
	//function to return Event Time

    Time GetEventTime();
	

	//      SETTERS

	
	//function to set Event Time


	void SetEventTime(Time ET);


};

