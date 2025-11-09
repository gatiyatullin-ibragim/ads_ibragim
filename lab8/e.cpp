#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> h(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    
    string s = "";
    // First character
    s += char(97 + h[1]);
    
    for (int k = 2; k <= N; k++) {
        long long diff = h[k] - h[k - 1];
        long long pow2 = 1LL << (k - 1); // 2^(k-1)
        long long val = diff / pow2;
        s += char(97 + val);
    }
    
    cout << s << endl;
    
    return 0;
}