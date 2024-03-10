#include <bits/stdc++.h>

using namespace std;

int N, M;

int check(int value, vector<int> &v) {
  int l, r, mid;
  l = 0;
  r = v.size() - 1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (v[mid] > value)
      r = mid - 1;
    else if (v[mid] == value)
      return 1;
    else
      l = mid + 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t_case = 0;
  cin >> t_case;

  for (int k = 0; k < t_case; k++) {
    cin >> N;
    int a = 0;
    vector<int> v;
    for (int i = 0; i < N; i++) {
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(), v.end());
    cin >> M;
    for (int i = 0; i < M; i++) {
      cin >> a;
      cout << check(a, v) << '\n';
    }
  }
  return 0;
}