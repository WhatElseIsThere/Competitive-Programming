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
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for (int i = 0; i + 1 < n; ++i) {
      ans = min(ans, a[i + 1] - a[i]);
    }
    cout << ans << endl;
  }
}
