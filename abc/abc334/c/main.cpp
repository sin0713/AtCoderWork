#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e18
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(k);
  rep(i, k) {
    cin >> a[i]; 
    a[i]--;
  }

  vector<int> cnt(n, 2);
  rep(i, k) { cnt[a[i]]--; }

  vector<int> d;
  rep(i, n) {
    rep(j, cnt[i]) d.push_back(i);
  }

  n = d.size();
  int ans = 0;
  if (n % 2 == 0) {
    rep(j, n / 2) {
      ans += d[j*2+1] - d[j*2];
    }
  } else {
    int now = 0;
    for (int i = 2; i < n; i+=2) {
      now += d[i] - d[i-1];
    }
    ans = now;
    for (int i = 2; i < n; i+=2) {
      now -= d[i] - d[i-1];
      now += d[i-1] - d[i-2];
      ans = min(ans, now);
    }
  }

  cout << ans << endl;
  return 0;
}