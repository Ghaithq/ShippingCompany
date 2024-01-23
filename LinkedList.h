#pragma once
#include "Node.h"
#include "Cargo.h"
#include"Truck.h"

template <class T>
class LinkedList
{
	Node<T>* Head;
public:
	LinkedList()
	{
		Head = nullptr;
	}

	bool IsEmpty()
	{
		return (Head == nullptr);
	}

	bool insert(T data)
	{
		Node<T>* NewNode = new Node<T>(data, nullptr);
		if (IsEmpty())
		{
			Head = NewNode;
			return true;
		}
		Node<T>* Temp = Head;
		while (Temp->GetNext())
			Temp = Temp->GetNext();
		Temp->SetNext(NewNode);
		return true;
	}

	bool InsertFirst(T data)
	{
		Node<T>* NewNode = new Node<T>(data, nullptr);
		if (IsEmpty())
		{
			Head = NewNode;
		}
		else
		{
			NewNode->SetNext(Head);
			Head = NewNode;
		}
		return true;
	}
	T PeekFront()
	{
		return Head;
	}

	T  Delete(T val)
	{
		if (!isfound(val))
		{
			return;
		}

		if (Head->GetNext() == nullptr)
		{
			Head = nullptr;
			return;
		}

		Node<T>* temp = Head;

		while (temp->GetNext() != nullptr)
		{
			if (temp->GetData() == val)
			{
				temp->GetData() = temp->GetNext()->GetData();
				temp->GetNext() = temp->GetNext()->GetNext();
				return;
			}
			if (temp->GetNext()->GetNext() == nullptr)
			{
				temp->GetNext() = nullptr;
				break;
			}
			temp = temp->GetNext();
		}
	}



	bool RemoveFirst(T& Data)
	{
		if (IsEmpty())
			return false;

		Node<T>* NodeToBeDeleted = Head;
		Data = NodeToBeDeleted->GetData();
		Head = Head->GetNext();
		delete NodeToBeDeleted;
		return true;
	}

	int GetCount()
	{
		int Counter = 0;
		Node<T>* Temp = Head;
		while (Temp)
		{
			Counter++;
			Temp = Temp->GetNext();
		}
		return Counter;
	}

	void Print()
	{
		Node<T>* Temp = Head;
		while (Temp)
		{
			cout << Temp->GetData();
			Temp = Temp->GetNext();
		}
	}
};



//      class specializtion to specify a copy for function delete using id for cargos only
template <>
class LinkedList <Cargo*>
{
	Node<Cargo*>* Head;

public:
	LinkedList()
	{
		Head = nullptr;
	}

	bool IsEmpty()
	{
		return (Head == nullptr);
	}

	bool insert(Cargo* data)
	{
		Node<Cargo*>* NewNode = new Node<Cargo*>(data, nullptr);
		if (IsEmpty())
		{
			Head = NewNode;
			return true;
		}
		Node<Cargo*>* Temp = Head;
		while (Temp->GetNext())
			Temp = Temp->GetNext();
		Temp->SetNext(NewNode);
		return true;
	}

	bool InsertFirst(Cargo* data)
	{
		Node<Cargo*>* NewNode = new Node<Cargo*>(data, nullptr);
		if (IsEmpty())
		{
			Head = NewNode;
		}
		else
		{
			NewNode->SetNext(Head);
			Head = NewNode;
		}
		return true;
	}

	//     Function Delete(id) to delete node associated with this id
	Cargo* Delete(int id)
	{
		Node<Cargo*>* temp = Head;

		if (IsEmpty())
			return nullptr;
		if (temp->GetData()->GetID() == id)
		{
			Head = temp->GetNext();
			return (temp->GetData());
		}
		Node<Cargo*>* NodeToBeDeleted;
		while (temp->GetNext())
		{
			if (temp->GetNext()->GetData()->GetID() == id)
			{
				NodeToBeDeleted = temp->GetNext();
				temp->SetNext(NodeToBeDeleted->GetNext());
				return (NodeToBeDeleted->GetData());
			}
			temp = temp->GetNext();
		}
		return nullptr;
	}

	int GetPosition(int ID)
	{
		Node<Cargo*>* temp = Head;
		int i = 0;
		while (temp)
		{
			i++;
			if (temp->GetData()->GetID() == ID)
			{
				return i;
			}
			temp = temp->GetNext();
		}
		return -1;
	}

	bool RemoveFirst(Cargo*& Data)
	{
		if (IsEmpty())
		{
			Data = nullptr;
			return false;
		}

		Node<Cargo*>* NodeToBeDeleted = Head;
		Data = NodeToBeDeleted->GetData();
		Head = Head->GetNext();
		delete NodeToBeDeleted;
		return true;
	}

	int GetCount()
	{
		int Counter = 0;
		Node<Cargo*>* Temp = Head;
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
		Node<Cargo*>* Temp = Head;
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
};

