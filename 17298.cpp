#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 1000010;
int N;
int arr[MAX_N];
stack<int> s;
int answer[MAX_N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    s.push(arr[i]);
  }
  answer[N - 1] = -1;
  int temp = 0;
  for (int i = N - 2; i >= 0; i--) {
    if (temp != 0) {
      if (arr[i] < s.top()) {
        answer[i] = s.top();
      } else {
        if (arr[i] < temp) {
          answer[i] = temp;
        } else {
          answer[i] = -1;
        }
      }
    } else {
      temp = s.top();
      if (arr[i] < s.top()) {
        answer[i] = s.top();
      } else {
        answer[i] = -1;
      }
    }
    s.pop();
  }

  for (int i = 0; i < N; i++) {
    cout << answer[i] << " ";
  }
  cout << '\n';
  return 0;
}