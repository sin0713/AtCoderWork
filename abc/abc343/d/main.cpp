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
  int n, t;
  cin >> n >> t;

  vector<ll> score(n);
  unordered_map<ll, int> mp;
  mp.emplace(0, n);
  rep(i, t) {
    int a, b;
    cin >> a >> b;
    a--;

    mp[score[a]]--;
    if (mp[score[a]] == 0) {
      mp.erase(score[a]);
    }

    score[a] += b;
    if (mp.count(score[a])) {
      mp[score[a]]++;
    } else {
      mp.emplace(score[a], 1);
    }

    cout << mp.size() << '\n';
  }
  return 0;
}