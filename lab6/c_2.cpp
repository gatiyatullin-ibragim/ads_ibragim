#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void sorting_1(int n, int arr[]){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n-i-1; ++j){
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }   
}

void sorting(vector<int>& v){
    for(int i=0; i<v.size(); ++i){
        for(int j=0; j<v.size()-i-1; ++j){
            if(v[j] > v[j+1]) swap(v[j], v[j+1]);
        }
    }   
}



int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];  // 23 20 1 34  65
    }

    sorting_1(n, arr); // 1 20 23 34 65

    vector<int> v;
    for(int i=0; i<n-1; ++i){
        v.push_back(arr[i+1]-arr[i]);
    }

    sorting(v);

    for(int i=0; i<n-1; ++i){
        if(arr[i+1] - arr[i] == v[0]){
            cout << arr[i] <<' '<<arr[i+1]<< ' ';
        }
    }
    cout << endl;


    return 0;
}