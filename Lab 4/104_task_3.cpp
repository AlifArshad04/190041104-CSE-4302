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
    static int highestMark[6];
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
        for (int i = 0; i < 6; ++i)
        {
            if (highestMark[i] < subjectMark[0])
            {
                highestMark[i] = subjectMark[i];
            }
        }

        //if (subjectMark[0] < passingMark || subjectMark[1] < passingMark || subjectMark[2] < passingMark || subjectMark[3] < passingMark || subjectMark[4] < passingMark || subjectMark[5] < passingMark)
    }
    // displayMarks() method that will display the marks
    void displayMarks()
    {
        cout << "OOP obtained marks: " << subjectMark[0] << " ";
        cout << "OOP hightest marks: " << highestMark[0] << '\n';

        cout << "DS obtained marks: " << subjectMark[1] << " ";
        cout << "DS hightest marks: " << highestMark[1] << '\n';

        cout << "DBMS obtained marks: " << subjectMark[2] << " ";
        cout << "DBMS hightest marks: " << highestMark[2] << '\n';

        cout << "COA obtained marks: " << subjectMark[3] << " ";
        cout << "COA hightest marks: " << highestMark[3] << '\n';

        cout << "LA obtained marks: " << subjectMark[4] << " ";
        cout << "LA hightest marks: " << highestMark[4] << '\n';

        cout << "EDC obtained marks: " << subjectMark[5] << " ";
        cout << "EDC hightest marks: " << highestMark[5] << '\n';
    }
    // checkPassing() method that will display whether the student successfully passed the semester or not
    bool checkPassing()
    {
        return fail;
    }
};

int StudentResult::passingMark = PASSMARK;
int StudentResult::highestMark[6] = {0};

int main()
{
    StudentResult sr1, sr2;
    sr1.setMarks();
    sr2.setMarks();
    sr1.displayMarks();
    cout << "Fail Status: " << sr1.checkPassing() << '\n';
    sr2.displayMarks();
    cout << "Fail Status: " << sr2.checkPassing() << '\n';

    return 0;
}