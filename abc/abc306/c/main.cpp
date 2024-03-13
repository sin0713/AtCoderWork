#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

struct Info
{
  int index;
  int cnt;
  int value;

  void update(int _i)
  {
    index = _i;
    cnt++;
  }

  bool shouldUpdate()
  {
    return cnt < 2;
  }

  Info() {};
  Info(int index_, int cnt_, int value_):  index(index_), cnt(cnt_), value(value_) {};
};

int main() {
  int n;
  cin >> n;

  vector<Info> mp(n);
  rep(i, n) mp[i] = {0, 0, i};

  rep(i, n * 3)
  {
    int a;
    cin >> a;
    a--;

    if (!mp[a].shouldUpdate())
      continue;

    mp[a].update(i);
  }

  sort(mp.begin(), mp.end(), [](Info left, Info right)
       { return left.index < right.index; });

  rep(i, n)
  {
    cout << mp[i].value + 1 << " ";
  }
  cout << endl;

  return 0;
}