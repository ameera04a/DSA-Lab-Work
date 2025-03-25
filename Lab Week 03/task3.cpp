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
class CustomList : public List<Type> {
public:
    using List<Type>::arr;
    using List<Type>::maxSize;
    using List<Type>::currentSize;

    // Parameterized constructor with default arguments
    CustomList(int size = 10) : List<Type>(size) {}

    // Copy constructor
    CustomList(const CustomList& other) : List<Type>(other) {}

    // Destructor
    ~CustomList() {}

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

    // Function to check if a number is prime
    bool isPrime(Type num) {
        if (num <= 1) return false;
        for (Type i = 2; i * i <= num; i++) {
            if (num % i == 0) return false;
        }
        return true;
    }

    // Function to find the sum of prime numbers in the CustomList
    Type sum_ofPrime() {
        Type sum = 0;
        for (int i = 0; i < currentSize; i++) {
            if (isPrime(arr[i])) {
                sum += arr[i];
            }
        }
        return sum;
    }

    // Function to find the second maximum even number
    Type secondMaxEven() {
        Type max1 = -1, max2 = -1;
        for (int i = 0; i < currentSize; i++) {
            if (arr[i] % 2 == 0) {
                if (arr[i] > max1) {
                    max2 = max1;
                    max1 = arr[i];
                } else if (arr[i] > max2 && arr[i] != max1) {
                    max2 = arr[i];
                }
            }
        }
        if (max2 == -1) {
            cout << "Not enough even numbers.\n";
            return Type(); // Return default value
        }
        return max2;
    }
        // Function to find the second minimum odd number
        Type secondMinOdd() {
            Type min1 = -1, min2 = -1;
            for (int i = 0; i < currentSize; i++) {
                if (arr[i] % 2 != 0) { // Check if the number is odd
                    if (min1 == -1 || arr[i] < min1) {
                        min2 = min1;
                        min1 = arr[i];
                    } else if ((min2 == -1 || arr[i] < min2) && arr[i] != min1) {
                        min2 = arr[i];
                    }
                }
            }
            if (min2 == -1) {
                cout << "Not enough odd numbers.\n";
                return Type(); // Return default value
            }
            return min2;
        }
    
        // Function to print duplicates
        void printDuplicates() {
            cout << "Duplicate elements: ";
            bool foundDuplicate = false;
            for (int i = 0; i < currentSize; i++) {
                for (int j = i + 1; j < currentSize; j++) {
                    if (arr[i] == arr[j]) {
                        cout << arr[i] << " ";
                        foundDuplicate = true;
                        break; // Break to avoid printing the same duplicate multiple times
                    }
                }
            }
            if (!foundDuplicate) {
                cout << "No duplicates found.";
            }
            cout << endl;
        }
    
        // Function to rotate the CustomList clockwise
        void rotateClockwise(int r) {
            if (currentSize == 0) return; // No rotation needed for empty CustomList
            r = r % currentSize; // Normalize r
            if (r == 0) return; // No rotation needed
    
            // Rotate the first part
            Type* temp = new Type[currentSize];
            for (int i = 0; i < currentSize; i++) {
                temp[i] = arr[i];
            }
    
            for (int i = 0; i < currentSize; i++) {
                arr[(i + r) % currentSize] = temp[i];
            }
    
            delete[] temp;
        }
        // Function to rotate both halves of the CustomList anti-clockwise
        void rotateAntiClockwise(int rt) {
            if (currentSize == 0) return; // No rotation needed for empty CustomList
            rt = rt % currentSize; // Normalize rt
            if (rt == 0) return; // No rotation needed

            int mid = currentSize / 2;

            // Rotate the first half
            Type* firstHalf = new Type[mid];
            for (int i = 0; i < mid; i++) {
                firstHalf[i] = arr[i];
            }

            // Rotate the second half
            Type* secondHalf = new Type[currentSize - mid];
            for (int i = mid; i < currentSize; i++) {
                secondHalf[i - mid] = arr[i];
            }

            // Rotate first half anti-clockwise
            for (int i = 0; i < mid; i++) {
                arr[(i - rt + mid) % mid] = firstHalf[i];
            }

            // Rotate second half anti-clockwise
            for (int i = 0; i < currentSize - mid; i++) {
                arr[(i - rt + (currentSize - mid)) % (currentSize - mid) + mid] = secondHalf[i];
            }

            delete[] firstHalf;
            delete[] secondHalf;
        }
};


int main() {
    CustomList<int> myList(10); 
    int choice, value, index, r;

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
        cout << "12. Sum of Prime Numbers\n";
        cout << "13. Second Maximum Even Number\n";
        cout << "14. Second Minimum Odd Number\n";
        cout << "15. Print Duplicates\n";
        cout << "16. Rotate Clockwise\n";
        cout << "17. Rotate Anti-Clockwise\n";
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
            case 12:
                cout << "Sum of prime numbers: " << myList.sum_ofPrime() << endl;
                break;
            case 13:
                cout << "Second maximum even number: " << myList.secondMaxEven() << endl;
                break;
            case 14:
                cout << "Second minimum odd number: " << myList.secondMinOdd() << endl;
                break;
            case 15:
                myList.printDuplicates();
                break;
            case 16:
                cout << "Enter number of positions to rotate clockwise: ";
                cin >> r;
                myList.rotateClockwise(r);
                break;
            case 17:
                cout << "Enter number of positions to rotate anti-clockwise: ";
                cin >> r;
                myList.rotateAntiClockwise(r);
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