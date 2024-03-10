#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


vector<string> split(string s,string d) {
  
    vector<string> res;
    string token = "";
    long long len = 0;
    while((len = s.find(d))!= string::npos) {
        token = s.substr(0,len);
        res.push_back(token);
        s.erase(0, len + d.length());
    }
    res.push_back(s);
    return res;
}



int main() {
    string s1;
    string ans = "";
    getline(cin,s1);
    

    vector<string> result = split(s1," ");
    for(string b : result) {
   
        
    reverse(b.begin(),b.end());
      if(ans == "") {
        ans = b;
      }else {
        if (stoi(ans) < stoi(b)) {
          ans = b;
        }
      }
    }
    cout << ans << '\n';
} 
