#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& vec, int left, int mid, int right){
    int i,j,k;
    int n1 = mid-left+1;
    int n2 = right-mid;

    vector<int> l_v(n1), r_v(n2);

    for(int i=0; i<n1; ++i)
        l_v[i] = vec[left+i];
    for(int j=0; j<n2; ++j)
        r_v[j] = vec[mid+1+j];

    i=0;
    j=0;
    k=left;

    while(i<n1 && j<n2){
        if(l_v[i] <= r_v[j]){ 
            vec[k] = l_v[i];
            i++;
        }
        else{
            vec[k] = r_v[j]; 
            j++;
        } 
        k++;
    }

    while(i<n1){
        vec[k] = l_v[i];
        i++;
        k++;
    }
    while(j<n2){
        vec[k] = r_v[j];
        j++;
        k++;
    }
}


void merge_sort(vector<int>& vec, int left, int right){
    if(left<right){
        int mid = left+(right-left)/2;

        merge_sort(vec,left,mid);
        merge_sort(vec,mid+1, right);

        merge(vec,left,mid,right);

    }
}

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    int f = v.size();

    merge_sort(v,0,f-1);

    for(auto i: v) cout << i << ' ';
    return 0;
}
