#include <bits/stdc++.h>

using namespace std;

int N, M, A, B, C, a, b, c, result, answer = -1;

const int MAX_N = 100010;
const int INF = 987654321;
int friends[3];
int dist[3][MAX_N];

vector<pair<int, int>> adj[MAX_N];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int main() {
  cin >> N;
  cin >> A >> B >> C;

  friends[0] = A - 1;
  friends[1] = B - 1;
  friends[2] = C - 1;
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    adj[a - 1].push_back({c, b - 1});
    adj[b - 1].push_back({c, a - 1});
  }

  for (int i = 0; i < 3; i++) {
    fill(&dist[i][0], &dist[i][0] + N, INF);

    int start = friends[i];
    dist[i][start] = 0;
    pq.push({0, start});

    while (pq.size()) {
      int here = pq.top().second;
      int w = pq.top().first;
      pq.pop();
      if (dist[i][here] != w) continue;

      for (auto next : adj[here]) {
        int there = next.second;
        int t_w = next.first;

        if (dist[i][there] > dist[i][here] + t_w) {
          dist[i][there] = dist[i][here] + t_w;
          pq.push({dist[i][there], there});
        }
      }
    }
  }

    for (int i = 0; i < N; i++) {
    int min_f = 987654321;
    for (int k = 0; k < 3; k++) {
      if (dist[k][i] != 0 && dist[k][i] != INF) {
        min_f = min(min_f, dist[k][i]);
      }
    }
    if (answer < min_f) {
      answer = min_f;
      result = i;
    }
  }
  cout << result + 1 << '\n';
  return 0;
}
