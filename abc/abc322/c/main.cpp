#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  int M;
  cin >> N >> M;
  vector<int> A(M);
  rep(i, M) cin >> A[i];

  rep(i, N) {
    auto iterator = lower_bound(A.begin(),A.end(), i+1);
    cout << *iterator - (i + 1) << endl;
  }

  return 0;
}