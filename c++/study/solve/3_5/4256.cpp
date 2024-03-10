// BOJ 4256 트리
// https://www.acmicpc.net/problem/4256
#include <bits/stdc++.h>

using namespace std;

int T, N, preIndex;

vector<int> preorder;
vector<int> inorder;

map<int, int> mp;

void go(int start, int end) {
  if (start == end) {
    cout << inorder[start] << " ";
    return;
  }

  int rootIdx = mp[preorder[preIndex]];

  if (rootIdx - 1 >= start) {
    preIndex++;
    go(start, rootIdx - 1);
  }
  if (rootIdx + 1 <= end) {
    preIndex++;
    go(rootIdx + 1, end);
  }
  cout << inorder[rootIdx] << " ";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;
  for (int i = 0; i < T; i++) {
    inorder.clear();
    preorder.clear();
    preIndex = 0;

    cin >> N;
    int input;
    for (int i = 0; i < N; i++) {
      cin >> input;
      preorder.push_back(input);
    }
    for (int i = 0; i < N; i++) {
      cin >> input;
      inorder.push_back(input);
      mp[input] = i;
    }

    go(0, N - 1);
    cout << '\n';
  }

  return 0;
}