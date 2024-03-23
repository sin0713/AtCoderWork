#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = unsigned long long;
using P = pair<int, int>;

int main() {
  int n;
  ll k;
  cin >> n >> k;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  set<ll> st;
  rep(i, n) {
    if (a[i] <= k) {
      st.insert(a[i]);
    }
  }

  ll sum = k * (k+1) / 2;
  for (auto l : st) {
    sum -= l;
  }
  cout << sum << endl;
  return 0;
}