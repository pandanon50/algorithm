#include <bits/stdc++.h>

using namespace std;

int H,W,ny,nx;

const int MAX_LEN = 104;
int visited[MAX_LEN][MAX_LEN];
char matrix[MAX_LEN][MAX_LEN];

void dfs(int y,int x,int time) {
    
    nx = x + 1;

    if(y < 0 || nx < 0 || y >= H || x >= W || visited[y][nx] != -1) return;
    if(matrix[y][nx] == 'c') return;

    visited[y][nx] = time + 1;
    dfs(y,nx,time + 1);
}

int main() {
    cin >> H >> W;

    for (int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> matrix[i][j];
        }
    }
    
    memset(visited,-1,sizeof(visited));

    for (int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(matrix[i][j] == 'c' && visited[i][j] == -1) {
                visited[i][j] = 0;
                dfs(i,j,0);
            }
        }
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << visited[i][j] << " ";
        }
        cout << '\n';
    }


}
