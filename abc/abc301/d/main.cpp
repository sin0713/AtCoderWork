#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() 
{
  string s;
  ll n;
  cin >> s >> n;

  int m = s.size();

  auto get_decimal = [&](string s) -> ll
  {
    ll x = 0;
    for (char &c : s)
      x = x * 2 + (c - '0');
    return x;
  };

  auto ok = [&](string s) -> bool {
    rep(i, m) {
      if (s[i] == '?') {
        s[i] = '0';
      }
    }

    return get_decimal(s) <= n;
  };

  if (!ok(s)) {
    cout << -1 << endl;
    return 0;
  }

  rep(i, m) {
    if (s[i] == '?') {
      s[i] = '1';
      if (!ok(s)) s[i] = '0';
    }
  }

  cout << get_decimal(s) << endl;
  return 0;
}