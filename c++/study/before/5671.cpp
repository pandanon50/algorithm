#include <bits/stdc++.h>

using namespace std;

int N,M,cnt; 
const int MAX_LEN = 5005;
int visited[MAX_LEN];
set <int> v;
int main(){
    
    while(cin >> N >> M) {
        cnt = 0;
        for(int i = N; i <= M; i++) {
            string str = to_string(i);
            v.clear();
            for(int k = 0; k < str.size(); k++) {

                v.insert(str[k] - 48);
            }
    
            if(str.size() == v.size()) {
                cnt++;
            }            
        }
        cout << cnt << '\n';
    }
    
}