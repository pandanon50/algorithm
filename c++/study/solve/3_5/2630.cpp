#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 130;
int N;
int maps[MAX_N][MAX_N];
int cnt[2];

int check(int y, int x, int len) {
  int cnt = maps[y][x];
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (maps[i + y][j + x] != cnt) return -1;
    }
  }
  return cnt;
}

void divide(int y, int x, int len) {
  int good = check(y, x, len);

  if (good != -1) {
    cnt[good] += 1;
    return;
  }

  divide(y, x, len / 2);
  divide(y + len / 2, x, len / 2);
  divide(y, x + len / 2, len / 2);
  divide(y + len / 2, x + len / 2, len / 2);
  return;
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> maps[i][j];
    }
  }

  divide(0, 0, N);
  for (int k = 0; k < 2; k++) {
    cout << cnt[k] << '\n';
  }

  return 0;
}