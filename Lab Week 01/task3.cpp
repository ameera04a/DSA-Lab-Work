#include <iostream>
#include <string>
using namespace std;

// Template function for linear search
template <typename T>
int linearSearch(T arr[], int n, T value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i; // Return the index if the value is found
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
    // Test with an integer array of size 5
    int intArray[5] = {64, 25, 12, 22, 11};
    int intKey = 12;
    int intIndex = linearSearch(intArray, 5, intKey);
    printSearchResult(intIndex, intKey);

    // Test with a float array of size 4
    float floatArray[4] = {3.14, 2.71, 1.62, 0.57};
    float floatKey = 1.62;
    int floatIndex = linearSearch(floatArray, 4, floatKey);
    printSearchResult(floatIndex, floatKey);

    // Test with a string array of size 4
    string stringArray[4] = {"apple", "orange", "banana", "grape"};
    string stringKey = "grape";
    int stringIndex = linearSearch(stringArray, 4, stringKey);
    printSearchResult(stringIndex, stringKey);

    return 0;
}