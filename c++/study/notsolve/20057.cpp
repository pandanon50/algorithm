#include <bits/stdc++.h>

using namespace std;

int N, sy, sx, answer;

const int MAX_LEN = 500;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};

// pair<int,int> dirSandPercent[4][15];
vector<pair<int, int>> dirSandPercent[4];
int matrix[MAX_LEN][MAX_LEN];

int outer(int cy, int cx) {
  if (cy < 0 || cx < 0 || cy >= N || cx >= N) {
    return 0;
  } else {
    return 1;
  }
}

void makeSand(int dir, int cy, int cx) {
  int outSand = 0;
  int inSand = 0;
  // cout << "dir -> " << dir << " cy -> " << cy << " cx ->" << cx << '\n';
  if (dir == 0) {
    if (outer(cy - 1, cx)) {
      inSand = (int)(matrix[cy][cx] * 0.07);
      matrix[cy - 1][cx] += (int)(matrix[cy][cx] * 0.07);

    } else {
      outSand += (int)(matrix[cy][cx] * 0.07);
    }

    if (outer(cy + 1, cx)) {
      inSand = (int)(matrix[cy][cx] * 0.07);
      matrix[cy + 1][cx] += (int)(matrix[cy][cx] * 0.07);
      cout << "inSand" << inSand << '\n';

    } else
      outSand += (int)(matrix[cy][cx] * 0.07);

    if (outer(cy - 1, cx - 1)) {
      matrix[cy - 1][cx - 1] += (int)(matrix[cy][cx] * 0.1);
      inSand = (int)(matrix[cy][cx] * 0.1);
      cout << "inSand" << inSand << '\n';

    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy + 1, cx - 1)) {
      matrix[cy + 1][cx - 1] += (int)(matrix[cy][cx] * 0.1);
      inSand = (int)(matrix[cy][cx] * 0.1);

      cout << "inSand" << inSand << '\n';

    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy + 2, cx)) {
      matrix[cy + 2][cx] += (int)(matrix[cy][cx] * 0.02);
      inSand = (int)(matrix[cy][cx] * 0.02);

      cout << "inSand" << inSand << '\n';

    } else
      outSand += (int)(matrix[cy][cx] * 0.02);

    if (outer(cy - 2, cx)) {
      matrix[cy - 2][cx] += (int)(matrix[cy][cx] * 0.02);
      inSand = (int)(matrix[cy][cx] * 0.02);

      cout << "inSand" << inSand << '\n';

    } else
      outSand += (int)(matrix[cy][cx] * 0.02);

    if (outer(cy - 1, cx + 1)) {
      matrix[cy - 1][cx + 1] += (int)(matrix[cy][cx] * 0.01);
      inSand = (int)(matrix[cy][cx] * 0.01);

      cout << "inSand" << inSand << '\n';

    } else
      outSand += (int)(matrix[cy][cx] * 0.01);

    if (outer(cy + 1, cx + 1)) {
      matrix[cy + 1][cx + 1] += (int)(matrix[cy][cx] * 0.01);
      inSand = (int)(matrix[cy][cx] * 0.01);

      cout << "inSand" << inSand << '\n';

    } else
      outSand += (int)(matrix[cy][cx] * 0.01);

    if (outer(cy, cx - 2)) {
      matrix[cy][cx - 2] += (int)(matrix[cy][cx] * 0.05);
      inSand = (int)(matrix[cy][cx] * 0.05);

      cout << "inSand" << inSand << '\n';
    } else
      outSand += (int)(matrix[cy][cx] * 0.05);

    // end
    if (outer(cy, cx - 1)) {
      matrix[cy][cx - 1] += (matrix[cy][cx] - (outSand + inSand));
    } else {
      outSand += matrix[cy][cx] - inSand;
    }

  } else if (dir == 1) {
    if (outer(cy, cx - 1)) {
      matrix[cy][cx - 1] += (int)(matrix[cy][cx] * 0.07);
      inSand = (int)(matrix[cy][cx] * 0.07);

    } else
      outSand += (int)(matrix[cy][cx] * 0.07);

    if (outer(cy, cx + 1)) {
      matrix[cy][cx + 1] += (int)(matrix[cy][cx] * 0.07);
      inSand = (int)(matrix[cy][cx] * 0.07);

    } else
      outSand += (int)(matrix[cy][cx] * 0.07);

    if (outer(cy + 1, cx - 1)) {
      matrix[cy + 1][cx - 1] += (int)(matrix[cy][cx] * 0.1);
      inSand = (int)(matrix[cy][cx] * 0.1);

    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy + 1, cx + 1)) {
      matrix[cy + 1][cx + 1] += (int)(matrix[cy][cx] * 0.1);
      inSand = (int)(matrix[cy][cx] * 0.1);

    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy, cx - 2)) {
      matrix[cy][cx - 2] += (int)(matrix[cy][cx] * 0.02);
      inSand = (int)(matrix[cy][cx] * 0.02);

    } else
      outSand += (int)(matrix[cy][cx] * 0.02);

    if (outer(cy, cx + 2)) {
      matrix[cy][cx + 2] += (int)(matrix[cy][cx] * 0.02);
      inSand = (int)(matrix[cy][cx] * 0.02);

    } else
      outSand += (int)(matrix[cy][cx] * 0.02);

    if (outer(cy - 1, cx - 1)) {
      matrix[cy - 1][cx - 1] += (int)(matrix[cy][cx] * 0.01);
      inSand = (int)(matrix[cy][cx] * 0.01);

    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy - 1, cx + 1)) {
      matrix[cy - 1][cx + 1] += (int)(matrix[cy][cx] * 0.01);
      inSand = (int)(matrix[cy][cx] * 0.01);

    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy + 2, cx)) {
      matrix[cy + 2][cx] += (int)(matrix[cy][cx] * 0.05);
      inSand = (int)(matrix[cy][cx] * 0.05);

    } else
      outSand += (int)(matrix[cy][cx] * 0.05);

    // end
    if (outer(cy + 1, cx)) {
      matrix[cy + 1][cx] += (matrix[cy][cx] - (outSand + inSand));
    } else {
      outSand += matrix[cy][cx] - inSand;
    }

  } else if (dir == 2) {
    if (outer(cy + 1, cx)) {
      matrix[cy + 1][cx] += (int)(matrix[cy][cx] * 0.07);
      inSand = (int)(matrix[cy][cx] * 0.07);

    } else
      outSand += (int)(matrix[cy][cx] * 0.07);

    if (outer(cy - 1, cx)) {
      matrix[cy - 1][cx] += (int)(matrix[cy][cx] * 0.07);
      inSand = (int)(matrix[cy][cx] * 0.07);

    } else
      outSand += (int)(matrix[cy][cx] * 0.07);

    if (outer(cy - 1, cx + 1)) {
      matrix[cy - 1][cx + 1] += (int)(matrix[cy][cx] * 0.1);
      inSand = (int)(matrix[cy][cx] * 0.1);

    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy + 1, cx + 1)) {
      matrix[cy + 1][cx + 1] += (int)(matrix[cy][cx] * 0.1);
      inSand = (int)(matrix[cy][cx] * 0.1);

    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy + 2, cx)) {
      matrix[cy + 2][cx] += (int)(matrix[cy][cx] * 0.02);
      inSand = (int)(matrix[cy][cx] * 0.02);

    } else
      outSand += (int)(matrix[cy][cx] * 0.02);

    if (outer(cy - 2, cx)) {
      matrix[cy - 2][cx] += (int)(matrix[cy][cx] * 0.02);
      inSand = (int)(matrix[cy][cx] * 0.02);

    } else
      outSand += (int)(matrix[cy][cx] * 0.02);

    if (outer(cy - 1, cx - 1)) {
      matrix[cy - 1][cx - 1] += (int)(matrix[cy][cx] * 0.01);
      inSand = (int)(matrix[cy][cx] * 0.01);

    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy + 1, cx - 1)) {
      matrix[cy + 1][cx - 1] += (int)(matrix[cy][cx] * 0.01);
      inSand = (int)(matrix[cy][cx] * 0.01);

    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy, cx + 2)) {
      matrix[cy][cx + 2] += (int)(matrix[cy][cx] * 0.05);
      inSand = (int)(matrix[cy][cx] * 0.05);
    } else
      outSand += (int)(matrix[cy][cx] * 0.05);

    // end
    if (outer(cy, cx + 1)) {
      matrix[cy][cx + 1] += (matrix[cy][cx] - (outSand + inSand));
    } else {
      outSand += matrix[cy][cx] - inSand;
    }

  } else {
    if (outer(cy, cx - 1)) {
      matrix[cy][cx - 1] += (int)(matrix[cy][cx] * 0.07);
      inSand = (int)(matrix[cy][cx] * 0.07);

    } else
      outSand += (int)(matrix[cy][cx] * 0.07);

    if (outer(cy, cx + 1)) {
      matrix[cy][cx + 1] += (int)(matrix[cy][cx] * 0.07);
      inSand = (int)(matrix[cy][cx] * 0.07);
    } else
      outSand += (int)(matrix[cy][cx] * 0.07);

    if (outer(cy - 1, cx - 1)) {
      matrix[cy - 1][cx - 1] += (int)(matrix[cy][cx] * 0.1);
      inSand = (int)(matrix[cy][cx] * 0.1);
    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy - 1, cx + 1)) {
      matrix[cy - 1][cx + 1] += (int)(matrix[cy][cx] * 0.1);
      inSand = (int)(matrix[cy][cx] * 0.1);
    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy, cx + 2)) {
      matrix[cy][cx + 2] += (int)(matrix[cy][cx] * 0.02);
      inSand = (int)(matrix[cy][cx] * 0.02);
    } else
      outSand += (int)(matrix[cy][cx] * 0.02);

    if (outer(cy, cx - 2)) {
      matrix[cy][cx - 2] += (int)(matrix[cy][cx] * 0.02);
      inSand = (int)(matrix[cy][cx] * 0.02);
    } else
      outSand += (int)(matrix[cy][cx] * 0.02);

    if (outer(cy + 1, cx - 1)) {
      matrix[cy + 1][cx - 1] += (int)(matrix[cy][cx] * 0.01);
      inSand = (int)(matrix[cy][cx] * 0.01);
    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy + 1, cx + 1)) {
      matrix[cy + 1][cx + 1] += (int)(matrix[cy][cx] * 0.01);
      inSand = (int)(matrix[cy][cx] * 0.01);
    } else
      outSand += (int)(matrix[cy][cx] * 0.1);

    if (outer(cy - 2, cx)) {
      matrix[cy - 2][cx] += (int)(matrix[cy][cx] * 0.05);
      inSand = (int)(matrix[cy][cx] * 0.05);
    } else
      outSand += (int)(matrix[cy][cx] * 0.05);

    // end
    if (outer(cy - 1, cx)) {
      matrix[cy - 1][cx] += (matrix[cy][cx] - (outSand + inSand));
    } else {
      outSand += matrix[cy][cx] - inSand;
    }
  }
  cout << "outSand" << outSand << '\n';
  cout << "inSand" << inSand << '\n';
  answer += outSand;
  cout << "answer " << answer << '\n';
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> matrix[i][j];
    }
  }

  int move = 0;
  int dir = 0;  // 0: left, 1:bottom, 2: right, 3: top
  int cy = N / 2;
  int cx = N / 2;
  for (int i = 0; i < N * 2 - 1; i++) {
    if (i == 0) {
      move = 1;
      dir = 0;
    } else if (i == N * 2 - 2) {
      move = N - 1;
      dir = 0;
    } else {
      if (i % 2 == 0) move += 1;
      dir = i % 4;
    }

    cout << "i -> " << i << " move -> " << move << '\n';

    for (int j = 0; j < move; j++) {
      int ny = cy + dy[dir];
      int nx = cx + dx[dir];
      cout << "ny : " << ny << " nx : " << nx << '\n';
      if (matrix[ny][nx] != 0) {
        makeSand(dir, ny, nx);
      }
      cy = ny;
      cx = nx;
    }
  }
  cout << answer << '\n';
}