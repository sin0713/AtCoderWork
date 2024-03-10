#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main()
{
  int n;
  cin >> n;

  vector<string> s(n);
  rep(i, n) cin >> s[i];

  unordered_map<string, int> mp;

  rep(i, n) {
    if (mp.count(s[i])) continue;
    reverse(s[i].begin(), s[i].end());
    if (mp.count(s[i])) continue;

    mp[s[i]]++;
  }

  cout << mp.size() << endl;
  return 0;
}