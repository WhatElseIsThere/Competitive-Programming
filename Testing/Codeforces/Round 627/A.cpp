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

    int sum = 0;
    for (auto x : a) {
      sum += (x & 1);
    }

    bool ans = (sum == 0 || sum == n);

    cout << (ans ? "YES" : "NO") << endl;
  }
}
