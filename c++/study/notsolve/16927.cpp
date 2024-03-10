// 4 4 2
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16

#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 310;
const int MAX_R = 1210;
int N, M;
long R;
int answer[MAX_R][MAX_LEN][MAX_LEN];
int good[MAX_LEN][MAX_LEN];
int prob[MAX_LEN][MAX_LEN];
vector<int> space;
void rotate(int sy, int ey, int sx, int ex, long roll) {
  int divide_N = ey - sy + 1;
  int divide_M = ex - sx + 1;
  int r_case = roll % (divide_N * 2 + divide_M * 2 - 4);
  space.push_back(r_case);
  for (int in = 0; in < r_case; in++) {
    for (int t = 0; t < 4; t++) {
      if (t == 0) {
        for (int i = sy + 1; i <= ey; i++) {
          if (in == 0)
            answer[0][i][sx] = prob[i - 1][sx];
          else {
            answer[in][i][sx] = answer[in - 1][i - 1][sx];
          }
        }
      }

      if (t == 1) {
        for (int i = sx + 1; i <= ex; i++) {
          if (in == 0)
            answer[0][ey][i] = prob[ey][i - 1];
          else {
            answer[in][ey][i] = answer[in - 1][ey][i - 1];
          }
        }
      }

      if (t == 2) {
        for (int i = ey - 1; i >= sy; i--) {
          if (in == 0)
            answer[0][i][ex] = prob[i + 1][ex];
          else {
            answer[in][i][ex] = answer[in - 1][i + 1][ex];
          }
        }
      }

      if (t == 3) {
        for (int i = ex - 1; i >= sx; i--) {
          if (in == 0)
            answer[0][sy][i] = prob[sy][i + 1];
          else {
            answer[in][sy][i] = answer[in - 1][sy][i + 1];
          }
        }
      }
    }
  }
  // if (r_case == 0) {
  //   for (int i = sy; i <= ey; i++) {
  //     for (int j = sx; j <= ex; j++) {
  //       answer[0][i][j] = prob[i][j];
  //     }
  //   }
  // }
}

int main() {
  cin >> N >> M >> R;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> prob[i][j];
    }
  }
  memset(answer, -1, sizeof(answer));
  int t_case = min(N, M) / 2;
  for (int i = 0; i < t_case; i++) {
    rotate(i, N - i - 1, i, M - i - 1, R);
  }

  for (int k = 0; k < space.size(); k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (space[k] != 0) {
          if (answer[space[k] - 1][i][j] != -1 && good[i][j] == 0)
            good[i][j] = answer[space[k] - 1][i][j];
        }
      }
    }
  }
  int space_cnt = 0;
  for (auto it : space) {
    if (it == 0) {
      space_cnt++;
    }
  }

  if (space.size() == space_cnt) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << prob[i][j] << " ";
      }
      cout << '\n';
    }
  } else {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << good[i][j] << " ";
      }
      cout << '\n';
    }
  }
}