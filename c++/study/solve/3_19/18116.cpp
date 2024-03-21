// BOJ 18116 로봇조립
// https://www.acmicpc.net/problem/18116
#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1000002;
int N, u, v;
char input;
int parent_copy[MAX_N];
int parent[MAX_N];
int r[MAX_N];
int s[MAX_N];
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
  s[b] += s[a];
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  cin >> N;

  for (int i = 1; i <= MAX_N; i++) {
    parent[i] = i;
    r[i] = 1;
    s[i] = 1;
  }

  for (int i = 0; i < N; i++) {
    cin >> input;
    if (input == 'I') {
      cin >> u >> v;
      merge(u, v);
    }
    if (input == 'Q') {
      cin >> u;
      int check = find(u);
      cout << s[check] << '\n';
    }
  }
  return 0;
}
// 처음 지금까지 알아낸 부품의 갯수 -> log(n)으로 풀기위해 find(check)와 같은
// 부모를 가진 값들을 이분탐색하려고함 -> sorting이 안됨. set_union 으로 부품의
// 집합을 만들 때 s[큰 집합] += s[작은 집합]를 이용해 갯수를 확인 단순하게
// 생각하자...!