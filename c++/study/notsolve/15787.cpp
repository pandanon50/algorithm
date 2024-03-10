#include <bits/stdc++.h>

using namespace std;

int N, M, com, num, x, answer;
const int MAX_LEN = 100010;
int train[MAX_LEN];
map<int, int> desti;

int main() {
  cin >> N >> M;
  for (int tc = 0; tc < M; tc++) {
    cin >> com >> num;

    if (com == 1) {
      cin >> x;
      x = x - 1;

      train[num] |= (1 << x);
    } else if (com == 2) {
      cin >> x;
      x = x - 1;
      train[num] &= ~(1 << x);
    } else if (com == 3) {
      train[num] <<= 1;
      train[num] = train[num] & ~(1 << 20);
    } else if (com == 4) {
      train[num] >>= 1;
    }
  }

  for (int i = 1; i <= N; i++) {
    if (desti[train[i]] == 0) {
      desti[train[i]] += 1;
      answer++;
    }
  }
  cout << answer << '\n';
  return 0;
}