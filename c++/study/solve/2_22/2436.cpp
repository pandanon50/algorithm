#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll A, B, a, b, sum = 200000000;

int GCD(int r, int k) {
  if (r == 0) return k;
  return GCD(k % r, r);
}

int main() {
  cin >> A >> B;
  ll K = B * A;
  ll R = K;
  ll div = 1;
  while (div < R) {
    if (K % div == 0) {
      R = K / div;
      if (R + div < sum && GCD(div, R) == A) {
        sum = R + div;
        a = div;
        b = R;
      }
    }
    div += 1;
  }
  cout << a << " " << b << '\n';
}