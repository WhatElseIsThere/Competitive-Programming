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
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    vector<int> line(n);
    iota(all(line), 0);
    sort(all(line), [&] (int i, int j) {
        return (d[i] > d[j]);
    });

    vector<pair<int, int>> ans;
    for (int i = 0; i + 1 < n; i++)
        ans.emplace_back(line[i], line[i + 1]);

    for (int i = 0; i < n; i++) {
        int id = line[i];
        int k = d[id];

        int p = line[i + k - 1];
        ans.emplace_back(p, n + id);

        if (p == line.back())
            line.push_back(n + id);
    }

    auto f = [&] (int v) {
        if (v < n)
            return (2 * v);
        else
            return (2 * (v - n) + 1);
    };

    for (auto elem : ans) {
        int u = f(elem.first), v = f(elem.second);
        cout << (u + 1) << ' ' << (v + 1) << endl;
    }
}
