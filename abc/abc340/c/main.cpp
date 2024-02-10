#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define inf (1 << 30)

unordered_map<long, long> memo;
long long f(long long x)
{
  if (x == 1)
    return 0;
  if (memo.count(x))
    return memo[x];

  return memo[x] = f(x / 2) + f(x - x / 2) + x;
}

int main()
{
  long long n;
  cin >> n;

  cout << f(n) << endl;
  return 0;
}