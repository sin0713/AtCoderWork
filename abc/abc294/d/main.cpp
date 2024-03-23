#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, q;
  cin >> n >> q;

  vector<int> people(n);
  rep(i, n) people[i] = i;
  set<int> not_call(people.begin(), people.end());
  set<int> not_come;

  rep(i, q) {
    int query;
    cin >> query;
    
    if (query == 1) {
      auto begin = not_call.begin();
      not_come.insert(*begin);
      not_call.erase(*begin);
      continue;
    }
    if (query == 2) {
      int x;
      cin >> x;
      x--;
      not_come.erase(x);
      continue;
    } 

    auto begin = not_come.begin();
    cout << *begin + 1 << '\n';
  }

  return 0;
}