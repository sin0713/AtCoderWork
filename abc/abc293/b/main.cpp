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

  vector<bool> called(n, false);
  rep(i, n) {
    int a;
    cin >> a;
    a--;

    if (called[i]) continue; 
    called[a] = true;
  }

  vector<int> ans;
  rep(i, n) {
    if (!called[i]) ans.push_back(i);
  }

  int k = ans.size();
  cout << k << endl;
  rep(i, k) cout << ans[i] + 1 << ' ';
  cout << endl;
  return 0;
}