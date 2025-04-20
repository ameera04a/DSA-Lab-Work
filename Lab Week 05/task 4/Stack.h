#pragma once
#include<string>
#include<iostream>
using namespace std;

class Stack {
private:
    int top;
    int capacity;
    char* arr;
public:
    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};
