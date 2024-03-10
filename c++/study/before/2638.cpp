// 2638 치즈
#include <bits/stdc++.h>

using namespace std;

int N, M, sec;

const int MAX_NM = 110;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int maps[MAX_NM][MAX_NM];
int visited[MAX_NM][MAX_NM];
queue<pair<int, int>> q;

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> maps[i][j];
    }
  }
  bool flag = true;
  while (true) {
    flag = false;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (maps[i][j] == 1) {
          visited[i][j] = 1;
          q.push({i, j});
          while (q.size()) {
            int cnt = 0;
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
              int ny = y + dy[i];
              int nx = x + dx[i];

              if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
              if (visited[ny][nx]) continue;

              if (maps[ny][nx] == 0) {
                cnt++;
                continue;
              }
              visited[ny][nx] = 1;
              q.push({ny, nx});
            }
            if (cnt >= 2) {
              maps[y][x] = 0;
              flag = true;
            }
          }
        }
      }
    }
    if (!flag) break;

    sec++;
    memset(visited, 0, sizeof(visited));
  }

  cout << sec << '\n';
}