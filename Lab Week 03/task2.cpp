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

template <typename Type>
class MyList : public List<Type> {
public:
    using List<Type>::arr;
    using List<Type>::maxSize;
    using List<Type>::currentSize;

    // Parameterized constructor with default arguments
    MyList(int size = 10) : List<Type>(size) {}

    // Copy constructor
    MyList(const MyList& other) : List<Type>(other) {}

    // Destructor
    ~MyList() {}

    // Adding element at the first index
    void addElementAtFirstIndex(Type element) {
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

    // Adding at the last index
    void addElementAtLastIndex(Type element) {
        if (currentSize >= maxSize) {
            cout << "List is full, cannot add at last index.\n";
            return;
        }
        arr[currentSize] = element;
        currentSize++;
    }

    // Removing element from the end
    Type removeElementFromEnd() override {
        if (currentSize == 0) {
            cout << "List is empty, cannot remove from end.\n";
            return Type();
        }
        currentSize--;
        return arr[currentSize];
    }

    // Removing element from the start
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

    // Check if the list is empty
    bool empty() {
        return currentSize == 0;
    }

    // Check if the list is full
    bool full() {
        return currentSize >= maxSize;
    }

    // Return the current size of the list
    int size() {
        return currentSize;
    }

    // Insert a value at a specific index
    bool insertAt(int index, Type value) {
        if (index < 0 || index > currentSize || currentSize >= maxSize) {
            return false; // Invalid index or list is full
        }
        // Shift elements to the right
        for (int i = currentSize; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        currentSize++;
        return true;
    }

    // Return the last element of the list
    Type last() {
        if (currentSize == 0) {
            cout << "List is empty, no last element.\n";
            return Type(); // Return default value
        }
        return arr[currentSize - 1];
    }

    // Search for a value in the list
    bool search(Type value) {
        for (int i = 0; i < currentSize; i++) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    MyList<int> myList(5);
    int choice, value, index;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Element at Last Index\n";
        cout << "2. Add Element at First Index\n";
        cout << "3. Remove Element from Start\n";
        cout << "4. Remove Element from End\n";
        cout << "5. Display List\n";
        cout << "6. Check if List is Empty\n";
        cout << "7. Check if List is Full\n";
        cout << "8. Get Current Size of List\n";
        cout << "9. Insert Element at Index\n";
        cout << "10. Get Last Element\n";
        cout << "11. Search for Element\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add at last index: ";
                cin >> value;
                myList.addElementAtLastIndex(value);
                break;
            case 2:
                cout << "Enter value to add at first index: ";
                cin >> value;
                myList.addElementAtFirstIndex(value);
                break;
            case 3:
                myList.removeElementFromStart();
                break;
            case 4:
                myList.removeElementFromEnd();
                break;
            case 5:
                cout << "List: ";
                myList.display();
                break;
            case 6:
                cout << (myList.empty() ? "List is empty." : "List is not empty.") << endl;
                break;
            case 7:
                cout << (myList.full() ? "List is full." : "List is not full.") << endl;
                break;
            case 8:
                cout << "Current size of the list: " << myList.size() << endl;
                break;
            case 9:
                cout << "Enter index to insert at: ";
                cin >> index;
                cout << "Enter value to insert: ";
                cin >> value;
                
                if (myList.insertAt(index, value)) {
                    cout << "Value inserted successfully.\n";
                } else {
                    cout << "Failed to insert value.\n";
                }
                break;
            case 10:
                cout << "Last element: " << myList.last() << endl;
                break;
            case 11:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (myList.search(value) ? "Value found in the list." : "Value not found in the list.") << endl;
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}