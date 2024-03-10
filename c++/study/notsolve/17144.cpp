#include <bits/stdc++.h>

using namespace std;

int R, C, T, answer, top, bottom;
const int MAX_RC = 55;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int maps[MAX_RC][MAX_RC];
int temp[MAX_RC][MAX_RC];

vector<int> vt;
vector<int> vb;

void spread() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (maps[i][j] != -1) {
        int cnt = 0;
        int div = maps[i][j] / 5;
        for (int k = 0; k < 4; k++) {
          int y = i + dy[k];
          int x = j + dx[k];

          if (x < 0 || y < 0 || x >= C || y >= R || maps[y][x] == -1) continue;
          cnt++;
          temp[y][x] += div;
        }
        temp[i][j] += (maps[i][j] - (cnt * div));
      } else if (maps[i][j] == -1) {
        temp[i][j] = -1;
      }
    }
  }
  return;
}

void tempMaps() {
  answer = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (temp[i][j] != -1) answer += temp[i][j];
      maps[i][j] = temp[i][j];
      temp[i][j] = 0;
    }
  }
  return;
}

void vTemp() {
  int cnt = 0;
  int i = top;
  int j = 0;
  bool re = false;

  while (cnt < 2 * C + top) {
    if (re) {
      if (j == 0) {
        for (int k = 0; k < top; k++) {
          temp[k][j] = vt[cnt++];
        }
      } else {
        temp[i][j--] = vt[cnt++];
      }
    } else {
      if (j != 0 && j % (C - 1) == 0) {
        for (int k = top; k > 0; k--) {
          temp[k][j] = vt[cnt++];
        }
        re = true;
        i = 0;
      } else {
        temp[i][j] = vt[cnt];
        j++;
        cnt++;
      }
    }
  }
  i = bottom;
  j = 0;
  cnt = 0;
  re = false;

  while (cnt < 2 * C + bottom) {
    if (re) {
      if (j == 0) {
        for (int k = i; k > bottom; k--) {
          temp[k][j] = vb[cnt++];
        }
      } else {
        temp[i][j--] = vb[cnt++];
      }
    } else {
      if (j != 0 && j % (C - 1) == 0) {
        for (int k = bottom; k < R - 1; k++) {
          temp[k][j] = vb[cnt++];
        }
        re = true;
        i = R - 1;
      } else
        temp[i][j++] = vb[cnt++];
    }
  }
  return;
}

void go() {
  int cnt = 0;
  int i = top;
  int j = 0;
  bool re = false;
  // 1. 위쪽 공기청정기
  while (cnt < 2 * C + top) {
    if (re) {
      if (j == 0) {
        for (int k = 0; k < top; k++) {
          vt.push_back(temp[k][j]);
          cnt++;
        }
      } else {
        vt.push_back(temp[i][j--]);
        cnt++;
      }
    } else {
      if (j != 0 && j % (C - 1) == 0) {
        for (int k = top; k > 0; k--) {
          vt.push_back(temp[k][j]);
          cnt++;
        }
        re = true;
        i = 0;
      } else {
        vt.push_back(temp[i][j]);
        cnt++;
        if (temp[i][j] == -1) {
          vt.push_back(0);
        }
        j++;
      }
    }
  }
  vt.pop_back();

  // 2. 아래쪽
  i = bottom;
  j = 0;
  cnt = 0;
  re = false;

  while (cnt < 2 * C + bottom) {
    if (re) {
      if (j == 0) {
        for (int k = i; k > bottom; k--) {
          vb.push_back(temp[k][j]);
          cnt++;
        }
      } else {
        vb.push_back(temp[i][j--]);
        cnt++;
      }
    } else {
      if (j != 0 && j % (C - 1) == 0) {
        for (int k = bottom; k < R - 1; k++) {
          vb.push_back(temp[k][j]);
          cnt++;
        }
        re = true;
        i = R - 1;
      } else {
        vb.push_back(temp[i][j]);
        cnt++;
        if (temp[i][j] == -1) {
          vb.push_back(0);
        }
        j++;
      }
    }
  }
  vb.pop_back();
  return;
}

int main() {
  cin >> R >> C >> T;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> maps[i][j];
      if (maps[i][j] == -1) {
        if (top == 0)
          top = i;
        else
          bottom = i;
      }
    }
  }

  while (T--) {
    vt.clear();
    vb.clear();

    // 1. 확산
    spread();

    // 2. 공기청정기
    go();
    // 3. vector -> temp
    vTemp();
    // 4. temp -> maps
    tempMaps();
  }
  cout << answer << '\n';
}