#include <bits/stdc++.h>

using namespace std;

int N, sx, sy, sec, weight = 2, eat;

const int MAX_N = 22;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int maps[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

bool cmp(pair<int, int> a, pair<int, int> b) {
  if (visited[a.first][a.second] < visited[b.first][b.second]) {
    return true;
  } else if (visited[a.first][a.second] == visited[b.first][b.second]) {
    if (a.first < b.first) {
      return true;
    } else if (a.first == b.first) {
      if (a.second < b.second) {
        return true;
      } else {
        return false;
      }
    } else {
      return false;
    }
  } else {
    return false;
  }
}

vector<pair<int, int>> pq;
queue<pair<int, int>> q;

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> maps[i][j];
      if (maps[i][j] == 9) {
        sy = i;
        sx = j;
        maps[i][j] = 0;
      }
    }
  }
  while (true) {
    visited[sy][sx] = 1;
    q.push({sy, sx});
    while (q.size()) {
      int ny = q.front().first;
      int nx = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int yy = ny + dy[i];
        int xx = nx + dx[i];

        if (yy < 0 || xx < 0 || yy >= N || xx >= N || visited[yy][xx]) continue;
        if (weight < maps[yy][xx]) continue;
        if (maps[yy][xx] != 0 && weight > maps[yy][xx]) {
          pq.push_back({yy, xx});
        }

        visited[yy][xx] = visited[ny][nx] + 1;
        q.push({yy, xx});
      }
    }

    if (pq.size() == 0) {
      cout << sec << '\n';
      break;
    }

    sort(pq.begin(), pq.end(), cmp);
    sy = pq[0].first;
    sx = pq[0].second;
    pq.clear();
    sec += (visited[sy][sx] - 1);
    eat++;
    maps[sy][sx] = 0;
    if (weight == eat) {
      weight++;
      eat = 0;
    }

    memset(visited, 0, sizeof(visited));
  }
  return 0;
}