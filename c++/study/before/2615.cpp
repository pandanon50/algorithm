#include <bits/stdc++.h>

// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 1 2 0 0 2 2 2 1 0 0 0 0 0 0 0 0 0 0
// 1 0 1 2 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
// 1 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 1 0 0 0 2 2 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

using namespace std;

const int N = 19;

int matrix[N][N];
int visited[N][N];
int exit_v[N][N];
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

vector<pair<int, int> > p;
vector<int> dol;
// 1 black , 2 white
void go(int y, int x, int dir, int color, int dol) {
  if (dol == 5) {
    for (int i = 0; i < 8; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny > N || nx > N || visited[ny][nx] ||
          exit_v[ny][nx])
        continue;

      if (abs(i - dir) == 4 && color == matrix[ny][nx]) {
        return;
      }
    }
    if (dir == 0) {
      if (p[0].second >= 0 && p[0].second < N && p[0].first + 1 >= 0 &&
          p[0].first + 1 < N) {
        if (matrix[p[0].first + 1][p[0].second] == color) {
          return;
        }
      }
    } else if (dir == 1) {
      if (p[0].second - 1 >= 0 && p[0].second - 1 < N && p[0].first + 1 >= 0 &&
          p[0].first + 1 < N) {
        if (matrix[p[0].first + 1][p[0].second - 1] == color) {
          return;
        }
      }
    } else if (dir == 2) {
      if (p[0].second - 1 >= 0 && p[0].second - 1 < N && p[0].first >= 0 &&
          p[0].first < N) {
        if (matrix[p[0].first][p[0].second - 1] == color) {
          return;
        }
      }
    } else if (dir == 3) {
      if (p[0].second - 1 >= 0 && p[0].second - 1 < N && p[0].first - 1 >= 0 &&
          p[0].first - 1 < N) {
        if (matrix[p[0].first - 1][p[0].second - 1] == color) {
          return;
        }
      }
    } else if (dir == 4) {
      if (p[0].second >= 0 && p[0].second < N && p[0].first - 1 >= 0 &&
          p[0].first - 1 < N) {
        if (matrix[p[0].first - 1][p[0].second] == color) {
          return;
        }
      }
    } else if (dir == 5) {
      if (p[0].second + 1 >= 0 && p[0].second + 1 < N && p[0].first - 1 >= 0 &&
          p[0].first - 1 < N) {
        if (matrix[p[0].first - 1][p[0].second + 1] == color) {
          return;
        }
      }
    } else if (dir == 6) {
      if (p[0].second + 1 >= 0 && p[0].second + 1 < N && p[0].first >= 0 &&
          p[0].first < N) {
        if (matrix[p[0].first][p[0].second + 1] == color) {
          return;
        }
      }
    } else if (dir == 7) {
      if (p[0].second + 1 >= 0 && p[0].second + 1 < N && p[0].first + 1 >= 0 &&
          p[0].first + 1 < N) {
        if (matrix[p[0].first + 1][p[0].second + 1] == color) {
          return;
        }
      }
    }
    cout << color << '\n';
    if (p[0].first < y) {
      if (p[0].second > x) {
        cout << y + 1 << " " << x + 1 << '\n';
      } else {
        cout << p[0].first + 1 << " " << p[0].second + 1 << '\n';
      }
    } else if (p[0].first == y) {
      if (p[0].second > x) {
        cout << y + 1 << " " << x + 1 << '\n';
      } else {
        cout << p[0].first + 1 << " " << p[0].second + 1 << '\n';
      }
    } else {
      if (p[0].second > x || p[0].second == x) {
        cout << y + 1 << " " << x + 1 << '\n';
      } else {
        cout << p[0].first + 1 << " " << p[0].second + 1 << '\n';
      }
    }
    exit(0);
  }

  for (int i = 0; i < 8; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny > N || nx > N || visited[ny][nx] ||
        exit_v[ny][nx])
      continue;
    if (matrix[ny][nx] == 0) continue;

    // 처음 들어왔을 때
    if (dir == -1) {
      visited[ny][nx] = 1;
      go(ny, nx, i, matrix[ny][nx], dol + 1);
      visited[ny][nx] = 0;
    } else {
      if ((dir == i || abs(i - dir) == 4) && color == matrix[ny][nx]) {
        visited[ny][nx] = 1;
        go(ny, nx, i, matrix[ny][nx], dol + 1);
        visited[ny][nx] = 0;
      }
    }
  }
  return;
}

int main() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> matrix[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (visited[i][j] == 0 && matrix[i][j] != 0) {
        p.push_back(make_pair(i, j));
        visited[i][j] = 1;
        go(i, j, -1, matrix[i][j], 1);
        exit_v[i][j] = 1;
        visited[i][j] = 0;
        p.pop_back();
      }
    }
  }
  cout << "0" << '\n';
}
