#pragma once

template <class T>
class NodeP
{
    T Data;
    int Priority;
    NodeP* Next;

public:
    NodeP(T val, int pri, NodeP<T>* N)
    {
        SetData(val);
        SetPriority(pri);
        SetNext(N);
    }
    NodeP()
    {
        Next = nullptr;
    }
    void SetData(T val)
    {
        Data = val;
    }
    void SetPriority(int val)
    {
        Priority = val;
    }
    void SetNext(NodeP<T>* N)
    {
        Next = N;
    }
    T GetData()
    {
        return Data;
    }
    int GetPriority()
    {
        return Priority;
    }
    NodeP<T>* GetNext()
    {
        return Next;
    }
};