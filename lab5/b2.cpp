#include <iostream>
#include <set>
using namespace std;
multiset <int> ms;
int a[100001];
 
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        ms.insert(a[i]);
    }
    while(ms.size() > 1) {
        int y = -*ms.rbegin();
        ms.erase(ms.end());
        int x = -*ms.rbegin();
        ms.erase(ms.end());
        if(y > x) ms.insert(x - y);
    }
    if(ms.size() == 0) cout << 0 << endl;
    else cout << *ms.begin() << endl;
    return 0;
}