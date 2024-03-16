#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

const string atcoder_str = "atcoder";
bool is_atcoder(char c) {
  rep(i, atcoder_str.size()) {
    if (c == atcoder_str[i]) {
      return true;
    }
  }
  return false;
} 

bool solve() {
  string s, t;
  cin >> s >> t;

  int n = s.size();
  int m = t.size();
  map<char, int> s_map;
  map<char, int> t_map;
  rep(i, n) { s_map[s[i]]++; }
  rep(i, m) { t_map[t[i]]++; }

  const char AT_MARK= '@';
  for (auto [k, v] : s_map) {
    if (k == AT_MARK) { continue; }

    rep(i, v) {
      if (t_map.count(k)) {
        t_map[k]--;
        if (t_map[k] == 0) t_map.erase(k);
        continue;
      } 

      if (t_map.count(AT_MARK) && is_atcoder(k)) {
        t_map[AT_MARK]--;
        if (t_map[AT_MARK] == 0) t_map.erase(AT_MARK);
        continue;
      }

      return false;
    }
  }

  if (!s_map.count(AT_MARK)) return true; 

  int s_atmark_cnt = s_map[AT_MARK];
  int cnt = 0;
  bool ok = true;
  for (auto [tk, tv] : t_map) {
    if (!is_atcoder(tk) && tk != AT_MARK) {
      ok = false;
      break;
    }
    cnt += tv;
  }
  if (!ok) {
    return false;
  }

  return s_atmark_cnt == cnt;
};

int main() {
  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}