// BOJ 4179 불!
// https://www.acmicpc.net/problem/4179
#include <bits/stdc++.h>

using namespace std;

int R, C;
const int MAX_RC = 1010;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

char dist[MAX_RC][MAX_RC];
int visited[MAX_RC][MAX_RC];
vector<pair<int, int>> fire;
queue<pair<int, int>> q;
pair<int, int> temp;
int main() {
  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> dist[i][j];
      if (dist[i][j] == 'J') {
        temp = {i, j};
      }
      if (dist[i][j] == 'F') {
        q.push({i, j});
        visited[i][j] = 1;
      }
    }
  }
  q.push({temp.first, temp.second});
  visited[temp.first][temp.second] = 1;
  while (q.size()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny >= R || ny < 0 || nx >= C || nx < 0) {
        if (dist[y][x] == 'F') continue;

        cout << visited[y][x] << '\n';
        exit(0);
      }
      if (dist[ny][nx] == 'F' || dist[ny][nx] == '#') continue;

      if (visited[ny][nx]) continue;
      if (dist[y][x] == 'F') {
        dist[ny][nx] = 'F';
        visited[ny][nx] = 1;
      } else {
        visited[ny][nx] = visited[y][x] + 1;
      }
      q.push({ny, nx});
    }
  }
  cout << "IMPOSSIBLE" << '\n';
  return 0;
}

// F와 J를 동시에 BFS
// 단 F가 있으면 넘어갈 수 없으므로 F를 먼저 확산 후 시작