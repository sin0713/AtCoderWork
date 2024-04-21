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
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  } 

  vector<int> pos(n);
  rep(i, n) {
    pos[a[i]] = i;
  }

  vector<P> ans; 
  rep(i, n) {
    if (a[i] != i) {
      P p = pair(i+1, pos[i]+1);
      ans.push_back(p);
      swap(pos[i], pos[a[i]]);
      swap(a[p.first-1], a[p.second-1]);
    }
  }

  cout << ans.size() << endl;
  for (auto [a, b] : ans) {
    printf("%d %d\n", a, b);
  }

  return 0;
}