#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (n * a != m * b) {
      cout << "NO" << endl;
      continue;
    }

    vector<vector<int>> ans(n, vector<int>(m));
    int pos = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < a; ++j) {
        ans[i][pos] = 1;
        pos = (pos + 1) % m;
      }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << ans[i][j];
      }
      cout << endl;
    }
  }
}
