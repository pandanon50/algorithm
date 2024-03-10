#include <bits/stdc++.h>
using namespace std;

// 0 -> start 
// 1 -> end
vector <string> pattern;
int N;

void split(string s) {
  string temp = "";
  for(char check : s) {
      if(check == '*') {
         pattern.push_back(temp);
         temp = "";
      }else {
        temp += check;
      }
  }
  pattern.push_back(temp);
}

int main() {
    string p;
    cin >> N;
    cin >> p;
    split(p);
    string problem;
    for (int i = 0; i < N; i++) {
        problem = "";
        cin >> problem;
        int flag = 0;
        for(int k = 0; k < 2; k++) {
            string compare = pattern[k];
            if(k == 0) {
                for(int j = 0; j < compare.size(); j++) {
                    if(compare[j] != problem[j]) {
                        flag = -1;
                        break;
                    }
                }
            }

            if(flag == -1) break;

            if (k == 1) {
                for (int j = 0; j < compare.size(); j++) {
                    if(compare[j] != problem[problem.size() - compare.size() + j]) {
                        flag = -1;
                        break;
                    }
                }
            }
            if(flag == 0 && (problem.size() < pattern[0].size() + pattern[1].size())) {
                flag = -1;
            }
        }
        if(flag == 0) cout << "DA" << "\n";
        else cout << "NE" << "\n";
    }
}