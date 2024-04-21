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

  unordered_map<string, int> mp;
  rep(i, n) {
    string s;
    cin >> s;

    if (mp.count(s)) {
      cout << s << '(' << mp[s] << ')' << '\n';
      mp[s]++;
      continue;
    } 

    cout << s << endl;
    mp[s]++;
  }
  return 0;
}