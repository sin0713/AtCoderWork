#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int a = 0010011;

int main()
{
  int n;
  cin >> n;

  int wa = 1;
  int ac = n;
  while (ac - wa > 1)
  {
    int x = (ac + wa) / 2;
    int si;
    cout << "? " << x << '\n';
    cin >> si;

    if (si == 0) wa = x; else ac = x;
  }

  cout << "! " << wa << endl;
  return 0;
}