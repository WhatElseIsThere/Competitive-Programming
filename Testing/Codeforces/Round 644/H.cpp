#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll ToInt(string s) {
  ll res = 0;
  reverse(s.begin(), s.end());
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      res += (1LL << i);
    }
  }
  return res;
}

string ToString(ll n, int width) {
  string res;
  while (n) {
    res += ((n & 1) ? '1' : '0');
    n >>= 1;
  }
  while (res.size() < width) res += '0';
  reverse(res.begin(), res.end());
  return res;
}

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      a[i] = ToInt(s);
    }

    ll initial = (1LL << (m - 1)) - 1;
    ll expected_cnt = ((1LL << m) - n + 1) / 2;
    for (ll val = max(initial - n, 0LL); val <= initial + n; ++val) {
      ll cnt = val + 1;
      for (auto x : a) {
        if (x <= val) {
          --cnt;
        }
      }
      if (cnt == expected_cnt) {
        cout << ToString(val, m) << endl;
        break;
      }
    }
  }
}
