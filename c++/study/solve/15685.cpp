#include <bits/stdc++.h>

using namespace std;

int N, nx, ny, dir, gen, answer;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};

const int MAX_LEN = 110;
const int MAX_GEN = 11;
int maps[MAX_LEN][MAX_LEN];
int visited[MAX_LEN][MAX_LEN];

vector<int> v[4][MAX_GEN];

int main() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j <= 10; j++) {
      if (j == 0) {
        v[i][j].push_back(i);
      } else {
        // 복사
        for (int a : v[i][j - 1]) {
          v[i][j].push_back(a);
        }
        // 뒤로 + 1씩
        vector<int> temp = v[i][j];
        for (int k = temp.size() - 1; k >= 0; k--) {
          if (temp[k] == 3) {
            v[i][j].push_back(0);
          } else
            v[i][j].push_back(temp[k] + 1);
        }
      }
    }
  }

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> nx >> ny >> dir >> gen;
    visited[ny][nx] = 1;
    for (int turn : v[dir][gen]) {
      nx = nx + dx[turn];
      ny = ny + dy[turn];

      visited[ny][nx] = 1;
    }
  }

  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      if (visited[i][j] == 1) {
        int cnt = 0;
        for (int di = 0; di <= 1; di++) {
          for (int dj = 0; dj <= 1; dj++) {
            if (i + di < 0 || i + di >= 101 || j + dj < 0 || j + dj >= 101)
              continue;
            if (visited[i + di][j + dj] == 1) cnt++;
          }
        }
        if (cnt == 4) {
          answer++;
        }
      }
    }
  }
  cout << answer << '\n';

  return 0;
}