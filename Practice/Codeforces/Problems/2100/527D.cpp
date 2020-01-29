#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

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

const int MAX_POS = 1e9;

unordered_map<int, int> f;

int get_max(int r) {
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        if (f.count(r))
            res = max(res, f[r]);
    return res;
}

void upd_val(int pos, int val) {
    for (; pos <= MAX_POS; pos |= (pos + 1))
        f[pos] = max(f[pos], val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        int x, w;
        cin >> x >> w;
        points.emplace_back(x, w);
    }

    sort(all(points));

    int ans = 0;
    for (auto [x, w] : points) {
        int cur = get_max(x - w) + 1;
        ans = max(ans, cur);
        upd_val(x + w, cur);
    }

    cout << ans << endl;
}
