// BOJ 1976 여행 가자
// https://www.acmicpc.net/problem/1976

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 210;
int N, M;
int parent[MAX_N];
int r[MAX_N];

int find(int u) {
  if (parent[u] == u) return u;

  return find(parent[u]);
}

void set_union(int u, int v) {
  u = find(u);
  v = find(v);

  if (u == v) return;

  if (r[u] > r[v]) swap(u, v);

  if (r[u] == r[v]) r[v]++;

  parent[u] = v;

  return;
}

int main() {
  cin >> N >> M;
  int input = 0;
  for (int i = 1; i <= N; i++) {
    parent[i] = i;
    r[i] = 1;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> input;
      if (input == 1) {
        set_union(i, j);
      }
    }
  }
  bool check = true;
  int temp = 0;
  for (int i = 0; i < M; i++) {
    cin >> input;
    if (i == 0)
      temp = find(input);
    else {
      if (find(input) != temp) {
        check = false;
        break;
      }
    }
  }

  if (check)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';

  return 0;
}