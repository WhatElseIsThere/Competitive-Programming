#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    int n, k;
    cin >> n >> k;
    int max_div = 1;
    for (int p = 1; p * p <= n; ++p) {
      if (n % p == 0) {
        int q = n / p;
        if (p <= k) {
          max_div = max(max_div, p);
        }
        if (q <= k) {
          max_div = max(max_div, q);
        }
      }
    }
    cout << n / max_div << endl;
  }
}
