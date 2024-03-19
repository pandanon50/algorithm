#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1000000;
int N, u, v;
char input;
int parent_copy[MAX_N];
int parent[MAX_N];
int r[MAX_N];

int find(int a) {
  if (parent[a] == a) return a;

  return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);

  if (a == b) return;

  if (r[a] > r[b]) swap(a, b);

  if (r[a] == r[b]) r[b]++;
  parent[a] = b;
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    parent[i] = i;
    r[i] = 1;
  }

  for (int i = 0; i < N; i++) {
    cin >> input;
    if (input == 'I') {
      cin >> u >> v;
      merge(u - 1, v - 1);
    }
    if (input == 'Q') {
      cin >> u;
      int check = find(u - 1);
      copy(parent, parent + N, parent_copy);
      sort(parent_copy, parent_copy + N);
      auto up = upper_bound(parent_copy, parent_copy + N, check);
      auto low = lower_bound(parent_copy, parent_copy + N, check);

      cout << up - low << '\n';
    }
  }
  return 0;
}