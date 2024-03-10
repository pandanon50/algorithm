#include <bits/stdc++.h>

using namespace std;

vector <int> v;
int N,
void combi(int depth, vector <int> b) {
    
    if(b.size() == M) {
        for(auto it : b) {
            cout << it << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = depth + 1; i < N; i++) {
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

    vector <int> com;

    combi(-1,com);
    
    return 0;
}