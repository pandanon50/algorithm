#include <bits/stdc++.h>

using namespace std;

int N, K, cnt;
const int MAX_LEN = 1010;
int arr[MAX_LEN];
vector<int> v;
int main() {
  cin >> N >> K;
  for (int i = 2; i <= N; i++) {
    if (arr[i] == 0) {
      v.push_back(i);
    }
    for (int j = i; j <= N; j += i) {
      if (i == j) continue;
      if (arr[j] == 0) {
        v.push_back(j);
        arr[j] = 1;
      }
    }
  }
  cout << v[K - 1] << '\n';

  return 0;
}