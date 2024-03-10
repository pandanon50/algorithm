#include <bits/stdc++.h>

using namespace std;

int cx,J,M,N,fruit,result;

void move(int current, int d) {
    int check = -1;
    
    if(d == 1) {
        for(int i = current; i <= N; i++) {
            for(int j = i; j < i + M; j++) {
                if(j == fruit) {
                  check = i - current;
                  cx = i;
                  break;  
                }
            }
            if(check != -1) {
                result += check;
                break;
            }
        }
    }else {
       for(int i = current; i > 0; i--) {
           for (int j = i; j < i + M; j++) {
                if(j == fruit) {
                  check = current - i;
                  cx = i;
                  break;  
                }
           }
           if(check != -1) {
                result += check;
                break;
            }
       }
    }
}

int main() {
    cin >> N >> M;
    cin >> J;
    cx = 1;
    while(J--) {
        cin >> fruit;
        if(cx != fruit) {
            if(cx > fruit) {
                move(cx,-1);
            }else {
                move(cx,1);
            }
        }
    }
    cout << result << '\n';
    return 0;
}

// bfs 써야하는줄..