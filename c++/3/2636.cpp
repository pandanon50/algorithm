// BOJ 2636 치즈
// https://www.acmicpc.net/problem/2636

#include <bits/stdc++.h>

using namespace std;
const int MAX_NM = 110;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int N, M;
int dist[MAX_NM][MAX_NM];
int visited[MAX_NM][MAX_NM];
vector<pair<int, int>> v;
queue<pair<int, int>> q;

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> dist[i][j];
    }
  }
  bool check = true;
  int cnt = 0;
  int ch = 0;
  while (true) {
    for (pair<int, int> dis : v) {
      dist[dis.first][dis.second] = 0;
      ch++;
    }
    v.clear();
    memset(visited, 0, sizeof(visited));
    visited[0][0] = 1;
    q.push({0, 0});

    check = true;
    while (q.size()) {
      int y = q.front().first;
      int x = q.front().second;
      q.pop();

      for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
        if (visited[ny][nx]) continue;

        if (dist[ny][nx] == 1) {
          check = false;
          visited[ny][nx] = 1;
          ch += 1;
          v.push_back({ny, nx});
          continue;
        }
        if (dist[ny][nx] == 0) {
          q.push({ny, nx});
          visited[ny][nx] = 1;
        }
      }
    }

    if (check) {
      cout << cnt << '\n';
      cout << ch << '\n';
      break;
    }
    cnt++;
    ch = 0;
  }

  return 0;
}