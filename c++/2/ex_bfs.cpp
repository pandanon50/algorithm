#include <bits/stdc++.h>

using namespace std;

int N,M,start_y,start_x,end_y,end_x;
int visited[100][100];
int matrix[100][100];
queue <pair<int,int>> q;
const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};


   


int main() {
    cin >> N >> M;
    cin >> start_y >> start_x;
    cin >> end_y >> end_x;

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
    int x,y = 0;
    visited[start_y][start_x] = 1;
    q.push({start_y,start_x});
    while(q.size()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny > N || nx < 0 || nx > M) continue;
            if(visited[ny][nx] == 0 && matrix[ny][nx] == 1) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx})
            }
        }
    }
    cout << visited[end_y][end_x] + 1 << '\n';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << visited[i][j] << " ";
        }
        cout << '\n';
    }
}