// BOJ 2852 NBA 농구
// https://www.acmicpc.net/problem/2852

#include <bits/stdc++.h>

using namespace std;

int N, A, B, team, osum, ssum;
string s, prev_s;
int stoi_time(string a) {
  return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

void print() {
  string s1, s2;
  string z = "";
  string z1 = "";
  s1 = to_string(osum / 60);
  s2 = to_string(osum % 60);
  if (s1.size() == 1) {
    z += "0";
  }
  if (s2.size() == 1) {
    z1 += "0";
  }
  cout << z << s1 << ":" << z1 << s2 << '\n';

  s1 = to_string(ssum / 60);
  s2 = to_string(ssum % 60);
  z = "";
  z1 = "";
  if (s1.size() == 1) {
    z += "0";
  }
  if (s2.size() == 1) {
    z1 += "0";
  }
  cout << z << s1 << ":" << z1 << s2 << '\n';
}

void go(int t, string start, string end) {
  int sec = stoi_time(end) - stoi_time(start);
  if (t == 1)
    osum += sec;
  else
    ssum += sec;
  return;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> team >> s;
    if (A > B)
      go(1, prev_s, s);
    else if (A < B)
      go(2, prev_s, s);
    team == 1 ? A++ : B++;
    prev_s = s;
  }
  if (A > B) {
    go(1, prev_s, "48:00");
  } else if (A < B) {
    go(2, prev_s, "48:00");
  }
  print();
  return 0;
}

// 1. 시간은 통일해서 한번에 넘겨준다
// 2. now - prev 팀스코어 조건에 맞게 처리