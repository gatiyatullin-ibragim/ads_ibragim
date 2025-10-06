#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; // количество тестов
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> freq(26, 0);
        queue<char> q;

        for (int i = 0; i < n; i++) {
            char ch;
            cin >> ch;

            if (ch < 'a' || ch > 'z') {
                cout << "-1 ";
                continue;
            }

            freq[ch - 'a']++;
            q.push(ch);

            while (!q.empty() && freq[q.front() - 'a'] > 1)
                q.pop();

            if (q.empty())
                cout << "-1 ";
            else
                cout << q.front() << " ";
        }

        cout << endl;
    }

    return 0;
}
