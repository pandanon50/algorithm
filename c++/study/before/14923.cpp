#include <bits/stdc++.h>

using namespace std;

int N, M, Hx, Hy, Ex, Ey;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

const int MAX_NM = 1010;
int maps[MAX_NM][MAX_NM];
int visited[MAX_NM][MAX_NM][2];
struct Go {
  int y, x, magic;
};
queue<Go> q;

int main() {
  cin >> N >> M;
  cin >> Hy >> Hx;
  cin >> Ey >> Ex;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> maps[i][j];
    }
  }
  visited[Hy - 1][Hx - 1][0] = 1;
  Go g = {Hy - 1, Hx - 1, 0};
  q.push(g);
  while (q.size()) {
    int y = q.front().y;
    int x = q.front().x;
    int magic = q.front().magic;

    if (y == Ey - 1 && x == Ex - 1) {
      cout << visited[y][x][magic] - 1 << '\n';
      exit(0);
    }

    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx][magic])
        continue;
      int staff = magic;
      if (magic == 0) {
        if (maps[ny][nx] == 1) {
          visited[ny][nx][magic + 1] = visited[y][x][magic] + 1;
          staff += 1;
        } else {
          visited[ny][nx][magic] = visited[y][x][magic] + 1;
        }
      } else {
        if (maps[ny][nx] == 0) {
          visited[ny][nx][magic] = visited[y][x][magic] + 1;
        } else
          continue;
      }
      Go g1 = {ny, nx, staff};
      q.push(g1);
    }
  }
  cout << -1 << '\n';
  return 0;
}