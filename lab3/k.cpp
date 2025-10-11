#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool feasible(int L, const vector<long long>& arr, long long k) {
    long long sum = 0;
    int n = arr.size();
    for (int i = 0; i < L; i++) {
        sum += arr[i];
    }
    if (sum >= k) return true;
    for (int i = L; i < n; i++) {
        sum += arr[i] - arr[i - L];
        if (sum >= k) return true;
    }
    return false;
}

int main() {
    int n;
    long long k;
    cin >> n >> k;
    
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int left = 1, right = n;
    int ans = n;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (feasible(mid, arr, k)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}