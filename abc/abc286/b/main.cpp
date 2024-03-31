#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  const string nya = "nya";
  const int m = nya.size();
  const int l = 2;

  int n;
  string s;
  cin >> n >> s;

  vector<int> p;
  rep(i, n - 1) {
    if (s[i] == 'n' && s[i + 1] == 'a') {
      p.push_back(i);
    }
  }

  for (int i = 0; i < p.size(); i++) {
    int start = p[i] + i; 
    s.replace(start, l, nya);
  }

  cout << s << endl;
  return 0;
}