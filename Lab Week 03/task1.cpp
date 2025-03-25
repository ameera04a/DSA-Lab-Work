#include <iostream>
using namespace std;

template <typename Type>
class List {
protected:
    Type* arr;
    int maxSize;
    int currentSize;

public:
   
    List(int size = 10) : maxSize(size), currentSize(0) {
        arr = new Type[maxSize];
    }

    // Copy constructor
    List(const List& other) {
        maxSize = other.maxSize;
        currentSize = other.currentSize;
        arr = new Type[maxSize];
        for (int i = 0; i < currentSize; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Virtual destructor
    virtual ~List() {
        delete[] arr;
    }

    // Pure virtual functions
    virtual void addElementAtFirstIndex(Type) = 0;
    virtual void addElementAtLastIndex(Type) = 0;
    virtual Type removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    void display() {
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Dummy class which inherits List
template <typename Type>
class DummyList : public List<Type> {
public:
    using List<Type>::arr;
    using List<Type>::maxSize;
    using List<Type>::currentSize;

    DummyList(int size = 10) : List<Type>(size) {}

    // adding element at 1st index
    void addElementAtFirstIndex(Type element)  {
        if (currentSize >= maxSize) {
            cout << "List is full, cannot add at first index.\n";
            return;
        }
        // Shifting elements to the right
        for (int i = currentSize; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = element;
        currentSize++;
    }

    // adding at the end
    void addElementAtLastIndex(Type element)  {
        if (currentSize >= maxSize) {
            cout << "List is full, cannot add at last index.\n";
            return;
        }
        arr[currentSize] = element;
        currentSize++;
    }

    // removing element from end
    Type removeElementFromEnd() override {
        if (currentSize == 0) {
            cout << "List is empty, cannot remove from end.\n";
            return Type();
        }
       
        currentSize--;
        return arr[currentSize];
    }

    // removing element from start
    void removeElementFromStart() override {
        if (currentSize == 0) {
            cout << "List is empty, cannot remove from start.\n";
            return;
        }
        // Shift elements to the left
        for (int i = 0; i < currentSize - 1; i++) {
            arr[i] = arr[i + 1];
        }
        currentSize--;
    }
};

// Main Function
int main() {
    DummyList<int> list(5);

    // Adding elements
    list.addElementAtLastIndex(560);
    list.addElementAtLastIndex(209);
    list.addElementAtFirstIndex(465);
    list.addElementAtLastIndex(390);
    
    cout << "List after adding elements: ";
    list.display();

    // Removing elements
    list.removeElementFromStart();
    cout << "List after removing first element: ";
    list.display();

    list.removeElementFromEnd();
    cout << "List after removing last element: ";
    list.display();

    return 0;
}
