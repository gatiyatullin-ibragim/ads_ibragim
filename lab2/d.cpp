#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    unordered_map<int,int> fr;
    for(int x : v){
        fr[x]++;
    }

    int maxcnt = 0;

    for(auto &p : fr){
        maxcnt = max(maxcnt, p.second);
    }

    vector<int> res;
    for(auto &p : fr){
        if(p.second == maxcnt){
            res.push_back(p.first);
        }
    }

    sort(res.begin(), res.end(), greater<int>());

    for(int x : res){
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
