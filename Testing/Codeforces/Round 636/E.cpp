#include <bits/stdc++.h>

using ll = long long;
using Graph = std::vector<std::vector<int>>;

std::vector<int> bfs(const Graph& graph, int source) {
  int n = graph.size();
  std::queue<int> que;
  std::vector<int> dist(n, INT_MAX);

  que.push(source);
  dist[source] = 0;

  while (!que.empty()) {
    auto cur = que.front(); que.pop();
    for (auto adj : graph[cur]) {
      if (dist[adj] != INT_MAX) {
        continue;
      }
      que.push(adj);
      dist[adj] = dist[cur] + 1;
    }
  }

  return dist;
}

int main() {
  int tests;
  std::cin >> tests;

  while (tests--) {
    int n, m, a, b, c;
    std::cin >> n >> m >> a >> b >> c;
    --a, --b, --c;
    std::vector<ll> cost(m);
    for (int i = 0; i < m; ++i) {
      std::cin >> cost[i];
    }
    Graph g(n);
    for (int i = 0; i < m; ++i) {
      int v, u;
      std::cin >> v >> u;
      --v, --u;
      g[v].push_back(u);
      g[u].push_back(v);
    }

    std::sort(cost.begin(), cost.end());
    std::vector<ll> partial_cost(m);
    std::partial_sum(cost.begin(), cost.end(), partial_cost.begin());

    auto dist_a = bfs(g, a);
    auto dist_b = bfs(g, b);
    auto dist_c = bfs(g, c);

    ll ans = LLONG_MAX;
    for (int v = 0; v < n; ++v) {
      int shared = dist_b[v];
      int unique_a = dist_a[v];
      int unique_c = dist_c[v];
      int total = shared + unique_a + unique_c;
      if (total > m) {
        continue;
      }
      ll val = 0;
      if (total > 0) {
        val += partial_cost[total - 1];
        if (shared > 0) {
          val += partial_cost[shared - 1];
        }
      }
      ans = std::min(ans, val);
    }

    std::cout << ans << std::endl;
  }
}
