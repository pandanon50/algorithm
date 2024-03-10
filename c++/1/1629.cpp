#include <bits/stdc++.h>

using namespace std; 

// typedef long long ll;

// map<ll,ll> mp;
// vector <ll> v;
// int main() {
//     ios_base::sync_with_stdio(false);
// 	cin.tie(NULL); cout.tie(NULL);
//     ll a,b,c = 0;

//     cin >> a >> b >> c;
    
//     if (a == 1 || a == 0) {
//         cout << a << '\n';
//         exit(0);
//     }

//     ll sq = 1;
//     ll cnt = 0;
//     for(ll i = 1; i <= b; i++) {
//         sq *= a;
//         if(c > sq) {
//             cnt++;
//             continue;
//         }
//         if(mp[sq % 10] != 0) {
//             if((b - cnt) % v.size() == 0) {
//                 cout << v[v.size() - 1] << '\n';
//             }else {
//                 cout << v[(b - cnt) % v.size()] << '\n';
//             }
//             exit(0);
//         }else {
//             mp[sq % 10] = sq % c;
//             v.push_back(sq % c); 
//         }
//     }
//     return 0;
// }


typedef long long ll;
ll a,b,c;
ll moding(ll a, ll b) {
    if(b == 1) return a % c;
    
    ll ret = moding(a,b/2);
    ret = (ret * ret) % c;
    if(b % 2) ret = (ret * a)% c;
    return ret;
   
} 

int main() {
    
    cin >> a >> b >> c;

    ll k = moding(a,b);
    cout << k << '\n';
    return 0;
}