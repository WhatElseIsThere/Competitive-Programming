#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    unordered_map<int, int> l, r;
    for (int i = 0; i < n; ++i) {
      int x = a[i];
      if (!l.count(x)) {
        l[x] = i;
      }
      r[x] = max(r[x], i);
    }
    bool ans = false;
    for (auto x : a) {
      ans |= (r[x] >= l[x] + 2);
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
}
