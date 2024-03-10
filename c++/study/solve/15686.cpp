#include <bits/stdc++.h>

using namespace std;

int N, M, answer = 1e9;

const int MAX_LEN = 52;
int maps[MAX_LEN][MAX_LEN];
vector<pair<int, int>> ck_map;

int search_ck(vector<int> c) {
  int sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (maps[i][j] == 1) {
        int distance = 1e9;
        for (auto it : c) {
          int ck_y = ck_map[it].first;
          int ck_x = ck_map[it].second;
          distance = min(distance, abs(i - ck_y) + abs(j - ck_x));
        }
        sum += distance;
      }
    }
  }
  return sum;
}

void combi(int depth, vector<int> b) {
  if (b.size() == M) {
       answer = min(answer, search_ck(b));
    return;
  }

  for (int i = depth + 1; i < ck_map.size(); i++) {
    b.push_back(i);
    combi(i, b);
    b.pop_back();
  }
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> maps[i][j];
      if (maps[i][j] == 2) {
        ck_map.push_back({i, j});
        maps[i][j] = 0;
      }
    }
  }
  vector<int> v;
  combi(-1, v);
  cout << answer << '\n';
}