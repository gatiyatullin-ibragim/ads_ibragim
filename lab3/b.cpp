#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDivide(vector<int>& arr, int k, int mid) {
    int currentSum = 0;
    int blocks = 1; 

    for (int x : arr) {
        if (x > mid) return false; 
        if (currentSum + x > mid) {
            blocks++;
            currentSum = x;
        } else {
            currentSum += x;
        }
    }

    return blocks <= k; 
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int low = *max_element(arr.begin(), arr.end()); 
    int high = 0;
    for (int x : arr) high += x; 

    while (low < high) {
        int mid = (low + high) / 2;

        if (canDivide(arr, k, mid))
            high = mid; 
        else
            low = mid + 1; 
    }

    cout << low;
    return 0;
}
