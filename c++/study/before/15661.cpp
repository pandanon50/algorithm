#include <bits/stdc++.h>

using namespace std;

int N,result = 999999999, K;
const int MAX_LEN = 23;
int matrix[MAX_LEN][MAX_LEN];
int visited[MAX_LEN];

int check(vector <int> team) {
   
    if(team.size() == 2) {
        return matrix[team[0] - 1][team[1] - 1] + matrix[team[1] - 1][team[0] - 1];
    }

    vector<int> v1,v2;
    for(int i = 0; i < team.size() - 1; i++) {
        v1.push_back(team[i]);
    }
    int end_value = team[team.size() - 1];     
    int sum = 0;
    v2.push_back(end_value);
    for(int i = 0; i < v1.size(); i++) {
        v2.push_back(v1[i]);
        sum += check(v2);
        v2.pop_back();
    }
    team.pop_back();
    return check(team) + sum;
    
}

void com(int depth, vector <int> b) {

    if(b.size() == K) {
        vector <int> t_link;
        for(int i = 1; i <= N;i++) {
            if(visited[i] == 0) t_link.push_back(i);
        }
        int start_sum = 0,link_sum = 0;

        start_sum = check(b);
        link_sum = check(t_link);

        if(start_sum - link_sum == 0 || link_sum - start_sum == 0) {
            cout << '0' << '\n';
            exit(0);
        }

        if(start_sum > link_sum) {
            result = min(start_sum - link_sum, result);
        }else {
            result = min(link_sum - start_sum, result);
        }
        return;
    }

    for(int i = depth + 1; i <= N; i++){
        b.push_back(i);
        visited[i] = 1;
        com(i,b);
        visited[i] = 0;
        b.pop_back();
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    K = N / 2;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
    vector <int> vcom;
    com(0,vcom);
    cout << result << '\n';
}