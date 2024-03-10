#include <bits/stdc++.h>
using namespace std;

string words;
int main() {
  cin >> words;
  string temp = words; 
  reverse(words.begin(), words.end());
  bool check = temp == words;
  cout << check << '\n';
  return 0;
}