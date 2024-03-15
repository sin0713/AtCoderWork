#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main()
{
  string n;
  cin >> n;

  for (int i = 3; i < n.size(); i++) {
    n[i] = '0';
  }

  cout << n << endl;;
  return 0;
}