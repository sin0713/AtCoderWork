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

  map<char, int> mp;
  rep(i, n) {
    mp[s[i]]++;
  }

  map<int, int> kind_mp;
  for (auto [c, cnt] : mp) {
    kind_mp[cnt]++;
  }

  for (auto [cnt, kind] : kind_mp) {
    if (kind != 2) {
      cout << "No"  << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}