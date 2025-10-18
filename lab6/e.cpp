#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> v[i][j];

    for (int j = 0; j < m; ++j) {                 
        vector<int> col;
        for (int i = 0; i < n; ++i)
            col.push_back(v[i][j]);               
        sort(col.begin(), col.end(), greater<int>()); 

        for (int i = 0; i < n; ++i)
            v[i][j] = col[i];                     
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << v[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}
