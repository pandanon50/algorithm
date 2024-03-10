// 11663 선분 위의 점
// https://www.acmicpc.net/problem/11663

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N, M, cnt;
const int MAX_NM = 100010;
ll arr[MAX_NM];

ll max_value, min_value;

int check(bool isMin, int val) {
  ll lo = 0, hi = N - 1, mid;
  while (lo <= hi) {
    mid = (lo + hi) / 2;

    if (val < arr[mid])
      hi = mid - 1;
    else if (val == arr[mid]) {
      return mid;
    } else
      lo = mid + 1;
  }
  if (isMin) {
    return max(lo, hi);
  } else {
    return min(lo, hi);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + N);
  max_value = arr[N - 1];
  min_value = arr[0];

  for (int i = 0; i < M; i++) {
    ll m1, m2;
    cin >> m1 >> m2;
    int lo_idx = 0;
    int hi_idx = N - 1;

    if ((m1 < min_value && m2 < min_value) ||
        (m1 > max_value && m2 > max_value)) {
      cout << 0 << '\n';
      continue;
    }

    if (m1 >= min_value) {
      lo_idx = check(true, m1);
    }
    if (m2 <= max_value) {
      hi_idx = check(false, m2);
    }
    cout << hi_idx - lo_idx + 1 << '\n';
  }
  return 0;
}