#include <bits/stdc++.h>

using namespace std;

int n,k;
int psum[100001];
int main() {
   cin >> n >> k;
   int num,answer = 0;
   for(int i = 1; i <= n; i++) {
      cin >> num;
      psum[i] = psum[i - 1] + num; 
   }
   
   for(int i = 1; i <= n - k + 1; i++) {
       if(i == 1) answer = psum[k];
       else {
           if(answer < psum[k - 1 + i] - psum[i - 1]) {
              answer = psum[k - 1 + i] - psum[i - 1];
           }
       }
   }
   cout << answer << '\n';

   return 0;
}


// #include<bits/stdc++.h> 
// using namespace std;  
// typedef long long ll;  
// int n, k, temp, psum[100001], ret = -1000000; 
// int main(){
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);cout.tie(NULL);
// 	cin >> n >> k; 
// 	for(int i = 1; i <= n; i++){
// 		cin >> temp; psum[i] = psum[i - 1] + temp; 
// 	} 
// 	for(int i = k; i <= n; i++){
// 		ret = max(ret, psum[i] - psum[i - k]);
// 	}
// 	cout << ret << "\n";
//     return 0;
// }