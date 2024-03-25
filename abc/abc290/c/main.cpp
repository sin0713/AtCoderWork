#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  set<int> st;
  rep(i, n) st.insert(a[i]);

  int mex_a = 0;
  while(st.count(mex_a)) mex_a++;

  int ans = min(k, mex_a);
  cout << ans << endl;
  return 0;
}