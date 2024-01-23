#include "Truck.h"
#include "Queue.h"
int Truck::J = 0;
int Truck::TruckCount = 0;

Truck::Truck(int DI)
{
	DeliveryInterval = DI;
	TotalJourneys = 0;
	EndOfCheckUp = 0;
	TruckActiveTime = 0;
	DeliveryFailed = false;
}
Truck::Truck()
{
	TID = ++TruckCount;
	DeliveryInterval = 0;
	TotalJourneys = 0;
	EndOfCheckUp = 0;
	EmergencyFlag = false;
	TruckActiveTime = 0;
	DeliveryFailed = false;
}

void Truck::LoadCargo(Cargo* C)
{
	int Prio = C->CalcPrio();
	CargosQueue.enqueue(C,Prio);
}

void Truck::SetMovingTime(Time T)
{
	MovingTime = T;
}

Time Truck::GetMovingTime()
{
	return MovingTime;
}

bool Truck::PeekCargosQueue(Cargo*& C)
{
	return CargosQueue.Peek(C);
}

bool Truck::DequeueCargo(Cargo*& C)
{
	return CargosQueue.Dequeue(C);
}

int Truck::GetDeliveryInterval()
{
	return DeliveryInterval;
}

int Truck::CalcPrio()
{
		Cargo* TempCargo;
		if(CargosQueue.Peek(TempCargo))
		{
		int CDT;
		CDT = TempCargo->GetCDT().day * 24 + TempCargo->GetCDT().hour;
		return 10000.0/CDT;
	    }
		else
		{
			if (DeliveryFailed)
				return 10000.0 / (MovingTime.day * 24 + MovingTime.hour);  // DeliveryInterval=0
			return 10000.0/(MovingTime.day * 24 + MovingTime.hour + DeliveryInterval);
		}
}



void Truck::SetTotalJourneys(int TJ)
{
	TotalJourneys = TJ;
}

int Truck::GetTotalJourneys()
{
	return TotalJourneys;
}

void Truck::SetJ(int j)
{
	J = j;
}

int Truck::GetJ()
{
	return J;
}

bool Truck::IsEmpty()
{
	return CargosQueue.IsEmpty();
}

int Truck::GetEndOfCheckUp()
{
	return EndOfCheckUp;
}
void Truck::SetEFlag(bool F)
{
	EmergencyFlag = F;
}
bool Truck::GetEFlag()
{
	return EmergencyFlag;
}
int Truck::GetTID()
{
	return TID;
}
void Truck::PrintTruckCargos()
{
	Cargo* Temp;
	CargosQueue.Peek(Temp);
	if (Temp)
		switch (Temp->GetCT())
		{
		case 'N':
		{
			cout << '[';
			CargosQueue.Print();
			cout << ']';
			cout << ' ';
			break;
		}
		case 'S':
		{
			cout << '(';
			CargosQueue.Print();
			cout << ')';
			cout << ' ';
			break;
		}
		case 'V':
		{
			cout << '{';
			CargosQueue.Print();
			cout << '}';
			cout << ' ';
			break;
		}
		}
	else
		cout << "E ";
}

void Truck::PrintID()
{
	cout << TID;
}

int Truck::GetCargoCount()
{
	return CargosQueue.GetCount();
}


void Truck::SetCWT()
{
	int MTHours = MovingTime.day * 24 + MovingTime.hour;
	Queue<Cargo*> Temp;
	Cargo* TempCargo;
	int PrepHours;
	while (CargosQueue.Dequeue(TempCargo))
	{
		PrepHours = TempCargo->GetPreparationTime().day * 24 + TempCargo->GetPreparationTime().hour;
		TempCargo->SetWT(Time((MTHours - PrepHours) % 24, (MTHours - PrepHours) / 24));
		Temp.Enqueue(TempCargo);
	}
	while (Temp.Dequeue(TempCargo))
	{
		CargosQueue.enqueue(TempCargo, TempCargo->CalcPrio());
	}
}

int Truck::GetActiveTime()
{
	return TruckActiveTime;
}

void Truck::SetTDC(int tdc)
{
	TDC = tdc;
}

int Truck::GetTDC()
{
	return TDC;
}

void Truck::SetReturnH(int h)
{

	ReturningHours = h;
}

int Truck::GetReturnH()
{
	return ReturningHours;
}

bool Truck::GetDeliveryFailed()
{
	return DeliveryFailed;
}
void Truck::SetDeliveryFailed(bool b)
{
	DeliveryFailed = b;
}