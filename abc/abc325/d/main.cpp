#include <vector>
#include <algorithm>
#include <iostream>
#include <atcoder/all>
#include <math.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF (1 << 30)

using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<pair<ll, ll>> range_list(n); 
  rep(i, n) {
    ll left;
    ll right;
    cin >> left >> right;
    range_list[i] = { left, left + right };
  }
  sort(range_list.begin(), range_list.end());

  priority_queue<ll, vector<ll>, greater<ll>> queue;
  int index = 0;
  ll t = 1;
  int ans = 0;
  while(index < n || !queue.empty()) {
    // 範囲内の商品を挿入
    while(index < n && range_list[index].first <= t) {
      queue.push(range_list[index].second);
      index++;
    }
    // 範囲外の商品を削除
    while(!queue.empty() && queue.top() < t) {
      queue.pop();
    }

    // print
    if (!queue.empty()) {
      queue.pop(); 
      ans++;
    }

    // 時刻を進める 
    if (queue.empty() && index < n) {
      t = range_list[index].first;
    } else {
      t++; 
    }
  }


  cout << ans << endl;
  return 0;
}