#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, h, l, r;
  cin >> n >> h >> l >> r;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto f = [&](int x) {
    return x >= l && x <= r;
  };

  vector<vector<int>> dp(n + 1, vector<int>(h, INT_MIN));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < h; ++j) {
      if (dp[i][j] == INT_MIN) {
        continue;
      }
      int j1 = (j + a[i]) % h;
      int j2 = (j + a[i] - 1) % h;
      dp[i + 1][j1] = max(dp[i + 1][j1], dp[i][j] + f(j1));
      dp[i + 1][j2] = max(dp[i + 1][j2], dp[i][j] + f(j2));
    }
  }

  int ans = *max_element(dp[n].begin(), dp[n].end());

  cout << ans << endl;
}
