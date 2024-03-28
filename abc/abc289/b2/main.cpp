#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

const int re = 101;

int main() {
  int n, m;
  cin >> n >> m;
  set<int> re;
  rep(i, m) {
    int a;
    cin >> a;
    re.insert(a);
  };

  vector<int> stack;
  for (int i = 1; i < n+1; i++) {
    if (re.count(i)) {
      stack.push_back(i);
      continue;
    }

    cout << i << ' ';
    while(!stack.empty()) {
      int top = stack.back(); stack.pop_back();
      cout << top << ' ';
    }
  }

  cout << endl;
  return 0;
}