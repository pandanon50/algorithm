#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 110;
const int INF = 987654321;
int n, m, a, b, c;

int dist[MAX_N][MAX_N];

int main() {
  cin >> n >> m;

  fill(&dist[0][0], &dist[0][0] + 110 * 110, INF);

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    dist[a - 1][b - 1] = min(c, dist[a - 1][b - 1]);
  }

  for (int k = 0; k < n; k++) {
    dist[k][k] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == k || j == k) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dist[i][j] == INF) {
        cout << 0 << " ";
      } else
        cout << dist[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}