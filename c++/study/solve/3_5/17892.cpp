// BOJ 17829 222-풀링
// https://www.acmicpc.net/problem/17829

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1030;
int N, answer;

int maps[MAX_N][MAX_N];
vector<int> v;
vector<pair<int, int>> pos;
vector<int> cmp;
void divide(int y, int x, int len) {
  if (len == 2) {
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        cmp.push_back(maps[i + y][j + x]);
      }
    }
    sort(cmp.begin(), cmp.end());
    v.push_back(cmp[2]);
    pos.push_back({y, x});
    cmp.clear();
    return;
  }

  divide(y, x, len / 2);
  divide(y, x + len / 2, len / 2);
  divide(y + len / 2, x, len / 2);
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
  while (true) {
    divide(0, 0, N);
    N = N / 2;

    for (int i = 0; i < v.size(); i++) {
      int ny = pos[i].first;
      int nx = pos[i].second;
      maps[ny / 2][nx / 2] = v[i];
    }
    v.clear();

    if (N == 1) break;
  }
  cout << maps[0][0] << '\n';
  return 0;
}
