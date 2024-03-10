#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int park_time[101][3];
int A,B,C = 0;


int parking = 0;

int visit[3] = {-1,-1,-1};

int sum() {
    if(parking == 0) {
        return 0;
    }
    if (parking == 1) {
        return A;
    }else if(parking == 2) {
        return B;
    }else {
        return C;
    }
}

int check(int time) {
  int check_parking = 0;
  for(int i = 0; i < 3; i++) {
    
    if(v[i].first == time) {
      visit[i] = 1;
    }
    
    if(v[i].second == time) {
      visit[i] = 0;
    }
  
    if(visit[i] == 1) {
      check_parking += 1;
    } 
  }
  
  return check_parking;

}

int main() {
  
  cin >> A >> B >> C;
  
  for (int i = 0; i < 3; i++) {
      int start,end = 0;
      cin >> start >> end;
      v.push_back({start,end});
  }

  for (int i = 1; i <= 100; i++) {
    parking = check(i);
    for(int park_idx = 0; park_idx < 3; park_idx++) {
        if (visit[park_idx] == 1) {
          park_time[i][park_idx] = park_time[i - 1][park_idx] + sum();
        }else if(visit[park_idx] == 0) {
          park_time[i][park_idx] = park_time[i - 1][park_idx];
        }
    }
  }

  cout << park_time[100][0] + park_time[100][1] + park_time[100][2] << '\n';

  return 0;
}



// 쉽게 생각 하자..
// cnt 배열 생각
