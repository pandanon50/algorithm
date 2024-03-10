#include <bits/stdc++.h>

using namespace std;
const int MAX_V = 20020;
const int INF = 987654321;
int V, E, K, u, v, w;

int dist[MAX_V];
vector<pair<int, int>> adj[MAX_V];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int main() {
  cin >> V >> E >> K;
  for (int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }
  fill(dist, dist + V + 1, INF);
  pq.push({0, K});
  dist[K] = 0;

  while (pq.size()) {
    int here = pq.top().second;
    int here_w = pq.top().first;
    pq.pop();
    if (dist[here] != here_w) continue;
    for (auto next : adj[here]) {
      int there = next.second;
      int there_w = next.first;

      if (dist[there] > dist[here] + there_w) {
        dist[there] = dist[here] + there_w;
        pq.push({dist[there], there});
      }
    }
  }
  for (int i = 1; i <= V; i++) {
    if (dist[i] == INF)
      cout << "INF" << '\n';
    else
      cout << dist[i] << '\n';
  }
  return 0;
}