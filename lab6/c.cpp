#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];  // 23 20 1 34  65
    }

    sort(arr, arr+n); // 1 20 23 34 65

    vector<int> v;
    for(int i=0; i<n-1; ++i){
        v.push_back(arr[i+1]-arr[i]);
    }

    sort(v.begin(), v.end());

    for(int i=0; i<n-1; ++i){
        if(arr[i+1] - arr[i] == v[0]){
            cout << arr[i] <<' '<<arr[i+1]<< ' ';
        }
    }
    cout << endl;


    return 0;
}