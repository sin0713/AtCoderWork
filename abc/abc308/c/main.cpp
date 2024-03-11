#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> B(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    A[i] = a;
    B[i] = a+b;
  }

  vector<int> ids(n);
  rep(i, n) ids[i] = i;

  stable_sort(ids.begin(), ids.end(), [&](int i, int j){
    return (ll)A[i] * B[j] > (ll)A[j] * B[i];
  });

  rep(i, n) {
    cout << ids[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}