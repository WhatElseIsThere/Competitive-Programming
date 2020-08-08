#include <bits/stdc++.h>

using namespace std;

int diff(const string& s, const string& t) {
  assert(s.size() == t.size());
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    res += (s[i] != t[i]);
  }
  return res;
}

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }

    string ans = "-1";
    for (int i = 0; i < m; ++i) {
      for (char c = 'a'; c <= 'z'; ++c) {
        string t = s[0];
        t[i] = c;

        bool good = true;
        for (int j = 0; j < n; ++j) {
          if (diff(s[j], t) > 1) {
            good = false;
          }
        }

        if (good) {
          ans = t;
        }
      }
    }

    cout << ans << endl;
  }
}
