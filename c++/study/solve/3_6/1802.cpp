// BOJ 1802 종이접기
// https://www.acmicpc.net/problem/1802
#include <bits/stdc++.h>

using namespace std;

int T;
int arr[3010];
bool isAnswer = true;
string s;

void go(int start, int end) {
  if (end - start == 2) {
    if (arr[start] == arr[end]) {
      isAnswer = false;
    }
    return;
  }

  go(start, ((start + end) / 2) - 1);
  go(((start + end) / 2) + 1, end);

  for (int k = 0; k < (end - start) / 2; k++) {
    if (arr[k] == arr[end - k]) {
      isAnswer = false;
      break;
    }
  }

  return;
}

int main() {
  cin >> T;

  for (int i = 0; i < T; i++) {
    isAnswer = true;
    cin >> s;
    for (int k = 0; k < s.size(); k++) {
      arr[k] = s[k] - '0';
    }
    if (s.size() == 1) {
      cout << "YES" << '\n';
      continue;
    }
    go(0, s.size() - 1);
    if (isAnswer)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }

  return 0;
}