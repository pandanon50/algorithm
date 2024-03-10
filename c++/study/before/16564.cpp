#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N;
const int MAX_N = 1000010;
ll K, hi, lo = 1, mid, ret = -1;
ll arr[MAX_N];

bool check(ll level) {
  ll num = 0;
  for (int i = 0; i < N; i++) {
    if (level > arr[i]) {
      num += (level - arr[i]);
    }
  }
  return K >= num;
}

int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    hi = max(hi, arr[i]);
  }
  hi = hi + K;

  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (check(mid)) {
      lo = mid + 1;
      ret = max(mid, ret);
    } else
      hi = mid - 1;
  }
  cout << ret << '\n';

  return 0;
}