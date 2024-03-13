// 횟수의 최솟값 + 경우의 수 -> BFS visited로 최소 경로 구하는 생각으로 접근
// next_permutation -> 뎁스 증가 하면서 3 * 3^1 * 3^2 .. 시간초과

#include <bits/stdc++.h>

using namespace std;

int N;
int scv[3];
int dist[64][64][64];
int visited[64][64][64];
int m[6][3] = {{9, 3, 1}, {9, 1, 3}, {3, 1, 9},
               {3, 9, 1}, {1, 3, 9}, {1, 9, 3}};
struct SCV {
  int a, b, c;
};

queue<SCV> q;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> scv[i];
  }
  visited[scv[0]][scv[1]][scv[2]] = 1;
  SCV k = {scv[0], scv[1], scv[2]};
  q.push(k);
  while (q.size()) {
    int s1 = q.front().a;
    int s2 = q.front().b;
    int s3 = q.front().c;
    q.pop();
    if (s1 == 0 && s2 == 0 && s3 == 0) {
      cout << visited[0][0][0] - 1 << '\n';
      break;
    }
    for (int i = 0; i < 6; i++) {
      int ds1 = max(0, s1 - m[i][0]);
      int ds2 = max(0, s2 - m[i][1]);
      int ds3 = max(0, s3 - m[i][2]);

      if (visited[ds1][ds2][ds3]) continue;
      visited[ds1][ds2][ds3] = visited[s1][s2][s3] + 1;
      SCV p = {ds1, ds2, ds3};
      q.push(p);
    }
  }
  return 0;
}