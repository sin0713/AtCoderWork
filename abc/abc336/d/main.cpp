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

int main()
{
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  a.push_back(0);
  a.insert(a.begin(), 0);
  n += 2;

  for (int i = 1; i < n; i++) {
    a[i] = min(a[i-1]+1, a[i]);
  }
  for (int i = n-2; i >= 0; i--) {
    a[i] = min(a[i+1]+1, a[i]);
  }

  int ans = 0;
  rep(i, n) {
    ans = max(a[i], ans);
  }

  cout << ans << endl;
  return 0;
}