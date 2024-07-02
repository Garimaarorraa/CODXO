#include<bits/stdc++.h>
using namespace std;

// Function to calculate grade points based on grades
int calculateGradePoints(char grade) {
    switch (grade) {
        case 'A': return 10;
        case 'B': return 8;
        case 'C': return 6;
        case 'D': return 4;
        case 'E': return 2;
        case 'F': return 0;
        default: return 0; // If an invalid grade is entered
    }
}

int main() {
    cout<<"!...................WELCOME TO CGPA CALCULATOR PAGE......................!"<<endl;
    int numCourses;
    cout << "Enter Number of Courses Including Labs(practical): ";
    cin >> numCourses;

    vector<int> credits(numCourses);
    vector<char> grades(numCourses);

    // Input for each course
    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter credit for course " << i + 1 << ": ";
        cin >> credits[i];
        cout << "Enter grade you got (A, B, C, D, E, F) for course " << i + 1 << ": ";
        cin >> grades[i];
    }

    // Calculate total grade points and total credits
    int totalGradePoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < numCourses; ++i) {
        totalGradePoints += calculateGradePoints(grades[i]) * credits[i];
        totalCredits += credits[i];
    }

    // Calculate CGPA
    float cgpa = static_cast<float>(totalGradePoints) / totalCredits;

    // Output CGPA
    cout << "Your CGPA is : " << cgpa << endl;

    return 0;
}

