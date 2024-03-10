// BOJ 11657 타임머신
// https://www.acmicpc.net/problem/11404
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 510;
const int INF = 987654321;

long long N, M, A, B, C;

long long dist[MAX_N];

vector<pair<int, int>> adj[MAX_N];

int main() {
  cin >> N >> M;
  fill(dist, dist + N, INF);
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    adj[A - 1].push_back({C, B - 1});
  }

  dist[0] = 0;
  bool isCycle = false;
  for (int i = 0; i < N; i++) {
    for (int here = 0; here < N; here++) {
      for (auto next : adj[here]) {
        int there = next.second;
        int t_weight = next.first;
        if (dist[here] != INF && dist[here] + t_weight < dist[there]) {
          if (i == N - 1) {
            isCycle = true;
          }
          dist[there] = dist[here] + t_weight;
        }
      }
    }
  }
  if (isCycle)
    cout << -1 << '\n';
  else {
    for (int i = 1; i < N; i++) {
      if (dist[i] == INF)
        cout << -1 << '\n';
      else
        cout << dist[i] << '\n';
    }
  }
  return 0;
}