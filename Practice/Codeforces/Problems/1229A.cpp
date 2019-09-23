#include <bits/stdc++.h>

using namespace std;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            deg[i] += ((a[i] & a[j]) != a[i]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int v = 0;
        for (int u = 0; u < n; u++) {
            if (deg[u] > deg[v])
                v = u;
        }
        if (deg[v] < (n - 1 - i)) {
            for (int u = 0; u < n; u++) {
                if (deg[u] != -1)
                    ans += b[u];
            }
            break;
        }
        for (int u = 0; u < n; u++) {
            if (u == v || deg[u] == -1)
                continue;
            deg[u] -= ((a[u] & a[v]) != a[u]);
        }
        deg[v] = -1;
    }

    cout << ans << endl;
}
