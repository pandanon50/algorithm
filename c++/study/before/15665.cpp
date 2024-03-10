#include <bits/stdc++.h>

using namespace std;

int N,M;
vector <int> item;
map<string,int> mp;
void combi(int depth, vector<int> com) {
    if(com.size() == M) {
        string key;
        for(int i = 0; i < com.size(); i++) {
            string s = to_string(com[i]);
            string str = "";
            for(int i = 0; i < s.size(); i++) {
                str += s[i];
            }
            key += str;
        }
        if(mp[key] == 0) {
            for(int i = 0; i < com.size(); i++) {
                cout << com[i] << " ";
            }
            cout << '\n';
            mp[key] = 1;
        }
        return;
    }

    for(int i = 0; i < N; i++) {
        // if(i == depth) continue;
        com.push_back(item[i]);
        combi(i,com);
        com.pop_back();
    }
    return;
}

int main(){

    cin >> N >> M;
    int input = 0;
    for(int i = 0; i < N; i++) {
        cin >> input;
        item.push_back(input);
    }
    sort(item.begin(),item.end());
    vector <int> v;
    combi(0,v);
    return 0;
}