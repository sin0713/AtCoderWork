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

  vector<int> g(n);
  rep(i, n) {
    int to; 
    cin >> to;
    to--;
    g[i] = to;
  }

  int start = -1;
  vector<int> ans;
  auto f = [&] (auto f, vector<int>& d, int v) {
    if (d[v] > 0) {
      return v;
    }

    d[v]++;
    ans.push_back(v);
    return f(f, d, g[v]);
  };

  vector<int> d(n);
  int v = f(f, d, 0);
  int s_index = find(ans.begin(), ans.end(), v) - ans.begin();

  int size = ans.size() - s_index;
  cout << size << endl;
  for (int i = s_index; i < ans.size(); i++) {
    cout << ++ans[i] << " ";
  }
  cout << endl;
  return 0;
}
