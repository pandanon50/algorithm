#include <bits/stdc++.h>

using namespace std;

int N,cnt;
string str;
stack<char> stk;
 
int main() {
    cin >> N;
    while(N--) {
        cin >> str;
        for (char a : str) {
            if(stk.size() == 0) {
                stk.push(a);
                continue;
            }else {
                if(stk.top() == a) {
                    stk.pop();
                }else {
                    stk.push(a);
                }
            } 
        }
        if(stk.size() == 0) {
            cnt++;
        }
        while( !stk.empty() )  stk.pop(); 
    }
    cout << cnt << '\n';
    return 0;
}