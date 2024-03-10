#include <bits/stdc++.h>

using namespace std;

int main() {
  int S = 0;

  S |= (1 << 0);

  cout << "S = >" << S << '\n';

  S |= (1 << 1);

  cout << "S = >" << S << '\n';

  if (S & (1 << 0)) {
    cout << "1번은 있습니다!" << '\n';
  } else
    cout << "1번은 없습니다!" << '\n';

  if (S & (1 << 1)) {
    cout << "2번은 있습니다!" << '\n';
  } else
    cout << "2번은 없습니다!" << '\n';
}