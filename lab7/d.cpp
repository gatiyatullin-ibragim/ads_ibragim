#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    map<int, int> freqA, freqB;

    for (int x : a) freqA[x]++;
    for (int x : b) freqB[x]++;

    for (auto [num, countA] : freqA) {
        if (freqB.count(num)) {
            int common = min(countA, freqB[num]);
            for (int i = 0; i < common; ++i)
                cout << num << ' ';
        }
    }

    cout << endl;
    return 0;
}
