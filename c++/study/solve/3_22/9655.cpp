// BOJ 9655 돌 게임
#include <bits/stdc++.h>

using namespace std;

int N;
int dp[1004];

int main() {
  cin >> N;

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= N; i++) {
    dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
  }

  if (dp[N] % 2 == 1)
    cout << "SK" << '\n';
  else
    cout << "CY" << '\n';

  return 0;
}