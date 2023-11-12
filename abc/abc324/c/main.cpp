#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
//#include <atcoder/all>

using namespace std;

// マクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;
string t_dash;
vector<string> t_list;

int count_same(string t, string t_dash) {
  int res = 0;
  int loop_cnt = min(t.size(), t_dash.size());
  rep(i, loop_cnt) {
    if (t[i] != t_dash[i]) break;
    res++;
  }

  return res;
}

int count_same_reverse(string t, string t_dash) {
  int res = 0;
  int loop_cnt = min(t.size(), t_dash.size());
  rep(i, loop_cnt) {
    if (t[(int)t.size() - (i + 1)] != t_dash[(int)t_dash.size() - (i + 1)]) {
      break;
    }
    res++;
  }

  return res;
}

bool check_same(int a, int b, string t, string t_dash) {
  if (a == b && b == (int)t.size() && (int)t.size() == (int)t_dash.size()) {
    return true;
  } 

  return false;
}

bool check_insert(int a, int b, string t, string t_dash) {
  if (a + b >= (int)t.size() && a + b == (int)t_dash.size() - 1) {
    return true;
  }

  return false;
}

bool check_delete(int a, int b, string t, string t_dash) {
  if (a + b >= (int)t.size() - 1 && a + b == (int)t_dash.size()) {
    return true;
  }
  return false;
}

bool check_replace(int a, int b, string t, string t_dash) {
  if (a + b == (int)t.size() - 1 && a + b == (int)t_dash.size() - 1) {
    return true;
  }
  return false;
}

int main() {
  cin >> n >> t_dash;
  t_list.resize(n);
  rep(i, n) cin >> t_list[i];


  vector<long long> index_list;
  rep(i, t_list.size()) {
    if (abs((int)t_list.size() - (int)t_dash.size()) >= 2) continue;

    int a = count_same(t_list[i], t_dash);
    int b = count_same_reverse(t_list[i], t_dash);
    if (check_same(a, b, t_list[i], t_dash) 
      || check_insert(a, b, t_list[i], t_dash)
      || check_delete(a, b, t_list[i], t_dash)
      || check_replace(a, b, t_list[i], t_dash)) {
        index_list.push_back(i + 1);
      }
  }

  cout << index_list.size() << endl;

  rep(i, index_list.size()) {
    cout << index_list[i] << " ";
  }
  cout << endl;

  return 0;
}