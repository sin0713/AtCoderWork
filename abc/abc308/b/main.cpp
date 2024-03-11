#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> c(n);
  rep(i, n)
  {
    cin >> c[i];
  }

  vector<string> d(m);
  rep(i, m)
  {
    cin >> d[i];
  }

  vector<int> p(m + 1);
  rep(i, m + 1)
  {
    cin >> p[i];
  }

  unordered_map<string, int> mp;
  rep(i, m) {
    mp[d[i]] = p[i+1];
  }

  int sum = 0;
  rep(i, n) {
    if (mp.count(c[i]))
      sum += mp[c[i]];
    else
      sum += p[0];
  }

  cout << sum << endl;
  return 0;
}