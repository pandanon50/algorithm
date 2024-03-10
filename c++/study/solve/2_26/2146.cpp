#include <bits/stdc++.h>

using namespace std;

int N, answer = 10000000;
const int MAX_N = 110;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int maps[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int bmaps[MAX_N][MAX_N];

queue<pair<int, int>> q;

void dfs(int y, int x, int a) {
  bmaps[y][x] = a;

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= N || nx >= N || bmaps[ny][nx]) continue;
    if (maps[ny][nx] == 0) continue;

    dfs(ny, nx, a);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> maps[i][j];
    }
  }
  int area = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (maps[i][j] == 1 && bmaps[i][j] == 0) {
        area++;
        dfs(i, j, area);
      }
    }
  }
  int nland = 0;
  // bmap -> bfs map으로
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (bmaps[i][j]) {
        nland = bmaps[i][j];
        visited[i][j] = 1;
        q.push({i, j});
        while (q.size()) {
          int y = q.front().first;
          int x = q.front().second;
          q.pop();
          for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (visited[ny][nx]) continue;
            if (bmaps[ny][nx] == nland) continue;

            if (bmaps[ny][nx] != 0 && bmaps[ny][nx] != nland) {
              answer = min(answer, visited[y][x]);
              continue;
            }
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
          }
        }
      }
      memset(visited, 0, sizeof(visited));
    }
  }
  cout << answer - 1 << '\n';
  return 0;
}