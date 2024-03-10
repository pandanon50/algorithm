#include <bits/stdc++.h>

using namespace std;

string code;
string answer;
int main() {
  getline(cin,code);

  for(char c : code) {

    if(c >= 'A' && c <= 'Z') {
        // 65 ~ 90
        if(c + 13 > 90) {
            answer += (64 + c + 13 - 90);
        }else {
            answer += (c + 13);
        }
    }else if(c >= 'a' && c <= 'z') {
        if(c + 13 > 122) {
            answer += (96 + c + 13 - 122);
        }else {
            answer += (c + 13);
        } 
    }else {
        answer += c;
    }
  }
  cout << answer << '\n';
  return 0;
}