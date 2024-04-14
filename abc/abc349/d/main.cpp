#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<ll, ll>;

int main() {
  ll L, R;
  cin >> L >> R;

  vector<P> ans; 
  auto f = [&](auto f , ll l, ll r) -> void {
    if (l >= L && r <= R) {
      ans.emplace_back(l, r);
      return;
    }

    ll mid = (l+r)>>1;
    if (L<mid) f(f, l, mid);
    if (mid<R) f(f, mid, r);
  };

  f(f, 0, 1ll<<60);

  int s = ans.size();
  cout << s << endl;
  for (auto [l, r] : ans) {
    cout << l << ' ' << r << '\n';
  }
  return 0;
}