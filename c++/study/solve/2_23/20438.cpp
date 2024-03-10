#include <bits/stdc++.h>

using namespace std;

int N, K, Q, M, ss, S, E;
const int MAX_N = 5010;

int arr[MAX_N];
int prefix[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K >> Q >> M;

  for (int i = 0; i < K; i++) {
    cin >> ss;
    arr[ss] = -1;
  }
  for (int i = 0; i < Q; i++) {
    cin >> ss;
    if (arr[ss] != -1) {
      for (int j = ss; j <= N + 2; j += ss) {
        if (arr[j] != -1) {
          arr[j] = 1;
        }
      }
    }
  }

  for (int i = 3; i <= N + 2; i++) {
    if (arr[i] == 0 || arr[i] == -1) {
      prefix[i] = prefix[i - 1] + 1;
    } else {
      prefix[i] = prefix[i - 1];
    }
  }

  for (int i = 0; i < M; i++) {
    cin >> S >> E;
    if (S == E) {
      if (arr[S] == 0)
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    } else {
      cout << prefix[E] - prefix[S - 1] << '\n';
    }
  }

  return 0;
}