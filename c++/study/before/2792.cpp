#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll N, M, ret = 1e18;
ll arr[300004];

bool check(int jy) {
  ll num = 0;
  for (int i = 0; i < M; i++) {
    num += (arr[i] / jy);
    if (arr[i] % jy) num++;
  }
  return N >= num;
}

int main() {
  cin >> N >> M;
  ll lo = 1, hi, mid, input;

  for (int i = 0; i < M; i++) {
    cin >> input;
    arr[i] = input;
    hi = max(hi, arr[i]);
  }

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