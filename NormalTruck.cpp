#include "Truck.h"
#include "NormalTruck.h"
#include "Queue.h"

int NormalTruck::TruckCapacity = 0;
int NormalTruck::Speed = 0;
int NormalTruck::CheckUpDuration = 0;
NormalTruck::NormalTruck()
{

}

NormalTruck::NormalTruck(int DI)  //uidch
{
	DeliveryInterval = DI;
}


void NormalTruck::SetStaticMembers(int TC, int S, int CUD)
{
	TruckCapacity = TC;
	Speed = S;
	CheckUpDuration = CUD;
}

void NormalTruck::SetDeliveryInterval()
{
	int LoadHours = 0;
	int FurthestDis;
	Queue<Cargo*> CargosTemp;
	Cargo* CTemp;
	while (CargosQueue.Dequeue(CTemp))
	{
		LoadHours += CTemp->GetLoadUnloadTime();
		CargosTemp.Enqueue(CTemp);
	}
	if (CTemp)
		FurthestDis = CTemp->GetDeliveryDistance();
	while (CargosTemp.Dequeue(CTemp))
	{
		CargosQueue.enqueue(CTemp, CTemp->CalcPrio());
	}
	DeliveryInterval = 2.0 * FurthestDis / Speed + LoadHours;
	TruckActiveTime += FurthestDis / Speed + 2 * LoadHours;
	ReturningHours = FurthestDis / Speed;
}

int NormalTruck::GetTruckCapacity()
{
	return TruckCapacity;
}

int NormalTruck::GetSpeed()
{
	return Speed;
}

int NormalTruck::GetCheckUpDuration()
{
	return CheckUpDuration;
}

void NormalTruck::SetEndOfCheckUp(Time EOCU)
{
	EndOfCheckUp = EOCU.hour + EOCU.day * 24 + CheckUpDuration;
}

bool NormalTruck::IsFull()
{
	return (CargosQueue.GetCount() == TruckCapacity);
}


void NormalTruck::SetCargosCDT()
{
		Queue<Cargo*> TempQueue;
		Cargo* Temp;
		int SumOfUnloadTimes = 0;
		int CDTHrs = 0;
		while (CargosQueue.Dequeue(Temp))
		{
			TempQueue.Enqueue(Temp);
			SumOfUnloadTimes += Temp->GetLoadUnloadTime();
			CDTHrs = MovingTime.day * 24 + MovingTime.hour + Temp->GetDeliveryDistance() / Speed + SumOfUnloadTimes;
			Temp->SetCDT(Time(CDTHrs % 24, CDTHrs / 24));
		}
		while (TempQueue.Dequeue(Temp))
		{
			CargosQueue.enqueue(Temp, Temp->CalcPrio());
		}
	}
