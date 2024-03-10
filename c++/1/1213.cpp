#include <bits/stdc++.h>

using namespace std;

// 65 ~ 91
int abc[27];
string input;
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int num_type = 0;
    string answer = "I'm Sorry Hansoo";
    // odd -> 1 , even -> 0
    getline(cin,input);
    if(input.length() % 2 != 0) num_type = 1;

    for(int i = 0; i < input.length(); i++) {
        abc[input[i] - 65] += 1;
    }    
    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        if(abc[i] % 2 != 0 && num_type == 0) {
            cout << answer << '\n';
            exit(0);
        }

        if(abc[i] % 2 != 0) {
            cnt++;
        } 
    }
    if(num_type == 1 && cnt > 1) {
        cout << answer << '\n';
        exit(0);
    }
    // 짝수
    if(num_type == 0) {
        answer = "";
        for(int i = 0; i < 26; i++) {
            for (int j = 0; j < abc[i] / 2; j++) {
                answer += char(i + 65);
            }
        }
        string temp = answer;
        reverse(temp.begin(),temp.end());
        cout << answer + temp << '\n';
     
    }else {
        answer = "";
        string checker = "";
        for(int i = 0; i < 26; i++) {
            if(abc[i] != 0) {
                if(abc[i] % 2 != 0) checker = (char)i + 65;
                for (int j = 0; j < abc[i] / 2; j++) {
                    answer += (char)(i + 65);
                }
            }
        }
        string temp = answer;
        reverse(temp.begin(),temp.end());
        cout << answer + checker + temp << '\n';   
    }
    return 0;
}