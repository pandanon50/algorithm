#include <bits/stdc++.h>

using namespace std;

string st1,temp,answer;
vector<string> v;
int zero_cnt;
int N;

bool cmp(string a, string b) {
    if(a.size() == b.size()) {
        return a < b;

    }
    else return a.size() < b.size();
}

int main() {
   cin >> N;
   for(int i = 0; i < N; i++) {
      cin >> st1;
      temp = "";
      for(int j = 0; j < st1.size(); j++) {
          if(st1[j] < 65) temp += st1[j];
          else if(temp.size()) {
            answer = "";
            zero_cnt = 0;
            for(int k = 0; k < temp.size(); k++) {
                int num2 = temp[k] - '0';
                if(num2 == 0) zero_cnt++;
                else {
                    answer = temp.substr(zero_cnt,temp.size());
                    break;
                }
            }
            if(temp.size() != 0) {
                if(temp.size() == zero_cnt) {
                    v.push_back("0");
                }
                else v.push_back(answer);
                temp = "";
            }
          }
      }
      if(temp.size()) {
        answer = "";
        zero_cnt = 0;
        for(int k = 0; k < temp.size(); k++) {
            int num2 = temp[k] - '0';
            if(num2 == 0) zero_cnt++;
            else {
                answer = temp.substr(zero_cnt,temp.size());
                break;
            }
        }
        if(temp.size() == zero_cnt) {
            cout << temp << '\n';
            cout <<temp.size() << '\n';
            cout << zero_cnt << '\n';
        }
        else v.push_back(answer);
      }
   }
   sort(v.begin(),v.end(),cmp);
   for (string li : v) {
       cout << li << '\n';
   }

   return 0;
}

// 정답코드

// #include <bits/stdc++.h>
// using namespace std;   
// int n; 
// vector<string> v; 
// string s, ret;
// void go(){   
// 	while(true){  
// 		if(ret.size() && ret.front() == '0')ret.erase(ret.begin()); 
// 		else break;
// 	}
// 	if(ret.size() == 0) ret = "0"; 
// 	v.push_back(ret);
// 	ret = "";  
// }
// bool cmp(string a, string b){
// 	if(a.size() == b.size()) return a < b;
// 	return a.size() < b.size();
// }
// int main () {
// 	cin >> n; 
// 	for(int i = 0; i < n; i++){
// 		cin >> s; 
// 	 	ret = "";
// 		for(int j = 0; j < s.size(); j++){
// 			if(s[j] < 65)ret += s[j];
// 			else if(ret.size()) go(); 
// 		}
// 		if(ret.size()) go(); 
// 	}
// 	sort(v.begin(), v.end(), cmp);
// 	for(string i : v)cout << i << "\n"; 
// 	return 0;
// }

