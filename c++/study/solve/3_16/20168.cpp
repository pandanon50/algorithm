// BOJ 20168 골목 대장 호석 - 기능성
// https://www.acmicpc.net/problem/20168

#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 12;
int N, M, C, A, B, ret = 1e9;

int visited[MAX_N];
vector<pair<int, int>> adj[MAX_N];

int dfs(int s, int e, int maxCost, int sumCost) {
  if (s == e) return maxCost;

  for (pair<int, int> next : adj[s]) {
    int there = next.second;
    int t_w = next.first;

    if (visited[there]) continue;
    if (sumCost + t_w > C) continue;

    visited[there] = 1;
    ret = min(ret, dfs(there, e, max(maxCost, t_w), sumCost + t_w));
    visited[there] = 0;
  }
  return ret;
}

int main() {
  cin >> N >> M >> A >> B >> C;
  int a, b, c;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }

  ret = dfs(A, B, 0, 0);

  if (ret == 1e9)
    cout << -1 << '\n';
  else
    cout << ret << '\n';
  return 0;
}

// 처음에 BFS로 풀려고했지만 실패 -> 만약 visited를 찍었다면 거기로 답이
// 될수있는 경우가 생략됨(반례)

// DFS 폼으로 < 갖고있는 돈 <= 현재까지 든 비용 + 다음 엣지까지 가는 비용 > 이면
// -> maxCost 값을 갱신하면서 다시 탐색
// 도착점으로 가는 한가지 경우가 끝나면 다시 visited를 0으로 초기화 (백트레킹)
/*
 for (pair<int, int> next : adj[s]) {
    int there = next.second;
    int t_w = next.first;

    if (visited[there]) continue;
    if (sumCost + t_w > C) continue;

    visited[there] = 1;
    ret = min(ret, dfs(there, e, max(maxCost, t_w), sumCost + t_w));
    visited[there] = 0;
  }

*/