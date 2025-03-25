#include <iostream>
#include <string> 
using namespace std;

// Template function for binary search
template <typename T>
int binarySearch(T arr[], int n, T value) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; //finding mid point

        if (arr[mid] == value) {
            return mid; // Return the index if the value is found
        } else if (arr[mid] < value) {
            low = mid + 1; // Search in the upper half
        } else {
            high = mid - 1; // Search in the lower half
        }
    }
    return -1; // Return -1 if the value is not found
}

// Function to print the search result
template <typename T>
void printSearchResult(int index, T value) {
    if (index != -1) {
        cout << "Value " << value << " found at index: " << index << endl;
    } else {
        cout << "Value " << value << " not found in the array." << endl;
    }
}

int main() {
    // Test with an integer array (sorted) of size 5
    int intArray[5] = {11, 12, 22, 25, 64};
    int intKey = 22;
    int intIndex = binarySearch(intArray, 5, intKey);
    printSearchResult(intIndex, intKey);

    // Test with a float array (sorted) of size 4
    float floatArray[4] = {0.57, 1.62, 2.71, 3.14};
    float floatKey = 2.71;
    int floatIndex = binarySearch(floatArray, 4, floatKey);
    printSearchResult(floatIndex, floatKey);

    // Test with a string array (sorted) of size 4
    string stringArray[4] = {"apple", "banana", "grape", "orange"};
    string stringKey = "banana";
    int stringIndex = binarySearch(stringArray, 4, stringKey);
    printSearchResult(stringIndex, stringKey);

    return 0;
}