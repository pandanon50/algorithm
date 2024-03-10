// BOJ 11403 경로 찾기
// https://www.acmicpc.net/problem/11403
#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 110;
int N;
int dist[MAX_N][MAX_N];
vector<int> adj[MAX_N];
queue<int> q;
int main() {
  cin >> N;
  int input;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> input;
      if (input == 1) adj[i].push_back(j);
    }
  }

  for (int i = 0; i < N; i++) {
    q.push(i);
    while (q.size()) {
      int here = q.front();
      q.pop();
      for (int there : adj[here]) {
        if (dist[i][there]) continue;
        dist[i][there] = 1;
        q.push(there);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << dist[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}