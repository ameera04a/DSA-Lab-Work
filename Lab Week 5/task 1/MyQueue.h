#pragma once
#include "Queue.h"

template<typename t>
class MyQueue : public Queue<t>
{
    int front, rear;
    using Queue<t>::arr;
    using Queue<t>::size;
public:
    MyQueue(int s);
    bool isFull();
    bool isEmpty();
    void enqueue(t* value);
    t* dequeue();
    void display();
};

template<typename t>
MyQueue<t>::MyQueue(int s) : Queue<t>(s), front(-1), rear(-1) {}

template<typename t>
bool MyQueue<t>::isFull() {
    return rear == size - 1;
}

template<typename t>
bool MyQueue<t>::isEmpty() {
    return front == -1;
}

template<typename t>
void MyQueue<t>::enqueue(t* value) {
    if (isFull()) {
        cout << "Queue is full.\n";
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    arr[rear] = value;
}

template<typename t>
t* MyQueue<t>::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return nullptr;
    }
    t* temp = arr[front];
    if (front == rear) { // Only one element
        front = rear = -1;
    }
    else {
        front++;
    }
    return temp;
}

template<typename t>
void MyQueue<t>::display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    for (int i = front; i <= rear; i++) {
        arr[i]->displayStudent(); // arr[i] is t* (pointer)
    }
}
