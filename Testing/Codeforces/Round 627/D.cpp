#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = a[i] - b[i];
  }
  sort(c.begin(), c.end());

  long long ans = 0;
  for (int r = 0; r < n; ++r) {
    int l = upper_bound(c.begin(), c.begin() + r, -c[r]) - c.begin();
    ans += r - l;
  }

  cout << ans << endl;
}
