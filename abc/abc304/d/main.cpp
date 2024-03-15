#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() { 
  int w, h, n;
  cin >> w >> h >> n;

  vector<int> p(n), q(n);
  rep(i, n) {
    cin >> p[i] >> q[i];
  }

  int A, B;
  cin >> A;
  vector<int> a(A);
  rep(i, A) cin >> a[i];
  cin >> B;
  vector<int> b(B);
  rep(i, B) cin >> b[i];

  map<P, int> mp;
  rep(i, n) {
    int x = lower_bound(a.begin(), a.end(), p[i]) - a.begin();
    int y = lower_bound(b.begin(), b.end(), q[i]) - b.begin();
    mp[pair(x, y)]++;
  }

  const int INF = 1e6;
  int mx = 0;
  int mn = INF;
  for (auto& [k, v] : mp) {
    mx = max(mx, v);
    mn = min(mn, v);
  }
  mn = (mp.size() < (A+1)*(B+1)) ? 0 : mn;

  cout << mn  << " " << mx << endl;
  return 0;
}