// 구간합
#include <bits/stdc++.h>

using namespace std;

int N, M, i, j;

const int MAX_N = 100010;
int arr[MAX_N];
int prefix[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
    prefix[i] = prefix[i - 1] + arr[i];
  }

  for (int k = 0; k < M; k++) {
    cin >> i >> j;

    if (i == 1) {
      cout << prefix[j] << '\n';
    } else if (i == j) {
      cout << arr[i] << '\n';
    } else {
      cout << prefix[j] - prefix[i - 1] << '\n';
    }
  }
  return 0;
}