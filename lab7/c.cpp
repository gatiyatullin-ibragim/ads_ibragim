#include<iostream>
#include<map>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    map<string,double> grades;
    grades["A+"] = 4.00;
    grades["A"] = 3.75;
    grades["B+"] = 3.50;
    grades["B"] = 3.00;
    grades["C+"] = 2.50;
    grades["C"] = 2.00;
    grades["D+"] = 1.50;
    grades["D"] = 1.00;
    grades["F"] = 0;


    int n;
    cin >> n;

    vector<pair<double,pair<string,string>>> res;
    for(int i=0; i<n; ++i){
        string last_name, first_name;
        cin >> last_name >> first_name;
        int kolich;
        cin >> kolich;
        double gpa = 0;
        int sum_of_cr = 0;

        for(int j=0; j<kolich; ++j){
            string grade;
            cin >> grade;
            int credits;
            cin >> credits;
            sum_of_cr += credits;
            gpa += (grades[grade]*credits);
        }
        double gpa_ot = gpa/sum_of_cr;

        
        res.push_back(make_pair(gpa_ot, make_pair(last_name, first_name)));
    }


    sort(res.begin(), res.end());

    for(auto it : res){
        cout << it.second.first << ' ' <<it.second.second << ' ' << fixed << setprecision(3) << it.first << endl;
    }


}