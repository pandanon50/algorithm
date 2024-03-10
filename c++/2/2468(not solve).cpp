#include <bits/stdc++.h>

using namespace std;

int N,nx,ny,ret,result = 1;
const int MAX_MAP = 104;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int matrix[MAX_MAP][MAX_MAP];
int visited[MAX_MAP][MAX_MAP];


void dfs(int y, int x, int het) {
    
    visited[y][x] = 1;
    
    for(int i = 0; i < 4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
        if(matrix[ny][nx] > het) dfs(ny,nx,het);
        
    }
    return;
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    for(int he = 1; he < 101; he++) {
        // ret,visited 초기화
        ret = 0;
        ny = 0;
        nx = 0;
        for(int i = 0; i < MAX_MAP; i++) {
            for (int j = 0; j < MAX_MAP; j++) {
                visited[i][j] = 0;
            }
        }

        for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(i < 0 || i >= N || j < 0 || j >= N || visited[i][j]) continue;
                if(matrix[i][j] > he) {
                    dfs(i,j,he);
                    ret++;
                }
                
            }
        }
        result = max(result,ret);
    }
    cout << result << '\n';
    return 0;
}

// 반례 생각! 초기값 result는 1로