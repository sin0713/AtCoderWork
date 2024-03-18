#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

vector<ll> isPrime;

vector<int> sieveOfEratosthenes(int n)
{
  isPrime.resize(n, true);
  isPrime[0] = false;
  isPrime[1] = false;
  vector<int> res;
  for (int i = 2; i <= n; i++)
  {
    if (isPrime[i])
    {
      res.push_back(i);
      for (int j = i * 2; j <= n; j += i)
      {
        isPrime[j] = false;
      }
    }
  }
  return res;
}

int main()
{
  ll n;
  cin >> n;
  vector<int> primes = sieveOfEratosthenes(1e6);

  int m = primes.size();
  int ans = 0;
  for (int ai = 0; ai < m; ai++)
  {
    ll a = primes[ai];
    if (a * a * a * a * a > n)
      break;
    for (int bi = ai + 1; bi < m; bi++) {
      ll b = primes[bi];
      if (a*a*b*b*b > n) break;
      for (int ci = bi+1; ci < m; ci++) {
        ll c = primes[ci];
        if (a*a*b*c*c > n) break;
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}