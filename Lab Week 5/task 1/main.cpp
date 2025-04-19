#include "MyQueue.h"
#include "Student.h"
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int size;
    cout << "Enter the number of students participating in the quiz: ";
    cin >> size;
    cin.ignore();

    MyQueue<Student> waitingQueue(size);
    MyQueue<Student> completedQueue(size);

    Student** allStudents = new Student * [size];  // dynamic array of pointers
    for (int i = 0; i < size; ++i) {
        allStudents[i] = nullptr;  // initialize all to nullptr
    }

    int currentAddedStudents = 0;  // how many students have been added

    int choice;
    Student* s;
    
    do {
        cout << "\n===== QUIZ COMPETITION MENU =====\n";
        cout << "1. Add a student to the waiting queue\n";
        cout << "2. Start the quiz and generate scores\n";
        cout << "3. Display scores, names, and time taken\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        string name;

        switch (choice) {
        case 1:
            if (currentAddedStudents >= size) {
                cout << "All students are already added. Cannot add more.\n";
                break;
            }
            cout << "Enter student name: ";
            getline(cin, name);

            s = new Student(name);
            allStudents[currentAddedStudents++] = s;   // track
            waitingQueue.enqueue(s);                  // enqueue
            break;

        case 2:
            s = waitingQueue.dequeue();
            if (s != nullptr) {
                s->generateScoreTime();
                completedQueue.enqueue(s);
            }
            else {
                cout << "Quiz has ended. All students have completed!" << endl;
            }
            break;

        case 3:
            completedQueue.display();
            break;

        case 4:
            cout << "Exiting the program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Please select 1-4.\n";
        }
    } while (choice != 4);

    // Manual memory cleanup
    for (int i = 0; i < currentAddedStudents; i++) {
        delete allStudents[i];
    }
    delete[] allStudents;  // delete array itself
    allStudents = nullptr;

    /*cout << "\nAll students deleted successfully.\n";*/

    system("pause");
    return 0;
}
