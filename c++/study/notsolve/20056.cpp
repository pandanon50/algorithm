#include <bits/stdc++.h>

using namespace std;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int N, M, K, result;

struct Fireball {
  int cy, cx, weight, sec;
  int direc;
  int count;
};

queue<Fireball> move_q, explo_q;
vector<Fireball> v_sum;

bool compare(Fireball a, Fireball b) {
  if (a.cy == b.cy)
    return a.cx < b.cx;
  else
    return a.cy < b.cy;
}

Fireball direction(Fireball item) {
  int ny = item.cy + (dy[item.direc] * item.sec % N);
  int nx = item.cx + (dx[item.direc] * item.sec % N);
  // 범위 연속 체크
  if (ny > N || ny < 1) {
    if (ny < 1) {
      ny += N;
    } else
      ny -= N;
  }

  if (nx > N || nx < 1) {
    if (nx < 1) {
      nx += N;
    } else
      nx -= N;
  }
  return {ny, nx, item.weight, item.sec, item.direc, 1};
}
void divide(Fireball item, int direc) {
  Fireball divideItem;
  divideItem.count = 1;
  divideItem.weight = item.weight / 5;
  divideItem.sec = item.sec / item.count;
  divideItem.cx = item.cx;
  divideItem.cy = item.cy;

  for (int i = 0; i < 4; i++) {
    if (direc == -1) {
      divideItem.direc = (i * 2) + 1;
    } else {
      divideItem.direc = i * 2;
    }
    move_q.push(divideItem);
  }
}

int main() {
  cin >> N >> M >> K;
  int y, x, m, s, d;
  for (int i = 0; i < M; i++) {
    cin >> y >> x >> m >> s >> d;
    Fireball fb = {y, x, m, s, d, 1};
    move_q.push(fb);
  }
  while (K--) {
    // 1. 방향체크
    v_sum.clear();
    int explo_check = 0;
    Fireball check = {0, 0, 0, 0, 0, 1};

    while (move_q.size()) {
      Fireball fb = move_q.front();
      v_sum.push_back(direction(fb));
      move_q.pop();
    }

    // 2. 합체크
    sort(v_sum.begin(), v_sum.end(), compare);
    for (int i = 0; i < v_sum.size(); i++) {
      if (i == 0) {
        check = {v_sum[i].cy,  v_sum[i].cx,    v_sum[i].weight,
                 v_sum[i].sec, v_sum[i].direc, 1};
      } else {
        // 파이어볼 합체
        if (check.cy == v_sum[i].cy && check.cx == v_sum[i].cx) {
          check.weight += v_sum[i].weight;
          check.sec += v_sum[i].sec;
          if (check.direc != -1 && check.direc % 2 != v_sum[i].direc % 2) {
            check.direc = -1;
          }
          check.count += 1;
          explo_check = 1;
        } else {
          if (explo_check == 1) {
            explo_q.push(check);
          } else {
            move_q.push(check);
          }
          check.cy = v_sum[i].cy;
          check.cx = v_sum[i].cx;
          check.weight = v_sum[i].weight;
          check.sec = v_sum[i].sec;
          check.direc = v_sum[i].direc;
          check.count = 1;
          explo_check = 0;
        }
      }
    }
    if (explo_check == 1) {
      explo_q.push(check);
    } else {
      move_q.push(check);
    }

    while (explo_q.size()) {
      Fireball exploItem = explo_q.front();
      int total_weight = exploItem.weight / 5;
      if (total_weight != 0) {
        divide(exploItem, exploItem.direc);
      }
      explo_q.pop();
    }
  }
  Fireball answer;
  while (move_q.size()) {
    answer = move_q.front();
    result += answer.weight;
    move_q.pop();
  }
  cout << result << '\n';
}
