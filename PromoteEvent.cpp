#include "PromoteEvent.h"
#include "Company.h"


bool PromoteEvent::Execute(Company& Comp)
{
	//removing the cargo from the normal waiting list if found by ID

	bool Check = true;
	if (Comp.GetNormalLoadingTruck())
	{
		int Index = Comp.GetWaitingIndex(ID);
		int Cap;
		Truck* TempTruck;
		TempTruck = Comp.GetNormalLoadingTruck();

		if (dynamic_cast<NormalTruck*>(TempTruck))
			Cap = NormalTruck::GetTruckCapacity();
		if (dynamic_cast<SpecialTruck*>(TempTruck))
			Cap = SpecialTruck::GetTruckCapacity();
		if (dynamic_cast<VIPTruck*>(TempTruck))
			Cap = VIPTruck::GetTruckCapacity();
		Check = Cap - TempTruck->GetCargoCount() < Index;
	}

	if (Check)
	{
		Cargo* CargoToBePromoted = Comp.RemoveWNC(ID);
		if (CargoToBePromoted)
		{
			//changing the cargo type into VIP

			CargoToBePromoted->SetCargoType('V');

			//increasing the cost of the cargo

			CargoToBePromoted->SetCost(CargoToBePromoted->GetCost() + ExtraCost);

			//adding the cargo into the VIP list
			int Priority = 10000 * ((CargoToBePromoted->GetCost()) / (CargoToBePromoted->GetDeliveryDistance() * (EventTime.day * 24.0 + EventTime.hour)));
			Comp.enqueueWVC(CargoToBePromoted, Priority);

			return true;
		}
		return false;
	}
}

void PromoteEvent::SetParameters(int id, int EC)
{
	ID = id;
	ExtraCost = EC;
}