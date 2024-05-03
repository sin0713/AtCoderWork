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
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  
  vector<int> s;
  rep(i, n) { 
    s.push_back(a[i]);

    while(s.size() >= 2) {
      int m = s.size();
      if (s[m-1] != s[m-2]) { break; } 

      s.pop_back();
      s.back()++;
    }
  }

  cout << s.size() << endl;
  return 0;
}