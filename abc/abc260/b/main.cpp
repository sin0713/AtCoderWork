#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

struct Person {
  int id, a, b;
  bool passed;

  int sum() {
    return a + b;
  }

  Person(){};
  Person(int id, int a, int b, bool passed = false):id(id), a(a), b(b), passed(passed) {};
};

int main() {
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  vector<Person> ps;
  rep(i, n) {
    ps.emplace_back(i, a[i], b[i]);
  }

  auto compa = [](Person& l, Person& r) -> bool {
    if (l.a != r.a) {
      return l.a > r.a;
    } else {
      return l.id < r.id;
    }
  };
  auto compb = [](Person& l, Person& r) -> bool {
    if (l.b != r.b) {
      return l.b > r.b;
    } else {
      return l.id < r.id;
    }
  };
  auto compsum = [](Person& l, Person& r) -> bool {
    if (l.sum() != r.sum()) {
      return l.sum() > r.sum();
    } else {
      return l.id < r.id;
    }
  };

  vector<int> ans;
  auto check = [&](int limit, auto comp) {
    sort(ps.begin(), ps.end(), comp);
    int cnt = 0;
    rep(i, n) {
      if (cnt == limit) break;
      if (ps[i].passed) continue;

      ans.push_back(ps[i].id);
      ps[i].passed = true;
      cnt++;
    }
  };

  check(x, compa);
  check(y, compb);
  check(z, compsum);

  sort(ans.begin(), ans.end());
  for (auto x : ans) {
    cout << x+1 << '\n';
  }
  return 0;
}