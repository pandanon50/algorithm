#include <bits/stdc++.h>

using namespace std;

int N, M;
typedef long long ll;
const int MAX_N = 1000010;
ll arr[MAX_N];

ll lo = 1, hi, mid, ret = 1e13;

bool check(ll minute) {
  ll num = 0;
  for (int i = 0; i < N; i++) {
    num += (minute / arr[i]);
  }
  return num >= M;
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    hi = max(hi, arr[i]);
  }

  hi = hi * M;
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