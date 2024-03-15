// BOJ 1043 거짓말
// https://www.acmicpc.net/problem/1043

#include <bits/stdc++.h>

using namespace std;
const int MAX_NM = 53;
int N, M, L, cnt;

int parent[MAX_NM];
int r[MAX_NM];
vector<int> party[MAX_NM];

int find(int u) {
  if (parent[u] == u)
    return u;
  else
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
  cin >> L;

  int input = 0;
  int num = 0;
  int pt = 0;

  for (int i = 0; i <= N; i++) {
    parent[i] = i;
    if (i == 0)
      r[i] = 52;
    else
      r[i] = 1;
  }

  for (int i = 0; i < L; i++) {
    cin >> input;
    set_union(0, input);
  }

  for (int i = 0; i < M; i++) {
    cin >> num;
    for (int j = 0; j < num; j++) {
      cin >> pt;
      party[i].push_back(pt);
    }
    if (num == 1) continue;

    for (int k = 0; k < num - 1; k++) {
      set_union(party[i][k], party[i][k + 1]);
    }
  }

  for (int i = 0; i < M; i++) {
    bool check = true;
    for (int j = 0; j < party[i].size(); j++) {
      if (find(party[i][j]) == 0) {
        check = false;
        break;
      }
    }
    if (check) cnt++;
  }
  cout << cnt << '\n';

  return 0;
}