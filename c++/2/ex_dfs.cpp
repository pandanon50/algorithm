#include <bits/stdc++.h>

using namespace std;

int N;
int M;
int visited[100][100];
int compo[100][100];
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

void dfs(int y,int x) {
    visited[y][x] = 1;
    cout << "y : " << y << " x : " << x << '\n';
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(visited[ny][nx]) continue;
        if(compo[ny][nx] == 1) {
            dfs(ny,nx);
        }
    }
    return;
}

int main() {
   
   cin >> N >> M;
   int cnt = 0;
   for(int i = 0; i < N; i++) {
       for (int j = 0; j < M; j++) {
           cin >> compo[i][j];
       }
   }
   for(int i = 0; i < N; i++) {
       for (int j = 0; j < M; j++) {
           for(int k = 0; k < 4; k++) {
               if(visited[i][j] == 0 && compo[i][j]) {
                  dfs(i,j);
                  cnt++;
               }
           }
       }
   }
   cout << cnt << '\n';
}


// 1. 방문했는지 먼저 검사 
// void dfs_doldoldol(int here) {
//     visited[here] = 1;
//     for(int there : adj[here]) {
//         if(visited[here]) continue;
//         dfs(here);
//     }
// }

// 2. 일단 호출 후 방문했는지 검사
// void dfs_gogogo(int here) {
//     if(visited[here] == 1) return;
//     visited[here] = 1;
//     for(int there : adj[here]) {
//         dfs(here);
//     }
// }