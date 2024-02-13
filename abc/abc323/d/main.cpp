#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;

  map<ll, ll> mp;
  rep(i, n) {
    int s;
    int c;
    cin >> s >> c;
    mp[s] = c;
  }

  int ans = 0;
  while(mp.size()) {
    auto [s, c] = *mp.begin();
    mp.erase(mp.begin());

    // スライム数を合成できるだけ合成 = /２
    if (c % 2 == 1) { ans++; }
    int merge_num = c / 2;
    if (merge_num) {
      mp[s * 2] += merge_num;
    }
  }

  cout << ans << endl;
  
  return 0;
}