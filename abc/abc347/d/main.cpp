#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

const int M = 60;

ll pc(ll x) { return __builtin_popcountll(x); }

ll tos(vector<int>& x) {
  ll res = 0;
  rep(i, M) res |= (ll)x[i] << i;
  return res;
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  ll one = pc(c);
  ll zero = M - one;

  ll d = a + b - one;
  if (d < 0 || d % 2 != 0) {
    cout << -1 << endl;
    return 0;
  }

  d /= 2;
  a -= d;
  b -= d;
  if (d > zero || a < 0 || b < 0) {
    cout << -1 << endl;
    return 0;
  }

  vector<int> i0, i1;
  rep(i, M) {
    ll bit = 1;
    if (c&(bit<<i))
      i1.push_back(i);
    else
      i0.push_back(i);
  }

  vector<int> x(M), y(M);
  // cの0かつx,yで1を使用する場所に1を立てる
  rep(j, d) {
    int i = i0[j];
    x[i] = y[i] = 1;
  }

  // cの1かつx,yで1を使用する場所に1を立てる
  rep(j, one) {
    int i = i1[j];
    if (j < a)
      x[i] = 1;
    else
      y[i] = 1;
  }

  cout << tos(x) << ' ' << tos(y) << endl;
  ;
  return 0;
}