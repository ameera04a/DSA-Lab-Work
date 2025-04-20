#pragma once
#include<iostream>
using namespace std;

template<typename t>
class Queue
{
protected:
    t** arr;   // Array of pointers
    int size;
public:
    Queue(int size);
    virtual void enqueue(t* value) = 0;
    virtual t* dequeue() = 0;
    virtual void display() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual t* frontPeek() = 0;
    virtual t* rearPeek() = 0;

    virtual ~Queue(); // virtual destructor
};

template<typename t>
Queue<t>::Queue(int s) : size(s) {
    arr = new t * [size]; // Array of t* pointers
}

template<typename t>
Queue<t>::~Queue() {
    delete[] arr; // Only deleting array, not students
}

