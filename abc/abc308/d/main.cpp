#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

int main()
{
  int h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  string snuke = "snukes";
  int n = snuke.size() - 1;
  unordered_map<char, char> next_map;
  rep(i, n) next_map[snuke[i]] = snuke[i+1];

  queue<P> q;
  vector<vector<bool>> dist(h, vector<bool>(w));
  q.emplace(0, 0);
  dist[0][0] = true;

  while(!q.empty()) {
    auto [i, j] = q.front(); q.pop();

    rep(k, 4) {
      int ai = i + di[k];
      int aj = j + dj[k];
      if (ai < 0 || aj < 0 || ai >= h || aj >= w) continue;
      if (dist[ai][aj]) continue;
      if (s[ai][aj] != next_map[s[i][j]]) continue;

      dist[ai][aj] = true;
      q.emplace(ai, aj);
    }
  }

  if (dist[h-1][w-1]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}