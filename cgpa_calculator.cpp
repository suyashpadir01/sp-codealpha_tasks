#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "===== CGPA Calculator =====" << endl;

    cout << "Enter the number of courses: ";
    cin >> n;

    vector<string> courseName(n);
    vector<float> grade(n), credit(n);

    float totalCredits = 0;
    float totalGradePoints = 0;

    // Input course details
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Course " << i + 1 << " Name: ";
        cin >> courseName[i];

        cout << "Enter Grade Point (0 - 10): ";
        cin >> grade[i];

        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    // Calculate CGPA
    float cgpa = totalGradePoints / totalCredits;

    // Display Results
    cout << "\n\n===== Course Details =====" << endl;
    cout << left << setw(15) << "Course"
         << setw(15) << "Grade Point"
         << setw(15) << "Credits" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(15) << courseName[i]
             << setw(15) << grade[i]
             << setw(15) << credit[i] << endl;
    }

    cout << "\nTotal Credits      : " << totalCredits << endl;
    cout << "Total Grade Points : " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "Final CGPA         : " << cgpa << endl;

    return 0;
}