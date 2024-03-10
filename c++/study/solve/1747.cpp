#include <bits/stdc++.h>

using namespace std;

int N;
string str;
int dp[2000002];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  dp[1] = 1;
  for (int i = 2; i < 2000001; i++) {
    if (dp[i] == 0) {
      for (int j = 2 * i; j < 2000001; j += i) {
        dp[j] = 1;
      }
    }
  }

  int check = 0;

  for (int i = N;; i++) {
    check = 0;
    str = to_string(i);

    for (int j = 0; j < str.size() / 2; j++) {
      if (str[j] != str[str.size() - j - 1]) {
        check = 1;
      }
    }
    if (check == 0 && dp[i] == 0) {
      cout << i << '\n';
      break;
    }
  }

  return 0;
}