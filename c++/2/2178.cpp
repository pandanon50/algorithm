#include <bits/stdc++.h>

using namespace std;

int N,M;
int visited[100][100];
int matrix[100][100];

const int dy[] = {-1,0,1,0};
const int dx[] = {0,1,0,-1};

int main() {

    cin >> N >> M;
    string buffer;

    for(int i = 0; i < N; i++) {
        cin >> buffer;
        for(int j = 0; j < buffer.length(); j++) {
            matrix[i][j] = buffer[j] - 48;
        }
    }
    queue <pair<int,int>> q;
    visited[0][0] = 1;
    q.push({0,0});
    while(q.size()) {
        int x,y = 0;
        tie(y,x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(visited[ny][nx] == 0 && matrix[ny][nx] == 1) {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            } 
        }
    }
    cout << visited[N - 1][M - 1] << '\n';  
    return 0;
}

// 붙어있는 스트링 교안 참고..
