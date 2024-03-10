#include <bits/stdc++.h>

using namespace std;

int N, root, answer, dV;
const int MAX_LEN = 50;

vector<int> v[MAX_LEN];
int visited[MAX_LEN];

void dfs(int there) {
  visited[there] = 1;

  for (int here : v[there]) {
    if (visited[here] == 0) {
      dfs(here);
    }
  }
  return;
}

int main() {
  cin >> N;
  int value = 0;
  for (int i = 0; i < N; i++) {
    cin >> value;
    if (value == -1) {
      root = i;
    } else {
      v[value].push_back(i);
    }
  }
  cin >> dV;
  if (dV == root) {
    cout << '0' << '\n';
  } else {
    int check_i = -1;
    int check_j = -1;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < v[i].size(); j++) {
        if (v[i][j] == dV) {
          check_i = i;
          check_j = j;
          break;
        }
      }
      if (check_i != -1) {
        break;
      }
    }

    v[check_i].erase(v[check_i].begin() + check_j);

    dfs(dV);

    for (int i = 0; i < N; i++) {
      if (visited[i] == 0 && v[i].size() == 0) {
        answer++;
      }
    }
    cout << answer << '\n';
  }

  return 0;
}