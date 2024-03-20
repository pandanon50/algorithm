#include <bits/stdc++.h>

using namespace std;

const int MAX_F = 200001;
int T, F, cnt;
int parent[MAX_F];
int r[MAX_F];
int s[MAX_F];
map<string, int> mp;

int find(int u) {
  if (parent[u] == u) return u;

  return parent[u] = find(parent[u]);
}

void set_union(int a, int b) {
  a = find(a);
  b = find(b);

  if (a == b) return;

  if (r[a] > r[b]) swap(a, b);

  if (r[a] == r[b]) r[b]++;
  parent[a] = b;
  s[b] += s[a];
}

int isFriends(string f) {
  if (mp[f] == 0) {
    mp[f] = cnt;
    parent[mp[f]] = cnt++;
    r[mp[f]] = 1;
    s[mp[f]] = 1;
    return parent[mp[f]];
  } else
    return find(mp[f]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> T;
  string f1, f2;

  for (int tcase = 0; tcase < T; tcase++) {
    cin >> F;
    for (int i = 0; i < F; i++) {
      cin >> f1 >> f2;
      set_union(isFriends(f1), isFriends(f2));

      int r1 = find(mp[f1]);
      int r2 = find(mp[f2]);

      cout << max(s[r1], s[r2]) << '\n';
    }
    mp.clear();
    memset(parent, 0, sizeof(parent));
    memset(r, 0, sizeof(r));
    memset(s, 0, sizeof(s));
  }

  return 0;
}