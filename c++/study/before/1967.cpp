#include <bits/stdc++.h>

using namespace std;

int N, answer;

const int MAX_LEN = 10010;

int cnt[MAX_LEN];
int visited[MAX_LEN];

vector<pair<int, int> > adj[MAX_LEN];

void go(int from) {
  for (auto there : adj[from]) {
    if (visited[there.first] == 0) {
      visited[there.first] = 1;
      cnt[there.first] = cnt[from] + there.second;
      go(there.first);
    }
  }
  return;
}

int main() {
  cin >> N;
  int a, b, c;
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
  }

  for (int i = 1; i <= N; i++) {
    visited[i] = 1;
    go(i);
    for (int i = 1; i <= N; i++) {
      if (answer < cnt[i]) {
        answer = cnt[i];
      }
    }
    memset(visited, 0, sizeof(visited));
    memset(cnt, 0, sizeof(visited));
  }
  cout << answer << '\n';
}