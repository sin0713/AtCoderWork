#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  queue<int> q;
  rep(i, n){
    int a;
    cin >> a;
    q.push(a);
  }

  int cnt = 0;
  int current = k;
  while(!q.empty()) {
    int front = q.front();
    if (current >= front) {
      current -= front;
      q.pop();
      continue;
    }

    cnt++;
    current = k;
  }

  cout << cnt+1 << endl;
  return 0;
}