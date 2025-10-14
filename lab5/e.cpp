#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[largest])
        largest = l;
    if (r < n && arr[r] < arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

vector <int> a;
long long sum;

int main(){
    int q, k;
    cin >> q >> k;
    while(q--) {
        string s;
        cin >> s;
        if(s == "insert") {
            int n;
            cin >> n;
            if(a.size() < k) {
                a.push_back(n);
                sum += n;
                if(a.size() == k) {
                    for (int i = a.size() / 2 - 1; i >= 0; i--)
                        heapify(a, a.size(), i);
                }
            } else {
                if(a[0] < n) {
                    sum -= a[0];
                    a[0] = n;
                    sum += n;
                    heapify(a, a.size(), 0);
                }
            }
        } else {
            cout << sum << '\n';
        }
    }
}