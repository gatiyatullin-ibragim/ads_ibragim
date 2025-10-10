#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> x2(n);
    vector<long long> y2(n);

    for (int i = 0; i < n; ++i) {
        long long x1, y1;
        cin >> x1 >> y1 >> x2[i] >> y2[i];
    }

    long long left = 0, right = 1e9, ans = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (x2[i] <= mid && y2[i] <= mid)
                cnt++;
        }

        if (cnt >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans;
    return 0;
}