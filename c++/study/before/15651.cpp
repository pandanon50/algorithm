#include <bits/stdc++.h>
using namespace std;

int N,M;

void combi(int depth, vector <int> v) {
    
    if(v.size() == M) {
        for(auto it : v) {
            cout << it << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = 1; i <= N; i++) {
        v.push_back(i);
        combi(i,v);
        v.pop_back();
    }
    return;
}

int main() {
    cin >> N >> M;
    vector <int> k;
    combi(0,k);


}