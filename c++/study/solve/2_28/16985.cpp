// 2/27(화) Maaaaaaaaaze
// 백준 16985
#include <bits/stdc++.h>

using namespace std;
int answer = 10000, ez = 4, ey, ex;
const int N = 5;
const int MAX_N = 5;
const int MAX_D = 4;
const int dz[] = {0, 0, 0, 0, 1, -1};
const int dy[] = {-1, 0, 1, 0, 0, 0};
const int dx[] = {0, 1, 0, -1, 0, 0};

vector<pair<int, int>> sIdx;
vector<pair<int, int>> eIdx;

int v[] = {0, 1, 2, 3, 4};

// 5 * 5 미로가 0,1,2,3 네 방향에 5개
int maps[MAX_D][MAX_N][MAX_N][MAX_N];
int cube[MAX_N][MAX_N][MAX_N];
int visited[MAX_N][MAX_N][MAX_N];

struct D3 {
  int z, y, x;
};
queue<D3> q;

void miro() {
  int sy = 0, sx = 0;
  int cnt = 0;
  while (cnt < 4) {
    sy = sIdx[cnt].first;
    sx = sIdx[cnt].second;
    ey = eIdx[cnt].first;
    ex = eIdx[cnt].second;

    if (cube[0][sy][sx] == 1 && cube[4][ey][ex] == 1) {
      visited[0][sy][sx] = 1;
      D3 d = {0, sy, sx};
      q.push(d);
      while (q.size()) {
        int z = q.front().z;
        int y = q.front().y;
        int x = q.front().x;

        q.pop();
        if (ey == y && ex == x && ez == z) {
          answer = min(answer, visited[z][y][x]);
          while (q.size()) {
            q.pop();
          }
          break;
        }
        for (int i = 0; i < 6; i++) {
          int ny = y + dy[i];
          int nx = x + dx[i];
          int nz = z + dz[i];

          if (ny < 0 || nx < 0 || nz < 0 || ny >= N || nx >= N || nz >= N)
            continue;
          if (visited[nz][ny][nx]) continue;
          if (cube[nz][ny][nx] == 0) continue;

          visited[nz][ny][nx] = visited[z][y][x] + 1;
          D3 d = {nz, ny, nx};
          q.push(d);
        }
      }
    }
    cnt++;
  }
  return;
}

void rotate(vector<int> r) {
  if (r.size() == 5) {
    for (int k = 0; k < r.size(); k++) {
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          cube[k][i][j] = maps[r[k]][v[k]][i][j];
          visited[k][i][j] = 0;
        }
      }
    }

    miro();

    return;
  }

  for (int i = 0; i < 4; i++) {
    r.push_back(i);
    rotate(r);
    r.pop_back();
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  sIdx.push_back({0, 0});
  sIdx.push_back({0, 4});
  sIdx.push_back({4, 0});
  sIdx.push_back({4, 4});

  eIdx.push_back({4, 4});
  eIdx.push_back({4, 0});
  eIdx.push_back({0, 4});
  eIdx.push_back({0, 0});
  // input
  for (int k = 0; k < 5; k++) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> maps[0][k][i][j];
      }
    }
  }
  // rotate
  for (int d = 1; d < 4; d++) {
    for (int k = 0; k < 5; k++) {
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          maps[d][k][j][i] = maps[d - 1][k][4 - i][j];
        }
      }
    }
  }
  vector<int> r1;
  do {
    rotate(r1);
  } while (next_permutation(v, v + 5));
  if (answer == 10000) {
    cout << -1 << '\n';
  } else {
    cout << answer - 1 << '\n';
  }

  return 0;
}
