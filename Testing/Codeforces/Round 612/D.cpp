#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

#ifdef LOCAL
    #define eprint(x) cerr << #x << " = " << (x) << endl
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprint(x)
    #define eprintf(...)
#endif


template <typename T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5;

vector<int> g[N];
int c[N], tSize[N], ans[N];
Tree<int> values;

void dfs1(int v) {
    tSize[v] = 1;
    for (auto u : g[v]) {
        dfs1(u);
        tSize[v] += tSize[u];
    }
}

void dfs2(int v) {
    auto it = values.find_by_order(c[v]);
    ans[v] = *it;
    values.erase(it);
    for (auto u : g[v])
        dfs2(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int root = -1;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p >> c[i];
        p--;

        if (p == -1)
            root = i;
        else
            g[p].push_back(i);
    }

    dfs1(root);
    for (int i = 0; i < n; i++) {
        if (c[i] >= tSize[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (int i = 1; i <= n; i++)
        values.insert(i);
    dfs2(root);

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}
