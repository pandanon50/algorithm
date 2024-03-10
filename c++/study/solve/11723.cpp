#include <bits/stdc++.h>

using namespace std;

int M, S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> M;
  for (int i = 0; i < M; i++) {
    string s = "";
    int x = 0;
    cin >> s;

    if (s == "add") {
      cin >> x;
      x = x - 1;
      if (S & (1 << x))
        continue;
      else
        S |= (1 << x);
    } else if (s == "check") {
      cin >> x;
      x = x - 1;
      if (S & (1 << x))
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    } else if (s == "remove") {
      cin >> x;
      x = x - 1;
      if (S & (1 << x)) {
        S &= ~(1 << x);
      }
    } else if (s == "toggle") {
      cin >> x;
      x = x - 1;
      S ^= (1 << x);
    } else if (s == "all") {
      S = 0;
      S = (1 << 20) - 1;
    } else if (s == "empty") {
      S = 0;
    }
  }
}