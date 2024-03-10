#include <bits/stdc++.h>

using namespace std;

int N,M;
const int MAX_LEN = 1010;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int matrix[MAX_LEN][MAX_LEN];
int visited[MAX_LEN][MAX_LEN];
queue <pair<int,int> > q;
int main() {
    cin >> N >> M;
    int sy,sx = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] == 0) visited[i][j] = 0;
            else if(matrix[i][j] == 1) {
                visited[i][j] = -1;
            }
            else {
                sy = i;
                sx = j;
            }
        }
    }

    visited[sy][sx] = 0;
    q.push(make_pair(sy,sx));
    while(q.size()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx] != -1) continue;
            visited[ny][nx] = 0;
            visited[ny][nx] = visited[y][x] + 1;
            q.push(make_pair(ny,nx));
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << visited[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}