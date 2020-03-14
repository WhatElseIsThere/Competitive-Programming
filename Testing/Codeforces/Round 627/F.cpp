#include <bits/stdc++.h>

using namespace std;

const int kN = 2e5;

int c[kN];
vector<int> g[kN];
int dp[kN], ans[kN];

void dfs1(int v, int p) {
  dp[v] = c[v];
  for (auto u : g[v]) {
    if (u == p) {
      continue;
    }
    dfs1(u, v);
    dp[v] += max(dp[u], 0);
  }
}

void dfs2(int v, int p, int val) {
  ans[v] = dp[v] + val;
  for (auto u : g[v]) {
    if (u == p) {
      continue;
    }
    int u_val = max(ans[v] - max(dp[u], 0), 0);
    dfs2(u, v, u_val);
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    if (c[i] == 0) {
      c[i] = -1;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    g[v].push_back(u);
    g[u].push_back(v);
  }

  dfs1(0, -1);
  dfs2(0, -1, 0);

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}
