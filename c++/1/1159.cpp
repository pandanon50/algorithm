#include <bits/stdc++.h>

using namespace std;

int N;
int cnt_arr[26];
string answer;

int main(){
    
    cin >> N;
    string buffer;
    for (int i = 0; i < N; i++) {
        cin >> buffer;
        cnt_arr[buffer[0] - 97]++;
    }

    for(int i = 0; i < 26; i++) {
        if(cnt_arr[i] > 4) {
           answer += (i + 97);
        }
    }

    if(answer =="") {
        cout << "PREDAJA" << '\n';
    }else {
        cout << answer << '\n';
    }

    return 0;
}