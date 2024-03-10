#include <bits/stdc++.h>

using namespace std;

int N, M, check, answer;
const int MAX_LEN = 10010;
int visited[MAX_LEN];
vector<int> adj[MAX_LEN];
int dp[MAX_LEN];

void go(int from) {
  for (int there : adj[from]) {
    if (visited[there]) continue;
    visited[there] = 1;
    dp[there]++;
    go(there);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;
  int A, B = 0;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;
    adj[A].push_back(B);
  }
  for (int i = 1; i <= N; i++) {
    memset(visited, 0, sizeof(visited));
    if (adj[i].size()) {
      visited[i] = 1;
      go(i);
    }
  }
  int maxValue = 0;

  for (int i = 1; i <= N; i++) {
    maxValue = max(maxValue, dp[i]);
  }

  for (int i = 1; i <= N; i++) {
    if (maxValue == dp[i]) {
      cout << i << " ";
    }
  }
  cout << '\n';
}
