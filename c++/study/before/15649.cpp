#include <bits/stdc++.h>

using namespace std;

int N,M;
map<string,int> mp;
vector<int> check;
int main(){
    cin >> N >> M;
    vector <int> v;
    vector <int> temp; 
    for(int i = 1; i <= N; i++) {
        if(i <= M) {
            temp.push_back(1);
        }else{
            temp.push_back(0);
        }
        v.push_back(i);
    }
    do{
        string s;
        check.clear();
        for(int i = 0; i < v.size(); i++) {
            if(temp[i] == 1) {
                s += v[i] - 48;
                check.push_back(v[i]);
            }
        }
        if(mp[s] == 0) {
            for(auto it : check) {
                cout << it << " ";
            }
            cout << '\n';
            mp[s] = 1;
        }
    }while(next_permutation(v.begin(),v.end()));
}