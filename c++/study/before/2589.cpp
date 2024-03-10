#include <bits/stdc++.h>

using namespace std;

int N, M, answer = -1, max_visit;

const int MAX_LEN = 52;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
char maps[MAX_LEN][MAX_LEN];
int visited[MAX_LEN][MAX_LEN];

queue<pair<int, int>> q;

void dfs() {
  while (q.size()) {
    int ny = q.front().first;
    int nx = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int cy = dy[i] + ny;
      int cx = dx[i] + nx;
      if (cy < 0 || cx < 0 || cy >= N || cx >= M || visited[cy][cx] ||
          maps[cy][cx] == 'W')
        continue;
      visited[cy][cx] = visited[ny][nx] + 1;
      q.push({cy, cx});
      max_visit = max(max_visit, visited[cy][cx]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> maps[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (maps[i][j] == 'L') {
        visited[i][j] = 1;
        q.push({i, j});
        dfs();
        answer = max(max_visit, answer);
        memset(visited, 0, sizeof(visited));
      }
    }
  }
  cout << answer - 1 << '\n';
}