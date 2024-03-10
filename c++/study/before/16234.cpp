#include <bits/stdc++.h>
using namespace std;

int N, L, R, sum, days;

const int MAX_LEN = 55;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int maps[MAX_LEN][MAX_LEN];
int visited[MAX_LEN][MAX_LEN];
vector<pair<int, int>> v;

void dfs(int y, int x, vector<pair<int, int>> &v) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
    if (visited[ny][nx]) continue;
    int diff = abs(maps[ny][nx] - maps[y][x]);

    if (diff >= L && diff <= R) {
      visited[ny][nx] = 1;
      sum += maps[ny][nx];
      v.push_back({ny, nx});
      dfs(ny, nx, v);
    }
  }
  return;
}

int main() {
  cin >> N >> L >> R;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> maps[i][j];
    }
  }

  while (true) {
    bool flag = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (visited[i][j] == 0) {
          v.clear();
          visited[i][j] = 1;
          sum = maps[i][j];
          v.push_back({i, j});
          dfs(i, j, v);
          if (v.size() == 1) continue;
          for (pair<int, int> b : v) {
            maps[b.first][b.second] = sum / v.size();
            flag = 1;
          }
        }
      }
    }
    if (!flag) break;
    days++;
  }
  cout << days << '\n';
  return 0;
}