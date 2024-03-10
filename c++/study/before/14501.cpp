#include <bits/stdc++.h>

using namespace std;


int N,result = 0,day,money;

vector <pair<int,int>> v;
vector <int> current; 
void go(int start, vector <int> cu) {
    int sum = 0;
    if(start + v[start].first == N) {
        for(auto it : cu) {
            sum += v[it].second;
        }
        if(result < sum) {
            result = sum;
        }
        return;
    }

    if(start + v[start].first < N) {
        for(int i = start + v[start].first; i < N; i++) {
            cu.push_back(i);
            go(i,cu);
            cu.pop_back();
        }
    }else {
        for(int i = 0; i < cu.size() - 1; i++) {
            sum += v[cu[i]].second;
        }
        if(result < sum) {
            result = sum;
        }
        return;
    }
    return;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> day >> money;
        v.push_back({day,money});        
    }
    vector <int> current; 
    for(int i = 0; i < N; i++) {
        current.push_back(i);
        go(i,current);
        current.pop_back();
    }
    cout << result << '\n';
}