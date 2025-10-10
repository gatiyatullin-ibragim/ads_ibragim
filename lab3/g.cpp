#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, f;
    cin >> n >> f;
    vector<int> a(n);
    int max_a = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
    }
    
    int left = 1, right = max_a;
    int ans = max_a;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        long long total_flights = 0;
        for (int x : a) {
            total_flights += (x + mid - 1) / mid;
        }
        if (total_flights <= f) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}