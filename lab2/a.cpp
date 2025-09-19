#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> v;
    for(int i=0; i<n; ++i){
        int a;
        cin >> a;
        v.push_back(a);
    }

    int x;
    cin >> x;

    vector<int> res;

    for(int i=0; i<v.size(); ++i){
        int b = abs(v[i]-x);
        res.push_back(b);
    }
    int idx = 0;
    int mn = res[0];

    for(int i=0; i<res.size(); ++i){
        if(res[i] < mn){
            mn = res[i];
            idx = i;
        }
    }
    cout << idx << endl;

    return 0;
}