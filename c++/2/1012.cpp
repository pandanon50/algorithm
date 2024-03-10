#include <bits/stdc++.h>

using namespace std;

int tcase,N,M,bae,k,p,nx,ny;

const int MAX_MAP = 54;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int matrix[MAX_MAP][MAX_MAP];
int visited[MAX_MAP][MAX_MAP];

void dfs(int y,int x) {

    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >=M || visited[ny][nx]) continue;
        if(matrix[ny][nx] == 1) {
            dfs(ny,nx);
        }
    }
}

int main(){
    
    cin >> tcase;    

    while(tcase--) {
        int ret = 0;
        
        cin >> M >> N >> bae;

        for(int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] = 0;
                visited[i][j] = 0;
            }
        }

        for(int i = 0; i < bae; i++) {
            cin >> k >> p;
            matrix[p][k] = 1;
        }
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(i < 0 || i >= N || j < 0 || j >= M || visited[i][j]) continue;
                if(matrix[i][j] == 1) {
                    ret++; dfs(i,j);
                }
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
