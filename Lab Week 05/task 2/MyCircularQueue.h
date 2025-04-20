#pragma once

#include "Queue.h"

template<typename t>
class MyCircularQueue : public Queue<t>
{
    int front, rear;
    using Queue<t>::arr;
    using Queue<t>::size;
public:
    MyCircularQueue(int s);
    bool isFull();
    bool isEmpty();
    void enqueue(t* value);
    t* dequeue();
    int sizeOfQueue();
    t* frontPeek();
    t* rearPeek();
    void display();
};

template<typename t>
MyCircularQueue<t>::MyCircularQueue(int s) : Queue<t>(s), front(-1), rear(-1) {}

template<typename t>
bool MyCircularQueue<t>::isFull() {
    return (rear+1)%size == front;
}

template<typename t>
bool MyCircularQueue<t>::isEmpty() {
    return front == -1;
}

template<typename t>
void MyCircularQueue<t>::enqueue(t* value) {
    if (isFull()) {
        cout << "Queue is full.\n";
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % size;
    arr[rear] = value;
}

template<typename t>
t* MyCircularQueue<t>::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return nullptr;
    }
    t* temp = arr[front];
    if (front == rear) { // Only one element
        front = rear = -1;
    }
    else {
        front = (front + 1) % size;
    }
    return temp;
}

template<typename t>
void MyCircularQueue<t>::display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    int i;
    for ( i = front; i != rear; i=(i+1)%size ){
        arr[i]->displayCustomer(); // arr[i] is t* (pointer)
    }
    arr[i]->displayCustomer();
}

template<typename t>
int MyCircularQueue<t>::sizeOfQueue() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return -1;
    }
    //starts from font as soon as rear is detected it breaks loop so rear remains to be included
    int count = 0;
    int i;
    for (i = front; i != rear; i = (i + 1) % size) {
         
        count++;
    }
    count++; //rear
    return count;
}
template<typename t>
t* MyCircularQueue<t>::frontPeek() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return nullptr;
    }
    return arr[front];
}
template<typename t>
t* MyCircularQueue<t>::rearPeek() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return nullptr;
    }

    return arr[rear];
}