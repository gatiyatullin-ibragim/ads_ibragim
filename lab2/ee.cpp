#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string name;
    set<string> st; 

    for (int i = 0; i < n; ++i) {
        cin >> name;
        st.insert(name);
    }

    cout << "All in all: " << st.size() << endl;
    cout << "Students:" << endl;

    for (auto &names : st) {
        cout << names << endl;
    }

    return 0;
}
