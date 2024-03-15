#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n, d;
  cin >> n >> d;

  vector<P> xy(n);
  rep(i, n)
  {
    int x, y;
    cin >> x >> y;
    xy[i] = {x, y};
  }

  auto near = [&](P& p1, P& p2) -> bool {
    int dx = abs(p1.first - p2.first);
    int dy = abs(p1.second - p2.second);
    return dx * dx + dy * dy <= d * d;
  };
  
  vector<bool> visited(n);
  auto f = [&] (auto f, int v) -> void {
    visited[v] = true;

    rep(i, n) {
      if (visited[i]) continue;
      if (near(xy[v], xy[i])) f(f, i);
    }
  };

  f(f, 0);

  rep(i, n) {
    if (visited[i]) cout << "Yes" << '\n';
    else cout << "No" << '\n';
  }
  return 0;
}