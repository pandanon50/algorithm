#include <bits/stdc++.h>

using namespace std;

int M, N, sy, sx, sd, ey, ex, ed;

const int MAX_NM = 110;

const int dy[] = {0, 0, 0, 1, -1};
const int dx[] = {0, 1, -1, 0, 0};

const int dir[5][5] = {{-1, -1, -1, -1, -1},
                       {-1, 0, 2, 1, 1},
                       {-1, 2, 0, 1, 1},
                       {-1, 1, 1, 0, 2},
                       {-1, 1, 1, 2, 0}};

int maps[MAX_NM][MAX_NM];
int visited[MAX_NM][MAX_NM][5];
struct Robot {
  int y, x, direct;
};
queue<Robot> q;

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> maps[i][j];
    }
  }

  cin >> sy >> sx >> sd;
  cin >> ey >> ex >> ed;

  Robot rb = {sy - 1, sx - 1, sd};
  visited[sy - 1][sx - 1][sd] = 1;
  q.push(rb);

  while (q.size()) {
    int y = q.front().y;
    int x = q.front().x;
    int direct = q.front().direct;

    if (y == ey - 1 && x == ex - 1) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
          cout << visited[i][j][4] << " ";
        }
        cout << '\n';
      }

      cout << visited[y][x][ed] << '\n';
      exit(0);
    }
    q.pop();

    for (int i = 1; i <= 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= M || maps[ny][nx]) continue;
      if (visited[ny][nx][i]) continue;
      // Go
      if (i == direct) {
        visited[ny][nx][i] = visited[y][x][direct];
        Robot rb1 = {ny, nx, direct};
        q.push(rb1);
      } else {
        visited[ny][nx][i] = visited[y][x][direct] + dir[direct][i] + 1;
        Robot rb1 = {ny, nx, direct};
        q.push(rb1);
      }
    }
  }
  return 0;
}