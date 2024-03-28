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
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int m;
  cin >> m;
  set<int> b;
  rep(i, m) {
    int x;
    cin >> x;
    b.insert(x);
  };

  int x;
  cin >> x;

  vector<int> dp(x+1);
  dp[0] = 1;

  for (int i = 1; i < x+1; i++) {
    if (b.count(i)) {
      continue;
    }

    rep(j, n) {
      if (i < a[j]) continue;

      if (dp[i-a[j]]) { 
        dp[i] = 1; 
        break;
      }
    }
  }

  if (dp[x]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}