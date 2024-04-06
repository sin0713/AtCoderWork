#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<ll, int>;

ll count(ll p, ll n) {
  if (p == 0) return 0;

  p /= n;
  return p + count(p, n);
}

int main() {
  ll k;
  cin >> k;

  // kを素因数分解
  vector<P> ps;
  {
    ll x = k;
    for (ll i = 2; i*i <= k; i++) {
      // 割れない（余りが出る）なら処理しない
      if (x%i) continue;

      int cnt = 0;
      while(x%i == 0) {
        cnt++;
        x /= i;
      }
      ps.emplace_back(i, cnt);
    }
    // xは素数
    if (x != 1) ps.emplace_back(x, 1);
  }

  auto isOk = [&] (ll x) -> bool {
    for (auto [p, cnt] : ps) {
      ll res = count(x, p);
      if (res < cnt) return false;
    }

    return true;
  };

  ll wa = 0, ac = k;
  while(ac - wa > 1) {
    ll wj = (ac+wa) / 2;
    if (isOk(wj)) ac = wj; else wa = wj;
  }

  cout << ac << endl;
  return 0;
}