#include <bits/stdc++.h>

using namespace std;

int mo,mo_con,ja_con,valid = 0;
char same;
string input;

int check_ja(char a) {
    if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
        return 1;
    }else {
        return 0;
    }
}

int main() {

    while(1) {
        mo = 0; mo_con = 0; ja_con = 0; valid = 0;
        same = '!';
        cin >> input;
        if(input == "end") {
            exit(0);
        }

        for(int i = 0; i < input.length(); i++) {
            // 연속 글자 확인
            if(same == input[i]) {
                if(same != 'e' && same != 'o') {
                    valid = -1;
                    break;
                } 
            }else {
                same = input[i];
            }
            // 자음 카운트
            if(check_ja(input[i]) == 0) {
                ja_con++;
                if(ja_con == 3) {
                    valid = -1;
                    break;
                }
                mo_con = 0;
            }else { // 모음 카운트
                mo_con++;
                mo = 1;
                if(mo_con == 3) {
                    valid = -1;
                    break;
                }
                ja_con = 0;
            }
        }
        if(mo == 0) valid = -1;
        
        if(valid == -1) cout << "<" << input << ">" << " is not acceptable." << '\n'; 
        else cout << "<" << input << ">" << " is acceptable." << '\n';
    }
}