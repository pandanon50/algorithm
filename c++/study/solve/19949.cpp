// 261622
// 1 2 3 4 5 1 2 3 4 5
#include <bits/stdc++.h>

using namespace std;
const int MAX_LEN = 12;
int arr[MAX_LEN];
int answer;
vector<int> v;

bool wrongCheck(vector<int> b, int size) {
  int temp = 0;
  int cnt = 0;
  for (int i = 0; i < size; i++) {
    if (cnt == 2) {
      return false;
    }
    if (i != 0 && temp == b[i]) {
      cnt++;
    } else {
      temp = b[i];
      cnt = 0;
    }
  }
  return cnt != 2;
}
bool answerCheck(vector<int> b) {
  int cnt = 0;
  for (int i = 0; i < 10; i++) {
    if (b[i] == arr[i]) cnt++;
  }
  return cnt >= 5;
}

void combi(vector<int> b) {
  if (b.size() == 10) {
    if (wrongCheck(b, 10) && answerCheck(b)) {
      answer++;
    }
    return;
  }
  if (b.size() > 2) {
    if (wrongCheck(b, b.size()) == false) {
      return;
    }
  }

  for (int i = 1; i <= 5; i++) {
    b.push_back(i);
    combi(b);
    b.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < 10; i++) {
    cin >> arr[i];
  }

  combi(v);

  cout << answer << '\n';
}