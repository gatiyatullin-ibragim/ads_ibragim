#include<iostream>
#include<vector>
using namespace std;


int main(){

    int a,b;
    cin >> a;

    vector<int> v1(a);
    for(int i=0; i<a; ++i){
        cin >> v1[i];
    }
    cin >> b;

    vector<int> v2(b);
    for(int i=0; i<b; ++i){
        cin >> v2[i];
    }

    
    
    int i=0;
    int j=0;

    vector<int> res;

    while(i < a && j < b){
        if(v1[i] < v2[j]) res.push_back(v1[i]), i++;
        else res.push_back(v2[j]), j++;
    }
    while(j<b){
        res.push_back(v2[j++]);
    }
    while(i<a){
        res.push_back(v1[i++]);
    }
    
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << ' ';
    }
    cout << endl;



    return 0;
}