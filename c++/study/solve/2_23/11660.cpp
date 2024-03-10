#include <bits/stdc++.h>

using namespace std;

int N, M, xx, x, y, yy;

const int MAX_N = 1030;

int arr[MAX_N][MAX_N];
int prefix[MAX_N][MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> arr[i][j];
      prefix[i][j] = (prefix[i - 1][j] + prefix[i][j - 1] + arr[i][j] -
                      prefix[i - 1][j - 1]);
    }
  }

  for (int i = 0; i < M; i++) {
    cin >> y >> x >> yy >> xx;

    if (x == xx == y == yy) {
      cout << arr[yy][xx] << '\n';
    } else if (x == xx && y == yy) {
      cout << arr[y][x] << '\n';
    } else {
      int x_diff = xx - x + 1;
      int y_diff = yy - y + 1;

      cout << prefix[yy][xx] - prefix[yy - y_diff][xx] -
                  prefix[yy][xx - x_diff] + prefix[yy - y_diff][xx - x_diff]
           << '\n';
    }
  }

  return 0;
}