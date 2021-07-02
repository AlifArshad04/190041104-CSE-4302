#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define PASSMARK 30

// Task 3
// Assume that the students in your class are taking six courses this semester. You are asked to write a class called "StudentResult"
// that can process the marks a student received in those courses and determine whether he/she will pass or fail the semester.
class StudentResult
{
    // Private members:
private:
    // passingMark: static int (The baseline mark to pass a course. It will be the same for all the courses)
    // subjectMark: integer array. (Contains the marks obtained in the courses)
    // fail : bool (Boolean variable indicating whether the student has passed or failed)
    static int passingMark;
    int subjectMark[6];
    bool fail;

    // Public members:
public:
    // setMarks() method that will set marks for the students
    void setMarks()
    {
        cout << "Enter OOP marks: ";
        cin >> subjectMark[0];
        cout << "Enter DS marks: ";
        cin >> subjectMark[1];
        cout << "Enter DBMS marks: ";
        cin >> subjectMark[2];
        cout << "Enter COA marks: ";
        cin >> subjectMark[3];
        cout << "Enter LA marks: ";
        cin >> subjectMark[4];
        cout << "Enter EDC marks: ";
        cin >> subjectMark[5];
        fail = *min_element(subjectMark, subjectMark + 6) < passingMark;

        //if (subjectMark[0] < passingMark || subjectMark[1] < passingMark || subjectMark[2] < passingMark || subjectMark[3] < passingMark || subjectMark[4] < passingMark || subjectMark[5] < passingMark)
    }
    // displayMarks() method that will display the marks
    void displayMarks()
    {
        cout << "OOP marks: " << subjectMark[0] << '\n';
        cout << "DS marks: " << subjectMark[1] << '\n';
        cout << "DBMS marks: " << subjectMark[2] << '\n';
        cout << "COA marks: " << subjectMark[3] << '\n';
        cout << "LA marks: " << subjectMark[4] << '\n';
        cout << "EDC marks: " << subjectMark[5] << '\n';
    }
    // checkPassing() method that will display whether the student successfully passed the semester or not
    bool checkPassing()
    {
        return fail;
    }
};

int StudentResult::passingMark = PASSMARK;

int main()
{
    StudentResult sr1;
    sr1.setMarks();
    sr1.displayMarks();
    cout << "Fail Status: " << sr1.checkPassing() << '\n';

    return 0;
}