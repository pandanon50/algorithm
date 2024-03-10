#include <bits/stdc++.h>

using namespace std;

int N,M;
map<string,int> mp;
vector<string> check;
int main(){
    cin >> N >> M;
    int input = 0;
    vector <int> v;
    for(int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(),v.end());

    do{
        string s;
        check.clear();
        for(int i = 0; i < M; i++) {
            string str = to_string(v[i]);
            s += str;
            check.push_back(str);
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