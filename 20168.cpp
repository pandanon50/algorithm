#include <bits/stdc++.h>

using namespace std;

int N, M, C, s, finish;
const int INF = 987654321;
int dist[12];
int top[12];
vector<pair<int, int>> adj[12];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int main() {
  cin >> N >> M >> s >> finish >> C;
  int v, c, w;
  for (int i = 0; i < M; i++) {
    cin >> v >> c >> w;
    adj[v - 1].push_back({w, c - 1});
    adj[c - 1].push_back({w, v - 1});
  }
  fill(dist, dist + 12, INF);
  fill(top, top + 12, INF);
  dist[s - 1] = 0;
  pq.push({0, s - 1});
  top[s - 1] = 0;
  while (pq.size()) {
    int here = pq.top().second;
    int w = pq.top().first;
    pq.pop();
    if (w > C) continue;
    if (dist[here] != w) continue;
    for (auto next : adj[here]) {
      int there = next.second;
      int t_w = next.first;

      if (C >= dist[here] + t_w) {
        int max_m = max(top[here], t_w);
        if (top[there] > max_m) top[there] = max_m;
        if (dist[there] > dist[here] + t_w) {
          dist[there] = dist[here] + t_w;
          pq.push({dist[there], there});
        }
      }
    }
  }
  if (top[finish - 1] == INF)
    cout << -1 << '\n';
  else
    cout << top[finish - 1] << '\n';

  return 0;
}