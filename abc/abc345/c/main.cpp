#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

ll c2(ll n) {
  return n * (n-1) / 2;
}

int main()
{
  string s;
  cin >> s;

  int n = s.size();
  map<char, int> mp;
  rep(i, n) { mp[s[i]]++; }

  ll same = 0;
  for (auto [k, v] : mp) {
    ll res = c2(v);
    same += res;
  }

  ll whole = c2(n);
  ll ans = whole - same;
  if (same) ans++;
  cout << ans << endl;
  return 0;
}