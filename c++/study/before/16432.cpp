#include <bits/stdc++.h>

using namespace std;

int N;
const int MAX_N = 1010;
vector<int> answer;
vector<int> v[MAX_N];

bool check(vector<int> c) {
  int temp = -1;
  for (int i = 0; i < c.size(); i++) {
    if (temp == c[i])
      return false;
    else
      temp = c[i];
  }
  return true;
}

void dfs(int depth, vector<int> b) {
  if (b.size() == 2) {
    if (b[0] == b[1]) return;
  }

  if (b.size() > 2 && b.size() <= N) {
    bool isGo = check(b);

    if (isGo == false) return;

    if (isGo && b.size() == N) {
      for (auto it : b) {
        cout << it << '\n';
      }
      exit(0);
    }
    if (b.size() == N) return;
  }

  for (int i = 0; i < v[depth + 1].size(); i++) {
    answer.push_back(v[depth + 1][i]);
    dfs(depth + 1, answer);
    answer.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  int v_size = 0;
  int input = 0;
  for (int i = 0; i < N; i++) {
    cin >> v_size;
    for (int j = 0; j < v_size; j++) {
      cin >> input;
      v[i].push_back(input);
    }
  }

  for (int i = 0; i < v[0].size(); i++) {
    answer.push_back(v[0][i]);
    dfs(0, answer);
    answer.pop_back();
  }
  cout << -1 << '\n';

  return 0;
}