#include <bits/stdc++.h>

using namespace std;

int N,M;
vector <int> v;

void combi(int depth, vector<int>b) {
    if(b.size() == M) {
        
        for(auto it : b) {
            cout << it << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = depth; i < N; i++) {
        b.push_back(v[i]);
        combi(i,b);
        b.pop_back();
    }
    return;
}

int main() {

    cin >> N >> M;
    int input = 0;
    for(int i = 0; i < N; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(),v.end());
    vector <int> check;
    combi(0,check);


}