#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

int main() {
    int n;
    cin >> n;
    
    vector<Date> dates;
    
    for (int i = 0; i < n; i++) {
        string date_str;
        cin >> date_str;
        
        int day, month, year;
        char dash1, dash2;
        stringstream ss(date_str);
        ss >> day >> dash1 >> month >> dash2 >> year;
        
        dates.push_back({day, month, year});
    }
    
    sort(dates.begin(), dates.end(), [](const Date& a, const Date& b) {
        if (a.year != b.year) {
            return a.year < b.year;
        }
        if (a.month != b.month) {
            return a.month < b.month;
        }
        return a.day < b.day;
    });
    
    for (const auto& date : dates) {
        cout << setw(2) << setfill('0') << date.day << "-"
             << setw(2) << setfill('0') << date.month << "-"
             << date.year << endl;
    }
    
    return 0;
}