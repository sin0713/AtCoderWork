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
  }

  vector<int> b;
  rep(i, n-1) {
    bool is_bigger = a[i] < a[i+1];
    int roop_cnt = abs(a[i] - a[i+1]) - 1;
    int num = a[i];
    b.push_back(a[i]);
    rep(j, roop_cnt) {
      if (is_bigger) num++; else num--;
      b.push_back(num);
    }
  }
  b.push_back(a[n-1]);

  int m = b.size();
  rep(i, m) {
    cout << b[i] << " ";
  }
  cout << endl;
  return 0;
}