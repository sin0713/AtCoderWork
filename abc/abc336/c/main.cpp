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
  ll n;
  cin >> n;
  n--;
   
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  
  int m = 5;
  string res = ""; 
  while(n != 0) {
    res += '0' + (n % 5 * 2);
    n /= m;
  }

  reverse(res.begin(), res.end());
  cout << res << endl;
  return 0;
}