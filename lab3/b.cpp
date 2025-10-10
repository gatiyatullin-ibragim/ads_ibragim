#include <iostream>
#include <vector>
using namespace std;

bool canDivide(vector<long long>& a, int k, long long maxSum) {
    long long currentSum = 0;
    int blocks = 1; 

    for (long long num : a) {
        if (currentSum + num > maxSum) {
            blocks++;           
            currentSum = num;   
        } else {
            currentSum += num;
        }
    }

    return blocks <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    long long low = 0, high = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        low = max(low, a[i]);  
        high += a[i];         
    }

    long long ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (canDivide(a, k, mid)) {
            ans = mid;       
            high = mid - 1; 
        } else {
            low = mid + 1;   
        }
    }

    cout << ans << endl;
    return 0;
}
