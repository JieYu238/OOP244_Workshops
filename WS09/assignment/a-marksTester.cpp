#include <iostream>
#include "Marks.h"

using namespace std;
using namespace seneca;

int main() {
    // Step 1: Create a Marks object
    Marks studentMarks;

    // Step 2: Add some marks to the collection
    studentMarks.addMark("Math", 85)
        .addMark("Science", 92)
        .addMark("History", 78);

    // Step 3: Display the marks
    cout << "Displaying Student Marks:" << endl;
    cout << studentMarks << endl;

    // Step 4: Verify index operator
    cout << "Accessing Marks using the Index Operator:" << endl;
    cout << "Mark 1: " << studentMarks[0].title() << ", " << studentMarks[0].mark() << endl;
    cout << "Mark 2: " << studentMarks[1].title() << ", " << studentMarks[1].mark() << endl;

    // Step 5: Copy the Marks object and display
    Marks copiedMarks = studentMarks;
    cout << "Displaying Copied Marks:" << endl;
    cout << copiedMarks << endl;

    return 0;
}