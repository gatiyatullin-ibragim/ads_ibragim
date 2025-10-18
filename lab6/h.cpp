#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char> v(n);

    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    char a;
    cin >> a;

    sort(v.begin(), v.end());


    char ans = v[0];

    for(int i=0; i<v.size(); ++i){
        if(v[i] > a){
            ans = v[i];
            break;
        }
    }

    cout << ans << ' ';

    cout << endl;
    

    return 0;
}