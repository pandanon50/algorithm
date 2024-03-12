// BOJ 1436 영화감독 숌
// https://www.acmicpc.net/problem/1436
#include <bits/stdc++.h>

using namespace std;

int N, answer;
vector<string> s;

int main() {
  string s1 = "";
  int i = 666;
  cin >> answer;
  while (N < 10000) {
    s1 = to_string(i);
    int cnt = 0;
    for (int k = 0; k < s1.size(); k++) {
      if (s1[k] - 48 == 6) {
        cnt++;
      } else
        cnt = 0;

      if (cnt == 3) {
        s.push_back(s1);
        N++;
        break;
      }
    }
    i++;
  }
  cout << s[answer - 1] << '\n';
  return 0;
}