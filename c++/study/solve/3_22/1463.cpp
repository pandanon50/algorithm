// BOJ 1463 1로 만들기

#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1000010];
int main() {
  cin >> N;

  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;

  for (int i = 4; i <= N; i++) {
    int ret = dp[i - 1] + 1;
    if (i % 2 == 0) {
      ret = min(dp[i / 2] + 1, ret);
    }
    if (i % 3 == 0) {
      ret = min(dp[i / 3] + 1, ret);
    }
    dp[i] = ret;
  }
  cout << dp[N] << '\n';
  return 0;
}