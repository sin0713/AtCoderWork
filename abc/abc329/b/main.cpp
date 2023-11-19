#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> A(N); 
  rep(i, N) cin >> A[i];

  sort(A.rbegin(), A.rend());
  int max = A[0];
  int res = -1;
  rep(i, N) {
    if (A[i] < max) {
      res = A[i];
      break;
    }
  }

  cout << res << endl;


  return 0;
}