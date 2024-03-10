#include <bits/stdc++.h>

using namespace std;

int N, t_cost, t_p, t_s, t_f, t_v, mp, mf, ms, mv, answer = 1000000;
const int MAX_N = 16;
int table[MAX_N][5];

map<int, vector<vector<int>>> ret_v;

int main() {
  cin >> N;
  cin >> mp >> mf >> ms >> mv;

  // 0:단백질, 1:지방, 2:탄수화물, 3:비타민, 4:비용
  for (int i = 0; i < N; i++) {
    cin >> table[i][0] >> table[i][1] >> table[i][2] >> table[i][3] >>
        table[i][4];
  }

  for (int i = 1; i < (1 << N); i++) {
    t_p = 0;
    t_f = 0;
    t_s = 0;
    t_v = 0;
    t_cost = 0;
    vector<int> good_bit;
    for (int j = 0; j < N; j++) {
      if (i & (1 << j)) {
        good_bit.push_back(j + 1);
        t_p += table[j][0];
        t_f += table[j][1];
        t_s += table[j][2];
        t_v += table[j][3];
        t_cost += table[j][4];
      }
    }

    if (t_p >= mp && t_f >= mf && t_s >= ms && t_v >= mv) {
      if (answer >= t_cost) {
        answer = t_cost;
        ret_v[answer].push_back(good_bit);
      }
    }
  }

  if (answer == 1000000) {
    cout << -1 << '\n';
  } else {
    sort(ret_v[answer].begin(), ret_v[answer].end());
    cout << answer << '\n';
    for (int a : ret_v[answer][0]) {
      cout << a << " ";
    }
  }
  return 0;
}