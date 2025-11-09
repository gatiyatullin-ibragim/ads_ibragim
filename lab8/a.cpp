
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

long long h(string s) {
    long long r = 0, p = 1, M = 1e9 + 7;
    for (char c : s) {
        r = (r + (c - 47) * p) % M;
        p = p * 11 % M;
    }
    return r;
}

int main() {
    long long n;
    cin >> n;
    
    string a[2*n];
    
    set<string> st;
    
    for(int i=0; i<n*2; ++i){
        cin >> a[i];
        st.insert(a[i]);
    }

    for(int i=0; i<2*n; ++i){
        long long hash_val = h(a[i]);
        string hash_str = to_string(hash_val);

        if(st.count(hash_str) && a[i] != hash_str)
            cout << "Hash of string \"" << a[i] << "\" is " << hash_str << endl;
    }

                 
    return 0;
}