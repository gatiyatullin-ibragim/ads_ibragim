#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    vector<int> targets(t);
    for (int i = 0; i < t; i++) {
        cin >> targets[i];
    }
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    unordered_map<int, pair<int, int>> position_map;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            position_map[grid[i][j]] = {i, j};
        }
    }
    
    for (int target : targets) {
        if (position_map.find(target) != position_map.end()) {
            auto coord = position_map[target];
            cout << coord.first << " " << coord.second << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}