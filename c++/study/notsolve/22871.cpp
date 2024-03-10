// 징검다리 건너기 22871
// https://www.acmicpc.net/problem/22871

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX_N = 5050;

int N;

ll arr[MAX_N];
int visited[MAX_N];
ll lo = 1, hi, mid, ret = 1e12;
vector<int> v;

bool check(ll K) {
  v.clear();
  memset(visited, 0, sizeof(visited));
  v.push_back(1);
  visited[1] = 1;

  while (v.size()) {
    int start = v[v.size() - 1];
    v.pop_back();
    ll power = 0;
    for (int j = start + 1; j <= N; j++) {
      power = (j - start) * (1 + abs(arr[start] - arr[j]));
      if (power <= K && visited[j] == 0) {
        v.push_back(j);
        visited[j] = 1;
      }
    }
  }
  return visited[N] == 1;
}

int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  hi = (N - 1) * (abs(arr[N] - arr[1]) + 1);
  while (lo <= hi) {
    mid = (lo + hi) / 2;

    if (check(mid)) {
      ret = min(ret, mid);
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  cout << ret << '\n';
  return 0;
}