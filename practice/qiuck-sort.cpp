#include<iostream>
using namespace std;

int partition(int* arr, int low, int high){
    int pivot = arr[high];

    int x = low-1;

    for (int i=low; i<=high; ++i){
        if(arr[i] < pivot){
            x++;
            swap(arr[x], arr[i]);
        }
    }
    swap(arr[x+1], arr[high]);
    return x+1;
}


void quick_sort(int *array, int low, int high){
    if(low<high){
        int array_partition = partition(array,low, high);
        quick_sort(array, low, array_partition-1);
        quick_sort(array, array_partition+1, high);
    }
}

int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }


    quick_sort(arr, 0, n);
    
    for(int i=0; i<n; ++i){
        cout << arr[i] << ' ';
    }

    return 0;
}

