// BOJ 20183 골목 대장 호석 - 효율성 2
// https://www.acmicpc.net/problem/20183

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX_N = 100010;

const ll INF = 1e14;
int N, M, A, B;
ll l = 1, r, C, mid, ret = -1;
ll dist[MAX_N];
vector<pair<ll, int>> adj[MAX_N];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

bool dijkstra(ll mid) {
  fill(dist, dist + N + 1, INF);
  dist[A] = 0;
  pq.push({0, A});
  while (pq.size()) {
    int here = pq.top().second;
    ll cost = pq.top().first;
    pq.pop();
    if (dist[here] != cost) continue;

    for (auto next : adj[here]) {
      int there = next.second;
      ll new_w = cost + next.first;
      if (mid < next.first) continue;
      if (C < new_w) continue;
      if (dist[there] <= new_w) continue;

      dist[there] = new_w;
      pq.push({dist[there], there});
    }
  }
  return dist[B] != INF;
}

int main() {
  cin >> N >> M >> A >> B >> C;
  int a, b;
  ll c;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
    r = max(r, c);
  }

  while (l <= r) {
    mid = (l + r) / 2;
    if (dijkstra(mid)) {
      ret = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }

  cout << ret << '\n';
  return 0;
}