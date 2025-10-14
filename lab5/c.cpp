#include <iostream>
#include <set>
using namespace std;
multiset <int> ms;
int a[100001];
long long sum;
 
int main()
{
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        ms.insert(-a[i]);
    } 
    while(x > 0) {
        int maxi = -*ms.begin();
        sum += maxi;
        ms.erase(ms.begin());
        if(maxi > 1) ms.insert(1 - maxi);
        x--;
    }
    cout << sum;
    return 0;
}