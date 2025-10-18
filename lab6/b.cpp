#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    
    int n1,n2;
    cin >> n1 >> n2;

    vector<bool> used(max(n1,n2));

    vector<int> arr1(n1);
    vector<int> arr2(n2);
    for(int i=0; i<n1; ++i){
        cin >> arr1[i];
    }
    for(int i=0; i<n2; ++i){
        cin >> arr2[i];
    }
    vector<int> res;
    if(n1>n2){
        swap(n1, n2);
        swap(arr1, arr2);
    }

    for(int i=0; i<n1; ++i){
        for(int j=0; j<n2; ++j){
            if(arr1[i] == arr2[j] && used[j]==false){
                res.push_back(arr1[i]);
                used[j]=true;
                break;
            }
        }
    }
    sort(res.begin(), res.end());
    
    for(int i=0; i<res.size(); ++i){
        cout << res[i] << ' ';
    }
    cout << endl;

    return 0;
}