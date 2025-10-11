#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N;
    long long H;
    cin >> N >> H;
    
    vector<long long> bags(N);
    long long max_bars = 0;
    for (int i = 0; i < N; i++) {
        cin >> bags[i];
        if (bags[i] > max_bars) max_bars = bags[i];
    }
    
    long long left = 1, right = max_bars;
    long long ans = max_bars;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long total_hours = 0;
        
        for (long long b : bags) {
            total_hours += (b + mid - 1) / mid; 
        }
        
        if (total_hours <= H) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}