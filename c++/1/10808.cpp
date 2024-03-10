#include <algorithm>
#include <iostream>

using namespace std;
int answer[26];
string S;

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> S;
  for(char alpha : S) {
    answer[alpha - 97]++;
  }
  for(int i = 0; i < 26; i++) cout << answer[i] << " ";

  return 0;
}