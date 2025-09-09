#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

string process(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '#') {
            if (!st.empty()) st.pop();
        } else {
            st.push(c);
        }
    }
    string result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s, t;
    cin >> s >> t;

    if (process(s) == process(t)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
