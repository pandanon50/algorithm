// BOJ 3474 교수가 된 현우
// https://www.acmicpc.net/problem/3474

#include <bits/stdc++.h>

using namespace std;

int T;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;

  for (int i = 0; i < T; i++) {
    int two = 0, five = 0;
    ll n;
    cin >> n;

    for (int j = 2; j <= n; j *= 2) {
      two += n / j;
    }

    for (int j = 5; j <= n; j *= 5) {
      five += n / j;
    }
    cout << min(two, five) << '\n';
  }
}

// 2,5의 갯수로 0의 갯수를 파악
// 두 값중 작은 값이 정답(2,5개가 딱맞아야지 10)