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
	int n;
	cin >> n;

	vector<int> a(n);
	rep(i, n) cin >> a[i];

	const int m = 1e6+1;
  vector<int> s(m);
	iota(s.begin(), s.end(), 0);

	for(int d = 1000; d >= 2; d--){
		for (int k = d*d; k < m; k+=d*d) {
			if (s[k] % (d*d) == 0) {
				s[k] /= d*d;
			}
		}
	}

	vector<ll> cnt(m);
	rep(i, n) {
		cnt[s[a[i]]]++;
	}

  ll ans = 0;
	rep(i, m) {
		if (i == 0 && cnt[i] != 0) {
			ans += cnt[0] * (cnt[0] - 1) / 2 + (n - cnt[0]) * cnt[0];
		} else {
			if (cnt[i] <= 1) continue;
			ans += (cnt[i] * (cnt[i]-1)) / 2;
		}
	}

	cout << ans << endl;
  return 0;
}