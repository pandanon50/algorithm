// BOJ 1780 종아의 갯수
// https://www.acmicpc.net/problem/1780

#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 2200;

int N;
int answer[3];
int maps[MAX_N][MAX_N];

int check(int s, int e, int len) {
  int first = maps[s][e];
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (maps[s + i][e + j] != first) {
        return 2;
      }
    }
  }
  return first;
}

void divide(int s, int e, int len) {
  if (len == 1) {
    if (maps[s][e] == -1) {
      answer[2] += 1;
    } else
      answer[maps[s][e]] += 1;
    return;
  }

  int c = check(s, e, len);
  if (c != 2) {
    if (c == -1)
      answer[2] += 1;
    else
      answer[c] += 1;
    return;
  }
  divide(s, e, len / 3);
  divide(s, e + len / 3, len / 3);
  divide(s, e + len - len / 3, len / 3);

  divide(s + len / 3, e, len / 3);
  divide(s + len / 3, e + len / 3, len / 3);
  divide(s + len / 3, e + len - len / 3, len / 3);

  divide(s + len - len / 3, e, len / 3);
  divide(s + len - len / 3, e + len / 3, len / 3);
  divide(s + len - len / 3, e + len - len / 3, len / 3);
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
  cout << answer[2] << '\n';
  cout << answer[0] << '\n';
  cout << answer[1] << '\n';

  return 0;
}