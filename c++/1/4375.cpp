#include <bits/stdc++.h>

using namespace std;

// typedef long long ll;
// ll arr[10000];

// map<ll,ll> mp1;  


// int main() {
//     arr[1] = 1;
//     for (int i = 1; i <= 10000; i++) {
//         ll num1 = 1;
//         ll cnt = 1;
//         if(i % 2 == 0 || i % 5 == 0) continue;

//         while(1) {
//             if(num1 % i == 0) {
//                 cout << "num1 ->" << num1 << " " << i << " " << cnt << " " << num1 / i <<  '\n'; 
//                 arr[i] = cnt;
//                 if(num1 / i > 10000) break;
//                 else {
//                     mp1[num1 / i] = cnt;
//                     break;
//                 }
//             }else {
//                 num1 = (num1 * 10) + 1;
//                 num1 %= i;
//                 cnt++;
//             }
           
//         }
//     }
// }
typedef long long ll;
int n;
int main() {
    while(scanf("%d", &n) != EOF) {
        ll cnt = 1, ret = 1;
        while(true) {
            if(cnt % n == 0) {
                printf("%lld\n",ret);
                break;
            }else {
                cnt = (cnt * 10) + 1;
                cnt %= n;
                ret++;
            }
        }
    }
    return 0;
}
