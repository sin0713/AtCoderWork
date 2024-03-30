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

  ll ans = 0;
  set<string> st;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      string a = "";
      for (int k = i; k < j+1; k++) {
        a += s[k];
      }
      st.insert(a);
    }
  }
  cout << st.size() << endl;
  return 0;
}