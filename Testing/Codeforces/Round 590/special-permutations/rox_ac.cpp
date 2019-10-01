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

int pos(int k, int val) {
    if (val == k)
        return 1;
    return (val + (val < k));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> x(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> x[i];

    vector<vector<int>> y(n + 1);
    for (int i = 1; i <= m; i++)
        y[x[i]].push_back(i);

    vector<ll> ans(n + 1);
    for (int i = 1; i + 1 <= m; i++)
        ans[1] += abs(pos(1, x[i]) - pos(1, x[i + 1]));

    for (int i = 2; i <= n; i++) {
        vector<int> ids;
        for (auto j : y[i - 1]) {
            ids.push_back(j);
            ids.push_back(max(j - 1, 1));
        }
        for (auto j : y[i]) {
            ids.push_back(j);
            ids.push_back(max(j - 1, 1));
        }
        sort(all(ids));
        ids.erase(unique(all(ids)), ids.end());

        ans[i] = ans[i - 1];
        for (auto j : ids) {
            if (j + 1 > m)
                break;
            ans[i] -= abs(pos(i - 1, x[j]) - pos(i - 1, x[j + 1]));
            ans[i] += abs(pos(i, x[j]) - pos(i, x[j + 1]));
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}
