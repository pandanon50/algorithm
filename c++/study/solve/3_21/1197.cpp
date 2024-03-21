// BOJ 1197 최소 스패닝 트리
#include <bits/stdc++.h>

using namespace std;

const int MAX_E = 10010;
int V, E, v, u, w, answer;
int parent[MAX_E];
int r[MAX_E];
vector<pair<int, pair<int, int>>> ed;

int find(int u) {
  if (parent[u] == u)
    return u;

  else
    return parent[u] = find(parent[u]);
}

void set_union(int a, int b) {
  a = find(a);
  b = find(b);

  if (a == b) return;

  if (r[a] > r[b]) swap(a, b);

  if (r[a] == r[b]) r[b]++;

  parent[a] = b;

  return;
}

int main() {
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    cin >> v >> u >> w;
    ed.push_back({w, {v, u}});
  }

  for (int i = 1; i <= V; i++) {
    parent[i] = i;
    r[i] = 1;
  }

  sort(ed.begin(), ed.end());

  for (int i = 0; i < ed.size(); i++) {
    int weight = ed[i].first;
    int v1 = ed[i].second.first;
    int v2 = ed[i].second.second;

    if (find(v1) == find(v2)) continue;

    answer += weight;
    set_union(v1, v2);
  }
  cout << answer << '\n';
  return 0;
}