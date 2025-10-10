#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> freq(1001, 0);
    vector<long long> sum(1001, 0);
    
    for (int i = 0; i < N; i++) {
        int power;
        cin >> power;
        freq[power]++;
    }
    
    for (int i = 1; i <= 1000; i++) {
        sum[i] = (long long)i * freq[i];
    }
    
    vector<int> prefix_count(1001, 0);
    vector<long long> prefix_sum(1001, 0);
    
    for (int i = 1; i <= 1000; i++) {
        prefix_count[i] = prefix_count[i - 1] + freq[i];
        prefix_sum[i] = prefix_sum[i - 1] + sum[i];
    }
    
    int P;
    cin >> P;
    
    while (P--) {
        int m;
        cin >> m;
        if (m > 1000) m = 1000;
        cout << prefix_count[m] << " " << prefix_sum[m] << "\n";
    }
    
    return 0;
}