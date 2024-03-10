#include <bits/stdc++.h>

using namespace std;

int N, M, answer, direction, sec;
const int MAX_N = 52;
// 2,4,6,8 (대각선)
const int dy[] = {2, 0, -1, -1, -1, 0, 1, 1, 1};
const int dx[] = {2, -1, -1, 0, 1, 1, 1, 0, -1};

queue<pair<int, int>> move_q;
queue<pair<int, int>> bug_q;

int maps[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void move_cloud() {
  while (move_q.size()) {
    int ny = move_q.front().first;
    int nx = move_q.front().second;

    move_q.pop();
    ny = ny + (dy[direction] * sec) % N;
    nx = nx + (dx[direction] * sec) % N;

    if (ny < 0)
      ny += N;
    else if (ny >= N)
      ny -= N;

    if (nx < 0)
      nx += N;
    else if (nx >= N)
      nx -= N;
    visited[ny][nx] = 1;
    bug_q.push({ny, nx});
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j]) maps[i][j] += 1;
    }
  }

  return;
}

void bug_cloud() {
  while (bug_q.size()) {
    int cnt = 0;
    int ny = bug_q.front().first;
    int nx = bug_q.front().second;
    bug_q.pop();
    for (int i = 1; i < 5; i++) {
      int cy = ny + dy[i * 2];
      int cx = nx + dx[i * 2];
      if (cy < 0 || cx < 0 || cy >= N || cx >= N || maps[cy][cx] == 0) continue;
      cnt++;
    }
    maps[ny][nx] += cnt;
  }
}

void make_cloud() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (maps[i][j] >= 2 && visited[i][j] == 0) {
        move_q.push({i, j});
        maps[i][j] -= 2;
      }
    }
  }
}

void go() {
  memset(visited, 0, sizeof(visited));
  move_cloud();

  bug_cloud();

  make_cloud();
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> maps[i][j];
    }
  }
  move_q.push({N - 1, 0});
  move_q.push({N - 1, 1});
  move_q.push({N - 2, 0});
  move_q.push({N - 2, 1});
  for (int i = 0; i < M; i++) {
    cin >> direction >> sec;
    go();
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      answer += maps[i][j];
    }
  }
  cout << answer << '\n';
}