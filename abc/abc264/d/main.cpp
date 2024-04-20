#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  map<string, int> dict;
  queue<string> queue;
  auto push = [&] (string s, int d) {
    if (dict.count(s)) return;

    dict[s] = d;
    queue.push(s);
  };

  push(s, 0);

  while(!queue.empty()) {
    string& current = queue.front(); 
    int cost = dict[current]; 
    queue.pop();

    for (int i = 0; i < n-1; i++) {
      string ns = current;
      swap(ns[i], ns[i+1]);
      push(ns, cost+1);
    }
  }

  string atcoder = "atcoder";
  cout << dict[atcoder] << endl;
  return 0;
}