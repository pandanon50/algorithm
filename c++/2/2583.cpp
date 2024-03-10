#include <bits/stdc++.h>

using namespace std;


int N,M,K,ny,nx,ret;
int cnt = 1;

const int MAX_LEN = 104;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

vector <int> v;

int matrix[MAX_LEN][MAX_LEN];
int visited[MAX_LEN][MAX_LEN];

void dfs(int y,int x) {
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        
        if(ny < 0 || ny >= M || nx >= N || nx < 0 || visited[ny][nx]) continue;
        if (matrix[ny][nx] != -1) {
            cnt++; dfs(ny,nx);
        }
    }

}

int main() {
    int sx,sy,ex,ey;
    cin >> M >> N >> K;
    
    for(int i = 0; i < K; i++) {
        cin >> sy >> sx >> ey >> ex;

        for(int j = sy; j < ey; j++) {
            for (int k = sx; k < ex; k++) {
                matrix[k][j] = -1;
            }
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if(i < 0 || i >= M || j >= N || j < 0 || visited[i][j]) continue;
            
            if (matrix[i][j] != -1) {
                dfs(i,j);
                v.push_back(cnt);
                cnt = 1;
            }
        }
    }

    sort(v.begin(),v.end());
    cout << v.size() << '\n';
    for(auto li : v) {
        cout << li << " ";
    }
    cout << '\n';

    return 0;
}