#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int m = 10;
  vector<vector<int>> cs(m, vector<int>(n+1));

  rep(i, n) {
    rep(j, m) {
      int si = s[i] - '0';
      if (si == j) {
        cs[j][i+1] = (cs[j][i] + 1) % 2; 
      } else {
        cs[j][i+1] = (cs[j][i]) % 2; 
      }
    }
  }

  map<vector<int>, int> mp;
  rep(i, n+1) {
    vector<int> res;
    rep(j, m) {
      res.push_back(cs[j][i]);
    }
    mp[res]++;
  }

  ll sum = 0;
  for (auto& [vec, cnt] : mp) {
    if (cnt <= 1) continue;

    sum += (ll)cnt * (cnt-1) / 2;
  }

  cout << sum << endl;
  return 0;
}