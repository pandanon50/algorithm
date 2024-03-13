// 수에 대해서 짝을 지어준다 (스택활용 확률있음)
// N^2 -> N
#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1000010;
int N;

int arr[MAX_N], ret[MAX_N];
stack<int> s;
int main() {
  cin >> N;
  memset(ret, -1, sizeof(ret));
  for (int i = 0; i < N; i++) {
    cin >> arr[i];

    while (s.size() && arr[s.top()] < arr[i]) {
      ret[s.top()] = arr[i];
      s.pop();
    }
    s.push(i);
  }
  for (int i = 0; i < N; i++) cout << ret[i] << " ";
  cout << '\n';
  return 0;
}