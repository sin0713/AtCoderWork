#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<char, int>;

int main() {
  string s, t;
  cin >> s >> t;

  auto ranlengs = [&] (string s) -> vector<P> {
    vector<P> res;
    int n = s.size();
    rep(i, n) {
      if (res.empty()) {
        res.emplace_back(s[i], 1);
        continue;
      }

      auto& last = res.back();
      if (last.first == s[i]) {
        last.second++;
      } else {
        res.emplace_back(s[i], 1);
      }
    }

    return res;
  };

  vector<P> sranl = ranlengs(s);
  vector<P> tranl = ranlengs(t);

  if (sranl.size() != tranl.size()) {
    cout << "No" << endl;
    return 0;
  }

  bool ok = true;
  rep(i, sranl.size()) {
    auto [sc, sv] = sranl[i];
    auto [tc, tv] = tranl[i];

    if (sc != tc) {
      ok = false;
      break;
    }

    if (sv == tv) continue;

    if (sv > tv || (sv < tv && sv < 2)) {
      ok = false;
      break;
    }
  }

  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}