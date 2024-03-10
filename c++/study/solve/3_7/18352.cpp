// BOJ 18353 경로찾기
// https://www.acmicpc.net/problem/11403

#include <bits/stdc++.h>

using namespace std;

int N, M, K, X;

const int MAX_N = 300010;
const int INF = 987654321;
int dist[MAX_N];

vector<pair<int, int>> adj[MAX_N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int main() {
  cin >> N >> M >> K >> X;
  int s, e;
  for (int i = 0; i < M; i++) {
    cin >> s >> e;
    adj[s].push_back({1, e});
  }
  fill(dist, dist + N + 1, INF);
  dist[X] = 0;
  pq.push({0, X});

  while (pq.size()) {
    int here = pq.top().second;
    int here_w = pq.top().first;
    pq.pop();
    if (dist[here] != here_w) continue;

    for (pair<int, int> next : adj[here]) {
      int there = next.second;
      int there_w = next.first;
      if (dist[there] > dist[here] + there_w) {
        dist[there] = dist[here] + there_w;
        pq.push({dist[there], there});
      }
    }
  }
  bool exist = false;
  for (int i = 1; i <= N; i++) {
    if (dist[i] == K) {
      exist = true;
      cout << i << '\n';
    }
  }

  if (!exist) cout << -1 << '\n';
}