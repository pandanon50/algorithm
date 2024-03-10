#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[10]; // 1 ~ 9
    int tall_sum = 0;
    int temp_tall = 0;
    
    for (int i = 1; i <= 9; i++) {
        cin >> arr[i];
        tall_sum += arr[i];
    }
    
    sort(arr + 1,arr + 10);
    int lie_i = -1;
    int lie_j = -1;
    for (int i = 1; i < 9; i++) {
        temp_tall = tall_sum;
        for(int j = i + 1; j <= 9; j++) {
            temp_tall -= (arr[i] + arr[j]);
            if(temp_tall == 100) {
                lie_i = i;
                lie_j = j;
              
                break;
            }else {
               temp_tall = tall_sum;
            }
        }
        if(lie_i != -1) {
            break;
        }
    }
    
    for (int i = 1; i <= 9; i++) {
       if(i != lie_i && i != lie_j) {
           cout << arr[i] << '\n';
       }
       
    }
    return 0;
}