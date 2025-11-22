#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<int>> dist(m, vector<int>(n, -1));

    queue<pair<int,int>> q;

    int mushrooms = 0;
    int max_time = 0;

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            cin >> a[i][j];

            if(a[i][j] == 2){
                q.push({i,j});
                dist[i][j] = 0;
            }
            else if(a[i][j] == 1){
                mushrooms++;
            }
        }
    }

    if(mushrooms == 0){
        cout << 0;
        return 0;
    }

    if(q.empty()){
        cout << -1;
        return 0;
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for(int k=0; k<4; ++k){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n){
                continue;
            }

            if(a[nx][ny] == 1 && dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                max_time = max(max_time, dist[nx][ny]);
                mushrooms--;

                a[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
    }

    if(mushrooms > 0){
        cout << -1 << endl;
    } else {
        cout << max_time << endl;
    }

    return 0;
}
