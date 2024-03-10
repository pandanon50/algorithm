// 백준 14503
// https://www.acmicpc.net/problem/14503
// 로봇청소기

#include <bits/stdc++.h>

using namespace std;

int N, M, result, sy, sx, ndir;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int deg[] = {3, 0, 1, 2};
const int back[] = {2, 3, 0, 1};
const int MAX_NM = 55;

int maps[MAX_NM][MAX_NM];

bool search(int y1, int x1) {
  bool isM = false;

  for (int i = 0; i < 4; i++) {
    int ny = y1 + dy[i];
    int nx = x1 + dx[i];

    if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

    // 벽 or 청소함
    if (maps[ny][nx] == 1 || maps[ny][nx] == -1) continue;

    if (maps[ny][nx] == 0) {
      isM = true;
      break;
    }
  }
  return isM;
}

void dfs(int y, int x) {
  bool check = search(y, x);
  // 청소 안한칸 존재
  if (check) {
    for (int k = 0; k < 4; k++) {
      ndir = deg[ndir];
      int cy = y + dy[ndir];
      int cx = x + dx[ndir];

      if (cy < 0 || cx < 0 || cy >= N || cx >= M) continue;
      if (maps[cy][cx] == 1) continue;

      if (maps[cy][cx] == 0) {
        maps[cy][cx] = -1;
        result++;
        dfs(cy, cx);
      }
    }
  }
  // 모든 구역 청소
  else {
    int by = y + dy[back[ndir]];
    int bx = x + dx[back[ndir]];
    if (by < 0 || bx < 0 || by >= N || bx >= M) {
      cout << result << '\n';
      exit(0);
    }
    if (maps[by][bx] == 1) {
      cout << result << '\n';
      exit(0);
    }
    if (maps[by][bx] == -1) {
      dfs(by, bx);
    }
  }
  return;
}

int main() {
  cin >> N >> M;

  cin >> sy >> sx >> ndir;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> maps[i][j];
    }
  }
  maps[sy][sx] = -1;
  result++;
  dfs(sy, sx);

  return 0;
}