// BOJ 1916 최소비용 구하기
// https://www.acmicpc.net/problem/1916

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1010;
const int INF = 987654321;
int N, M, v, u, w, answer_from, answer_to;
int dist[MAX_N][MAX_N];
vector<pair<int, int>> adj[MAX_N];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;

int main() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> v >> u >> w;
    adj[v].push_back({w, u});
  }
  cin >> answer_from >> answer_to;
  for (int i = 1; i <= N; i++) {
    fill(dist[i], dist[i] + N + 1, INF);
    dist[i][i] = 0;
    pq.push({0, i});

    while (pq.size()) {
      int here = pq.top().second;
      int here_weight = pq.top().first;
      pq.pop();
      if (dist[i][here] != here_weight) continue;

      for (pair<int, int> there : adj[here]) {
        int next = there.second;
        int next_weight = there.first;

        if (dist[i][next] > next_weight + dist[i][here]) {
          dist[i][next] = next_weight + dist[i][here];
          pq.push({dist[i][next], next});
        }
      }
    }
  }
  cout << dist[answer_from][answer_to] << '\n';
  return 0;
}