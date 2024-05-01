#include <bits/stdc++.h>

using namespace std;

int N = 0

    int
    find(int u) {
  if (parent[u] == u)
    return u;

  else
    return parent[u] = find(parent[u]);
}

void set_union(int a, int b) {
  a = find(a);
  b = find(b);

  if (a == b) return;

  if (r[a] > r[b]) swap(a, b);

  if (r[a] == r[b]) r[b]++;

  parent[a] = b;

  return;
}

int main() { return 0; }