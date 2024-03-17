// BOJ 1717 집합의 표현
// https://www.acmicpc.net/problem/1717

#include <bits/stdc++.h>

using namespace std;
int n, m, t, a, b;
const int MAX_N = 1000010;
int parent[MAX_N];
int tree_height[MAX_N];
int find(int u) {
  if (parent[u] == u)
    return u;

  else
    return find(parent[u]);
}

bool check_union(int u, int v) { return find(u) == find(v); }

void set_union(int u, int v) {
  int pu = find(u);
  int pv = find(v);
  if (pu == pv) return;
  int height = -1;
  if (tree_height[pu] > tree_height[pv]) swap(pu, pv);

  if (tree_height[pu] == tree_height[pv]) tree_height[pv]++;

  parent[pu] = pv;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i <= n; i++) {
    parent[i] = i;
    tree_height[i] = 1;
  }

  for (int i = 0; i < m; i++) {
    cin >> t >> a >> b;

    if (t == 0) {
      set_union(a, b);
    } else if (t == 1) {
      if (check_union(a, b))
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}