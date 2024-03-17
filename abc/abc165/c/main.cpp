#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

struct Query
{
  int a, b, c, d;

  Query(){};
  Query(int a_, int b_, int c_, int d_) : a(a_), b(b_), c(c_), d(d_){};
};


int main()
{
  int n, m, q;
  cin >> n >> m >> q;

  vector<Query> q_list;
  rep(i, q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--;
    q_list.push_back(Query(a, b, c, d));
  }

  ll ans = 0;
  auto dfs = [&] (auto dfs, vector<int> &a) -> void {
    if (a.size() == n) {
      ll sum = 0;
      rep(i, q) {
        Query query = q_list[i];
        if (a[query.b] - a[query.a] == query.c) {
          sum += query.d;
        }
        ans = max(ans, sum);
      }

      return;
    }

    int prev_last = (a.empty()) ? 1 : a.back();
    for (int i = prev_last; i <= m; i++) {
      a.push_back(i);
      dfs(dfs, a);
      a.pop_back();
    }
  };

  vector<int> a;
  dfs(dfs, a);
  cout << ans << endl;
  return 0;
}