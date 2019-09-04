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

struct SegmentTree {
    int n;
    vector<ll> t;

    SegmentTree(int n) : n(n) {
        t.resize(4 * n);
    }

    void add(int v, int tl, int tr, int l, int r, ll val) {
        if (max(tl, l) >= min(tr, r))
            return;
        if (tl >= l && tr <= r) {
            t[v] += val;
            return;
        }
        int tm = (tl + tr) / 2;
        add(v * 2 + 1, tl, tm, l, r, val);
        add(v * 2 + 2, tm, tr, l, r, val);
    }

    ll get(int v, int tl, int tr, int pos) {
        if (tr - tl == 1)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos < tm)
            return (t[v] + get(v * 2 + 1, tl, tm, pos));
        else
            return (t[v] + get(v * 2 + 2, tm, tr, pos));
    }

    void add(int l, int r, ll val) {
        add(0, 0, n, l, r, val);
    }

    ll get(int pos) {
        return get(0, 0, n, pos);
    }
};

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ql(m), qr(m);
    for (int i = 0; i < m; i++) {
        cin >> ql[i] >> qr[i];
        ql[i]--, qr[i]--;
    }

    vector<vector<int>> toAns(n);
    for (int i = 0; i < m; i++)
        toAns[qr[i]].push_back(i);

    vector<ll> ans(m);
    vector<pair<int, int>> gcds;
    SegmentTree ta(n), tb(n);

    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> gcdsNew;
        gcdsNew.emplace_back(a[i], i);
        for (auto elem : gcds) {
            int g = elem.first, l = elem.second;
            g = gcd(g, gcdsNew.back().first);
            if (g == gcdsNew.back().first)
                gcdsNew.back().second = l;
            else
                gcdsNew.emplace_back(g, l);
        }
        gcds.swap(gcdsNew);

        for (int j = 0; j < sz(gcds); j++) {
            int g = gcds[j].first, l = gcds[j].second;
            int r = (j ? gcds[j - 1].second : i + 1);
            ta.add(l, r, -g);
            tb.add(l, r, ll(g) * r);
            tb.add(0, l, ll(g) * (r - l));
        }

        for (auto id : toAns[i]) {
            int l = ql[id];
            ans[id] = (ta.get(l) * l) + tb.get(l);
        }
    }

    for (auto val : ans)
        cout << val << '\n';
}
