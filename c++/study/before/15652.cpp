#include <bits/stdc++.h>
using namespace std;

int N,M;
int cnt[10];
map <string,int> mp;
void combi(int depth ,vector <int> v) {
    if(v.size() == M) {
        for(auto it : v) {
            cout << it << " ";
        }
        cout << '\n'; 
        return;
    }

    for(int i = depth; i <= N; i++) {
        v.push_back(i);
        combi(i,v);
        v.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    vector <int> k;
    combi(1,k);

    return 0;
}