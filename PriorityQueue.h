#pragma once
#include"NodeP.h"
#include<iostream>
#include "Cargo.h"
using namespace std;


template<class T>
class PriorityQueue
{
    NodeP<T>* Front;
    NodeP<T>* Rear;
public:
    PriorityQueue()
    {
        Front = nullptr;
        Rear = nullptr;
    }

    bool IsEmpty()
    {
        return !Front;
    }

    //     Function enqueue that enqueue with respect to Priority
    void enqueue(T Val, int Prio=0)
    {
        NodeP<T>* NewNode = new NodeP<T>;
        NewNode->SetData(Val);
        NewNode->SetPriority(Prio);
        NewNode->SetNext(nullptr);
        if (IsEmpty())
        {
            Front = NewNode;
            Rear = NewNode;
            return;
        }
        NodeP<T>* Temp = Front;
        if (!Temp->GetNext() || Temp->GetPriority() < Prio)
        {
            if (Temp->GetPriority() < Prio)
            {
                NewNode->SetNext(Front);
                Front = NewNode;
                while (Temp->GetNext())
                {
                    Temp = Temp->GetNext();
                }
                Rear = Temp;
            }
            else
            {
                Temp->SetNext(NewNode);
                Rear = NewNode;
            }
            return;
        }
        while (Temp)
        {
            if (!Temp->GetNext())
                break;
            if (Temp->GetNext()->GetPriority() < Prio)
            {
                NewNode->SetNext(Temp->GetNext());
                Temp->SetNext(NewNode);
                if (NewNode->GetNext() == nullptr)
                    Rear = NewNode;
                return;
            }
            Temp = Temp->GetNext();
        }
        Rear->SetNext(NewNode);
        Rear = NewNode;
    }

    bool Dequeue(T& data)
    {
        if (IsEmpty())
            return false;
        NodeP<T>* NodeToBeDeleted = Front;
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

    int GetCount()
    {
        int Counter = 0;
        NodeP<T>* Temp = Front;
        while (Temp)
        {
            Counter++;
            Temp = Temp->GetNext();
        }
        return Counter;
    }

    void Print()
    {
        NodeP<T>* Temp = Front;
        while (Temp)
        {
            cout << Temp->GetData();
            Temp = Temp->GetNext();
        }
    }
};

//class specializtion to specify a copy for function enqueue for cargos only
template<>
class PriorityQueue <Cargo*>
{
    NodeP<Cargo*>* Front;
    NodeP<Cargo*>* Rear;
public:
    PriorityQueue()
    {
        Front = nullptr;
        Rear = nullptr;
    }

    bool IsEmpty()
    {
        return !Front;
    }

    //     Function enqueue that enqueue with respect to Priority
    void enqueue(Cargo* Val, int Prio = 0)
    {
        NodeP<Cargo*>* NewNode = new NodeP<Cargo*>;
        NewNode->SetData(Val);
        NewNode->SetPriority(Prio);
        NewNode->SetNext(nullptr);
        if (IsEmpty())
        {
            Front = NewNode;
            Rear = NewNode;
            return;
        }
        NodeP<Cargo*>* Temp = Front;
        if (!Temp->GetNext() || Temp->GetPriority() < Prio)
        {
            if (Temp->GetPriority() < Prio)
            {
                NewNode->SetNext(Front);
                Front = NewNode;
                while (Temp->GetNext())
                {
                    Temp = Temp->GetNext();
                }
                Rear = Temp;
            }
            else
            {
                Temp->SetNext(NewNode);
                Rear = NewNode;
            }
            return;
        }
        while (Temp)
        {
            if (!Temp->GetNext())
                break;
            if (Temp->GetNext()->GetPriority() < Prio)
            {
                NewNode->SetNext(Temp->GetNext());
                Temp->SetNext(NewNode);
                if (NewNode->GetNext() == nullptr)
                    Rear = NewNode;
                return;
            }
            Temp = Temp->GetNext();
        }
        Rear->SetNext(NewNode);
        Rear = NewNode;
    }

    bool Dequeue(Cargo*& data)
    {
        if (IsEmpty())
            return false;
        NodeP<Cargo*>* NodeToBeDeleted = Front;
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

    int GetCount()
    {
        int Counter = 0;
        NodeP<Cargo*>* Temp = Front;
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
        NodeP<Cargo*>* Temp = Front;
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