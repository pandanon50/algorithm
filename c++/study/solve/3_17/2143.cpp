// BOJ 2143 두 배열의 합
// https://www.acmicpc.net/problem/2143
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX_NM = 1010;
int A[MAX_NM];
int B[MAX_NM];
vector<ll> va;
vector<ll> vb;

int N, M, lo, hi, mid;
ll T, cnt;

int main() {
  cin >> T;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  cin >> M;
  for (int i = 1; i <= M; i++) {
    cin >> B[i];
  }

  for (int i = 1; i <= N; i++) {
    ll sum = 0;
    for (int j = i; j <= N; j++) {
      sum += A[j];
      va.push_back(sum);
    }
  }
  for (int i = 1; i <= M; i++) {
    ll sum = 0;
    for (int j = i; j <= M; j++) {
      sum += B[j];
      vb.push_back(sum);
    }
  }

  sort(va.begin(), va.end());
  for (int i = 0; i < vb.size(); i++) {
    ll value = T - vb[i];
    auto up = upper_bound(va.begin(), va.end(), value);
    auto low = lower_bound(va.begin(), va.end(), value);
    cnt += up - low;
  }
  cout << cnt << '\n';

  return 0;
}

// A배열, B배열 각각 누적합을 N^2으로 계산
// 둘중하나의 배열을 sort하고 T - 배열의 값을 순차적으로 N,M번 돌리고 그 뺀값을
// 솔팅한 배열에서 이분탐색으로 search 중복된 배열을 생각못해서 정답맞추는데
// 오래걸림 N^2 * Mlog(M) * log(M)