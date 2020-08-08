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

    int parity_odd = 0, parity_even = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] & 1) {
        parity_odd ^= 1;
      } else {
        parity_even ^= 1;
      }
    }

    bool one_diff = false;
    sort(a.begin(), a.end());
    for (int i = 0; i + 1 < n; ++i) {
      one_diff |= (a[i + 1] == a[i] + 1);
    }

    if (parity_odd == parity_even && (parity_odd == 0 || one_diff)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
