#include <iostream>
#include <set>
using namespace std;
multiset <long long> ms;
int a[200001];
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        ms.insert(a[i]);
    }
    long long cost = 0;
    while(ms.size() > 1) {
        long long mini1 = *ms.begin();
        ms.erase(ms.begin());
        long long mini2 = *ms.begin();
        ms.erase(ms.begin());
        ms.insert(mini1 + mini2);
        cost += mini1 + mini2;
    }
    cout << cost << '\n';
    return 0;
}