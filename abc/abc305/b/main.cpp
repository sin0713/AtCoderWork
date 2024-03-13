#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

struct Edge
{
  int to, cost;

  Edge(){};
  Edge(int to_, int cost_) : to(to_), cost(cost_){};
};

int main()
{
  int n = 7;
  vector<Edge> g(n);
  vector<int> costs = {3, 1, 4, 1, 5, 9};
  rep(i, n) {
    if (i == n-1) {
      g[i] = {-1, 0};
      continue;
    }
    g[i] = {i+1, costs[i]};
  }

  char p, q;
  cin >> p >> q;
  if (p > q) swap(p, q);

  int start = p - 'A';
  int end = q - 'A';
  int sum = 0;
  for (int i = start; i < end; i++) {
    sum += g[i].cost;
  } 

  cout << sum << endl;
  return 0;
}