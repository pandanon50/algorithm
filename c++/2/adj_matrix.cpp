#include <bits/stdc++.h>

using namespace std;


int matrix[10][10];
int visit[10];


void go(int v) {

   if(visit[v] == 0){
       visit[v] = 1;
       cout << "visit : " << v << "\n";
       for(int i = 0; i < 10; i++) {
           if(visit[i]) continue;
           if(matrix[v][i]) {
               go(i);
           }
       }
       
   }
   return; 
}

int main() {
   
   matrix[2][1] = 1;
   matrix[3][1] = 1;
   matrix[4][3] = 1;
   matrix[1][2] = 1;
   matrix[1][3] = 1;
   matrix[3][4] = 1;


   for(int i = 0; i < 10; i++) {
       for(int j = 0; j< 10;j++) {
           if(matrix[i][j] && visit[i] == 0) {
                go(i);
           }

       }
   }
}