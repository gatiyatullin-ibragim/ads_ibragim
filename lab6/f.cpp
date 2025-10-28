#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>

using namespace std;

struct Student {
    string lastname;
    string firstname;
    double gpa;
};

int main() {
    int n;
    cin >> n;
    
    map<string, double> grade_points = {
        {"A+", 4.00},
        {"A", 3.75},
        {"B+", 3.50},
        {"B", 3.00},
        {"C+", 2.50},
        {"C", 2.00},
        {"D+", 1.50},
        {"D", 1.00},
        {"F", 0.00}
    };
    
    vector<Student> students;
    
    for (int i = 0; i < n; i++) {
        string lastname, firstname;
        int m;
        cin >> lastname >> firstname >> m;
        
        double total_points = 0.0;
        int total_credits = 0;
        
        for (int j = 0; j < m; j++) {
            string grade;
            int credits;
            cin >> grade >> credits;
            
            total_points += grade_points[grade] * credits;
            total_credits += credits;
        }
        
        double gpa = total_points / total_credits;
        students.push_back({lastname, firstname, gpa});
    }
    
    sort(students.rbegin(), students.rend(), [](const Student& a, const Student& b) {
        if (a.gpa != b.gpa) {
            return a.gpa > b.gpa; 
        }
        if (a.lastname != b.lastname) {
            return a.lastname < b.lastname;
        }
        return a.firstname < b.firstname; 
    });
    
    cout << fixed << setprecision(3);
    for (const auto& student : students) {
        cout << student.lastname << " " << student.firstname << " " << student.gpa << endl;
    }
    
    return 0;
}