#include <bits/stdc++.h>

using namespace std;

int tc, N;
typedef long long ll;
ll answer = 0;
const int MAX_N = 102;
int tarr[MAX_N];

int GCD(int a, int b) {
  int temp;
  while (b) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

void combi(int depth, vector<int> cb) {
  if (cb.size() == 2) {
    // cout << cb[]
    answer = answer + GCD(cb[0], cb[1]);
    return;
  }

  for (int i = depth + 1; i < N; i++) {
    cb.push_back(tarr[i]);
    combi(i, cb);
    cb.pop_back();
  }
  return;
}

int main() {
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    cin >> N;
    answer = 0;
    for (int j = 0; j < N; j++) {
      cin >> tarr[j];
    }
    vector<int> b;
    combi(-1, b);
    cout << answer << '\n';
  }
}