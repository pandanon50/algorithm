// BOJ 1753 최단 경로
// https://www.acmicpc.net/problem/1753

#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 20010;
const int INF = 987654321;
int V, E, K, u, v, w;

int dist[MAX_V];

vector<pair<int, int>> adj[MAX_V];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

int main() {
  cin >> V >> E >> K;
  fill(dist, dist + 20010, INF);
  for (int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }
  pq.push({0, K});
  dist[K] = 0;

  while (pq.size()) {
    int here = pq.top().second;
    int here_weight = pq.top().first;

    pq.pop();

    if (dist[here] != here_weight) continue;

    for (pair<int, int> there : adj[here]) {
      int from = there.second;
      int from_dist = there.first;

      if (dist[from] > from_dist + dist[here]) {
        dist[from] = from_dist + dist[here];
        pq.push({dist[from], from});
      }
    }
  }
  for (int i = 1; i <= V; i++) {
    if (dist[i] == INF)
      cout << "INF" << '\n';
    else
      cout << dist[i] << '\n';
  }
}