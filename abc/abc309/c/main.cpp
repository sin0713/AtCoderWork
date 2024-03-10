#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n, k;
  cin >> n >> k;

  vector<P> med(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    med[i] = {a, b};
  }

  auto f = [&] (ll x) -> bool {
    ll sum = 0;
    rep(i, n) {
      if (x <= med[i].first) sum += med[i].second;
    }

    return sum <= k;
  };

  ll wa = 0; 
  ll ac = 1001001001;
  while(ac - wa > 1) {
    ll x = (ac + wa) / 2;
    if (f(x)) ac = x; else wa = x;
  }

  cout << ac << endl;
  return 0;
}