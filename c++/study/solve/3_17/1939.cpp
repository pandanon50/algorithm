// BOJ 1939 중량제한
// https://www.acmicpc.net/problem/1939

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX_N = 10010;
ll C, w, lo, hi, mid, ret;
int N, M, a, b, A, B;
int visited[MAX_N];
vector<pair<ll, int>> adj[MAX_N];

bool bfs(ll limit) {
  memset(visited, 0, sizeof(visited));
  queue<int> q;
  visited[A] = 1;
  q.push(A);
  while (q.size()) {
    int here = q.front();
    q.pop();

    for (auto next : adj[here]) {
      int there = next.second;
      if (limit > next.first) continue;
      if (visited[there]) continue;

      visited[there] = 1;
      q.push(there);
    }
  }

  return visited[B] != 0;
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> a >> b >> w;

    adj[a].push_back({w, b});
    adj[b].push_back({w, a});
    hi = max(hi, w);
    lo = min(lo, w);
  }
  cin >> A >> B;
  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (bfs(mid)) {
      ret = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  cout << ret << '\n';
  return 0;
}

// 이진탐색으로 중량을 설정
// 설정된 값으로 BFS 탐색 (엣지만 탐색 M)
// 값이 가능하면 lo = mid + 1; 불가능하면 hi = mid - 1;
// (N + M) * logC
