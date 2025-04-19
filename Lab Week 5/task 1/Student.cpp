#include "Student.h"
#include <cstdlib> // for rand()
#include <ctime>   // for time()

Student::Student(string n) : score(0), time(0) {
    name = n;
}

void Student::generateScoreTime() {
    score = rand() % 101;        // random score between 0 and 100
    time = (rand() % 91) + 10;    // random time between 10 and 100
}

void Student::displayStudent() {
    cout << "\nName: " << name
        << "\nScore: " << score
        << "\nTime: " << time << " minutes\n";
}
