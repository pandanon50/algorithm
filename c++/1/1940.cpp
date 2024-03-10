#include <bits/stdc++.h>

using namespace std;

int N,M,k,cnt,check;
vector <int> com;
int arr[15002];

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> M;
    
    for(int i = 0; i < N; i++) {
        cin >> k;
        arr[i] = k;
    }
    if(M > 200000) {
        // 문제를 잘 보면 유추가능!
        cout << 0 << "\n";
    }else {
        for(int i = 0; i < N; i++) {
          for (int j = i + 1; j < N; j++) {
                check = arr[i] + arr[j];
                if(check == M) {
                    cnt++;
                }
           }
        }
        cout << cnt << "\n";
    }
}