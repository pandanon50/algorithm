#include <bits/stdc++.h>

using namespace std;

int K, W, H, answer = 50000;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

const int hy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int hx[] = {1, 2, 2, 1, -1, -2, -2, -1};

const int MAX_LEN = 210;
const int MAX_K = 32;
int maps[MAX_LEN][MAX_LEN];
int visited[MAX_LEN][MAX_LEN][MAX_K];

struct Move {
  int y;
  int x;
  int horse_move;
};

queue<Move> q;

int main() {
  cin >> K;
  cin >> W >> H;

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> maps[i][j];
    }
  }
  Move monkey = {0, 0, 0};

  visited[0][0][0] = 1;
  q.push(monkey);

  while (q.size()) {
    int y = q.front().y;
    int x = q.front().x;
    int move = q.front().horse_move;
    q.pop();

    if (y == H - 1 && x == W - 1) {
      cout << visited[y][x][move] - 1 << '\n';
      exit(0);
    }

    if (move < K) {
      for (int i = 0; i < 8; i++) {
        int py = y + hy[i];
        int px = x + hx[i];

        if (py < 0 || px < 0 || py >= H || px >= W) continue;
        if (visited[py][px][move + 1]) continue;
        if (maps[py][px] == 1) continue;

        visited[py][px][move + 1] = visited[y][x][move] + 1;
        Move horse = {py, px, move + 1};
        q.push(horse);
      }
    }
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;

      if (visited[ny][nx][move]) continue;
      if (maps[ny][nx] == 1) continue;

      visited[ny][nx][move] = visited[y][x][move] + 1;
      Move monkey = {ny, nx, move};
      q.push(monkey);
    }
  }
  cout << -1 << '\n';

  return 0;
}