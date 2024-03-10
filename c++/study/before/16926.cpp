// 4 4 2
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16

#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 310;

int N, M, R;
int answer[MAX_LEN][MAX_LEN];
int prob[MAX_LEN][MAX_LEN];

void rotate() {
  for (int k = 0; k < R; k++) {
    int t_case = min(N, M) / 2;
    for (int in = 0; in < t_case; in++) {
      int sy = in;
      int ey = N - in - 1;
      int sx = in;
      int ex = M - in - 1;

      for (int t = 0; t < 4; t++) {
        if (t == 0) {
          for (int i = sy + 1; i <= ey; i++) {
            answer[i][sx] = prob[i - 1][sx];
          }
        }

        if (t == 1) {
          for (int i = sx + 1; i <= ex; i++) {
            answer[ey][i] = prob[ey][i - 1];
          }
        }

        if (t == 2) {
          for (int i = ey - 1; i >= sy; i--) {
            answer[i][ex] = prob[i + 1][ex];
          }
        }

        if (t == 3) {
          for (int i = ex - 1; i >= sx; i--) {
            answer[sy][i] = prob[sy][i + 1];
          }
        }
      }
    }
    for (int a = 0; a < N; a++) {
      for (int b = 0; b < M; b++) {
        prob[a][b] = answer[a][b];
      }
    }
  }
}

int main() {
  cin >> N >> M >> R;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> prob[i][j];
    }
  }
  rotate();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << answer[i][j] << " ";
    }
    cout << '\n';
  }
}