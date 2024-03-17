// BOJ 20182 골목 대장 호석 - 효율성 1
// https://www.acmicpc.net/problem/20182

#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100010;
const int MAX_COST = 22;
const int INF = 1e9;
int N, M, C, A, B, ret = INF;

int dist[MAX_N][MAX_COST];
struct Cost {
  int c;
  int mc;
  int here;
};

vector<pair<int, int>> adj[MAX_N];
queue<Cost> q;

int main() {
  cin >> N >> M >> A >> B >> C;
  int a, b, c;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }

  fill(&dist[0][0], &dist[0][0] + 22 * (N + 1), INF);

  dist[A][0] = 0;
  q.push({0, 0, A});

  while (q.size()) {
    int here = q.front().here;
    int cost = q.front().c;
    int max_cost = q.front().mc;
    q.pop();

    if (dist[here][max_cost] < cost) continue;

    for (auto next : adj[here]) {
      int there = next.second;
      int t_w = next.first;
      int new_weight = cost + t_w;
      int new_max_cost = max(max_cost, t_w);

      if (new_weight > C) continue;
      // 최대 비용 값들 끼리 비교하면서 내가 쓴 돈은 최소로 하는 로직
      // new_max_cost가 같은 값들 중에서 가장 최소값만 들어간다!
      if (dist[there][new_max_cost] <= new_weight) continue;

      dist[there][new_max_cost] = new_weight;
      q.push({new_weight, new_max_cost, there});
    }
  }

  for (int i = 1; i <= 20; i++) {
    if (dist[B][i] != INF) {
      ret = i;
      break;
    }
  }
  if (ret == INF)
    cout << -1 << '\n';
  else
    cout << ret << '\n';

  return 0;
}