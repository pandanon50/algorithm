// BOJ 14621 나만 안되는 연애
#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1010;
int N, M, e_cnt, answer;
int men = -1, women = -1;
char sex[MAX_N];
int parent[MAX_N];
int r[MAX_N];
vector<pair<int, pair<int, int>>> ed;

int find(int u) {
  if (parent[u] == u)
    return u;
  else
    return parent[u] = find(parent[u]);
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
  for (int i = 1; i <= N; i++) {
    cin >> sex[i];
    parent[i] = i;
    r[i] = 1;
  }
  int u, v, d;
  for (int i = 0; i < M; i++) {
    cin >> u >> v >> d;
    ed.push_back({d, {u, v}});
  }
  sort(ed.begin(), ed.end());
  for (int i = 0; i < ed.size(); i++) {
    int weight = ed[i].first;
    int s = ed[i].second.first;
    int e = ed[i].second.second;

    if (sex[s] == sex[e]) continue;
    if (find(s) == find(e)) continue;

    answer += weight;
    e_cnt++;
    set_union(e, s);
    if (N - 1 == e_cnt) {
      cout << answer << '\n';
      break;
    }
  }
  if (e_cnt != N - 1) cout << -1 << '\n';
  return 0;
}