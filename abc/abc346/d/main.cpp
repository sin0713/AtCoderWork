#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> c(n);
  rep(i, n) cin >> c[i];

  vector<ll> s0(n+1);
  vector<ll> s1(n+1);

  rep(i, n) {
    s0[i+1] += s0[i];  
    s1[i+1] += s1[i];  

    if (i % 2 == 0) {
      // 偶数番目の文字
      if (s[i] == '0') {
        s1[i+1] += c[i];
      } else {
        s0[i+1] += c[i];
      }
      continue;
    }

    // 奇数番目の文字
    if (s[i] == '0') {
      s0[i+1] += c[i];
    } else {
      s1[i+1] += c[i];
    }
  }

  const ll INF = 1e15;
  ll ans = INF;
  for (int i = 1; i < n; i++) {
    ans = min(ans, s1[i]+(s0[n] - s0[i]));
    ans = min(ans, s0[i]+(s1[n] - s1[i]));
  }

  cout << ans << endl;
  return 0;
}