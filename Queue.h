#pragma once

#include "Node.h"
#include <iostream>
#include "Cargo.h"
#include"Truck.h"
#include"NormalTruck.h"
#include"SpecialTruck.h"
#include"VIPTruck.h"

using namespace std;


template <class T>
class Queue 
{
	Node<T>* Rear;
	Node<T>* Front;
public:
	Queue()
	{
		Rear = nullptr;
		Front = nullptr;
	}
	bool Enqueue(T data)
	{
		Node<T>* NewNode = new Node<T>(data, nullptr);
		if (IsEmpty())
		{
			Front = NewNode;
		}
		else
		{
			Rear->SetNext(NewNode);
		}
		Rear = NewNode;
		return true;
	}

	bool Dequeue(T& data)
	{
		if (IsEmpty())
		{
			//T = NULL;
			return false;
		}
		Node<T>* NodeToBeDeleted = Front;
		if (Front == Rear)
			Rear = nullptr;
		Front = Front->GetNext();
		data = NodeToBeDeleted->GetData();
		delete NodeToBeDeleted;
		return true;
	}

	bool Peek(T& C)
	{
		if (IsEmpty())
		{
			C = nullptr;
			return false;
		}

		C = Front->GetData();
		return true;
	}

	bool IsEmpty()
	{
		if(!Front)
			return true;
		return false;
	}

	int GetCount()
	{
		int Counter = 0;
		Node<T>* Temp = Front;
		while (Temp)
		{
			Counter++;
			Temp = Temp->GetNext();
		}
		return Counter;
	}
	void Print()
	{
		Node<T>* Temp = Front;
		while (Temp)
		{
			cout << Temp->GetData();
			Temp = Temp->GetNext();
		}
	}
};

//      class specializtion to specify a copy for function Print using data and id for cargos only
template <>
class Queue <Cargo*>
{
	Node<Cargo*>* Rear;
	Node<Cargo*>* Front;
public:
	Queue()
	{
		Rear = nullptr;
		Front = nullptr;
	}
	bool Enqueue(Cargo* data)
	{
		Node<Cargo*>* NewNode = new Node<Cargo*>(data, nullptr);
		if (IsEmpty())
		{
			Front = NewNode;
		}
		else
		{
			Rear->SetNext(NewNode);
		}
		Rear = NewNode;
		return true;
	}

	bool Dequeue(Cargo*& data)
	{
		if (IsEmpty())
			return false;
		Node<Cargo*>* NodeToBeDeleted = Front;
		if (Front == Rear)
			Rear = nullptr;
		Front = Front->GetNext();
		data = NodeToBeDeleted->GetData();
		delete NodeToBeDeleted;
		return true;
	}

	bool Peek(Cargo*& C)
	{
		if (IsEmpty())
		{
			C = nullptr;
			return false;
		}

		C = Front->GetData();
		return true;
	}

	bool IsEmpty()
	{
		if (!Front)
			return true;
		return false;
	}

	int GetCount()
	{
		int Counter = 0;
		Node<Cargo*>* Temp = Front;
		while (Temp)
		{
			Counter++;
			Temp = Temp->GetNext();
		}
		return Counter;
	}

	//     fuction Print to Print according to the wanted format
	void Print()
	{
		Node<Cargo*>* Temp = Front;
		while (Temp)
		{
			if (!Temp->GetNext())
			{
				cout << Temp->GetData()->GetID();
				return;
			}
			cout << Temp->GetData()->GetID() << ",";
			Temp = Temp->GetNext();
		}
	}
	void SpecialPrint()
	{
		Node<Cargo*>* Temp = Front;
		while (Temp)
		{
			{
				switch (Temp->GetData()->GetCT())
				{
				case  'N':
					cout << " [";
					cout << Temp->GetData()->GetID() <<"]";
					break;
				case  'S':
					cout << " (";
					cout << Temp->GetData()->GetID() << ")";
					break;
				case  'V':
					cout << " {";
					cout << Temp->GetData()->GetID() << "}";
					break;
				}
			}
			Temp = Temp->GetNext();
		}

	}
};


template <>
class Queue <NormalTruck*>
{
	Node<NormalTruck*>* Rear;
	Node<NormalTruck*>* Front;
public:
	Queue()
	{
		Rear = nullptr;
		Front = nullptr;
	}
	bool Enqueue(NormalTruck* data)
	{
		Node<NormalTruck*>* NewNode = new Node<NormalTruck*>(data, nullptr);
		if (IsEmpty())
		{
			Front = NewNode;
		}
		else
		{
			Rear->SetNext(NewNode);
		}
		Rear = NewNode;
		return true;
	}

	bool Dequeue(NormalTruck*& data)
	{
		if (IsEmpty())
			return false;
		Node<NormalTruck*>* NodeToBeDeleted = Front;
		if (Front == Rear)
			Rear = nullptr;
		Front = Front->GetNext();
		data = NodeToBeDeleted->GetData();
		delete NodeToBeDeleted;
		return true;
	}

	bool Peek(NormalTruck*& C)
	{
		if (IsEmpty())
		{
			C = nullptr;
			return false;
		}

		C = Front->GetData();
		return true;
	}

	bool IsEmpty()
	{
		if (!Front)
			return true;
		return false;
	}

	int GetCount()
	{
		int Counter = 0;
		Node<NormalTruck*>* Temp = Front;
		while (Temp)
		{
			Counter++;
			Temp = Temp->GetNext();
		}
		return Counter;
	}

	//     fuction Print to Print according to the wanted format
	void Print()
	{
		Node<NormalTruck*>* Temp = Front;
		while (Temp)
		{
			if (!Temp->GetNext())
			{
				cout << Temp->GetData()->GetTID();
				return;
			}
			cout << Temp->GetData()->GetTID() << ",";
			Temp = Temp->GetNext();
		}
	}
	
};


template <>
class Queue <SpecialTruck*>
{
	Node<SpecialTruck*>* Rear;
	Node<SpecialTruck*>* Front;
public:
	Queue()
	{
		Rear = nullptr;
		Front = nullptr;
	}
	bool Enqueue(SpecialTruck* data)
	{
		Node<SpecialTruck*>* NewNode = new Node<SpecialTruck*>(data, nullptr);
		if (IsEmpty())
		{
			Front = NewNode;
		}
		else
		{
			Rear->SetNext(NewNode);
		}
		Rear = NewNode;
		return true;
	}

	bool Dequeue(SpecialTruck*& data)
	{
		if (IsEmpty())
			return false;
		Node<SpecialTruck*>* NodeToBeDeleted = Front;
		if (Front == Rear)
			Rear = nullptr;
		Front = Front->GetNext();
		data = NodeToBeDeleted->GetData();
		delete NodeToBeDeleted;
		return true;
	}

	bool Peek(SpecialTruck*& C)
	{
		if (IsEmpty())
		{
			C = nullptr;
			return false;
		}

		C = Front->GetData();
		return true;
	}

	bool IsEmpty()
	{
		if (!Front)
			return true;
		return false;
	}

	int GetCount()
	{
		int Counter = 0;
		Node<SpecialTruck*>* Temp = Front;
		while (Temp)
		{
			Counter++;
			Temp = Temp->GetNext();
		}
		return Counter;
	}

	//     fuction Print to Print according to the wanted format
	void Print()
	{
		Node<SpecialTruck*>* Temp = Front;
		while (Temp)
		{
			if (!Temp->GetNext())
			{
				cout << Temp->GetData()->GetTID();
				return;
			}
			cout << Temp->GetData()->GetTID() << ",";
			Temp = Temp->GetNext();
		}
	}

};

template <>
class Queue <VIPTruck*>
{
	Node<VIPTruck*>* Rear;
	Node<VIPTruck*>* Front;
public:
	Queue()
	{
		Rear = nullptr;
		Front = nullptr;
	}
	bool Enqueue(VIPTruck* data)
	{
		Node<VIPTruck*>* NewNode = new Node<VIPTruck*>(data, nullptr);
		if (IsEmpty())
		{
			Front = NewNode;
		}
		else
		{
			Rear->SetNext(NewNode);
		}
		Rear = NewNode;
		return true;
	}

	bool Dequeue(VIPTruck*& data)
	{
		if (IsEmpty())
			return false;
		Node<VIPTruck*>* NodeToBeDeleted = Front;
		if (Front == Rear)
			Rear = nullptr;
		Front = Front->GetNext();
		data = NodeToBeDeleted->GetData();
		delete NodeToBeDeleted;
		return true;
	}

	bool Peek(VIPTruck*& C)
	{
		if (IsEmpty())
		{
			C = nullptr;
			return false;
		}

		C = Front->GetData();
		return true;
	}

	bool IsEmpty()
	{
		if (!Front)
			return true;
		return false;
	}

	int GetCount()
	{
		int Counter = 0;
		Node<VIPTruck*>* Temp = Front;
		while (Temp)
		{
			Counter++;
			Temp = Temp->GetNext();
		}
		return Counter;
	}

	//     fuction Print to Print according to the wanted format
	void Print()
	{
		Node<VIPTruck*>* Temp = Front;
		while (Temp)
		{
			if (!Temp->GetNext())
			{
				cout << Temp->GetData()->GetTID();
				return;
			}
			cout << Temp->GetData()->GetTID() << ",";
			Temp = Temp->GetNext();
		}
	}

};