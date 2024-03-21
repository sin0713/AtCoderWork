#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;

  unordered_map<int, int> mp;
  rep(i, n) {
    int socks;
    cin >> socks;

    mp[socks]++;
  }

  ll sum = 0;
  for (auto &[k, v] : mp) {
    sum += (ll) v / 2;
  }
  cout << sum << endl;
  return 0;
}