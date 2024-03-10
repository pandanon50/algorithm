#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 128;

int N;
int matrix[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];


int check(int n, int sy, int sx) {
    
    int cnt = matrix[sy][sx];
    int check = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cnt != matrix[sy+ i][sx + j]) {
                check = 0;
                break;
            }
        }
        if(check == 0) {
            break;
        }
    }
    if(check == 0) {
        return -1;
    }else {
        return cnt;
    }
}

string divide(int n, int start_y, int start_x) {
    

    int checking = check(n,start_y,start_x);

    if(checking != -1) {
        if(checking == 0) return "0";
        else return "1";
    }
    string str = "(";

    if(n == 2) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                if(matrix[start_y + i][start_x + j]) str += "1";
                else str += "0";
            }
        }
        str += ")";

        return str;
    }
    
    int divide_N = n / 2;
    
    str += divide(divide_N, start_y, start_x);
    str += divide(divide_N, start_y, start_x + divide_N);
    str += divide(divide_N, start_y + divide_N , start_x);
    str += divide(divide_N, start_y + divide_N, start_x + divide_N);
    return str + ")";
}

int main() {

    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%1d",&matrix[i][j]);
        }
    }

    string str = "";
    str = divide(N,0,0);
    cout << str << '\n';

}