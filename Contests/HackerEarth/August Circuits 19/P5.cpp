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

const int K = 700;

struct SegmentTree {
    vector<int> a;
    vector<vector<int>> t;

    void rebuild(int v, int tl, int tr) {
        t[v].clear();
        if (tr - tl == 1) {
            t[v] = {a[tl]};
            return;
        }
        int tm = (tl + tr) / 2;
        rebuild(2 * v + 1, tl, tm);
        rebuild(2 * v + 2, tm, tr);
        merge(all(t[2 * v + 1]), all(t[2 * v + 2]), back_inserter(t[v]));
    }

    void partition(int v, int tl, int tr, int l, int r, vector<int> &res) {
        if (max(tl, l) >= min(tr, r))
            return;
        if (tl >= l && tr <= r) {
            res.push_back(v);
            return;
        }
        int tm = (tl + tr) / 2;
        partition(2 * v + 1, tl, tm, l, r, res);
        partition(2 * v + 2, tm, tr, l, r, res);
    }

    void rebuild(const vector<int> &b) {
        a = b;
        rebuild(0, 0, sz(a));
    }

    SegmentTree(const vector<int> &b) {
        t.resize(4 * sz(b));
        rebuild(b);
    }

    vector<int> partition(int l, int r) {
        vector<int> res;
        partition(0, 0, sz(a), l, r + 1, res);
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int q;
    cin >> q;

    SegmentTree t(a);
    vector<pair<int, int>> changes;

    int lastAns = 0;
    while (q--) {
        int qt;
        cin >> qt;

        if (qt == 1) {
            int x, y;
            cin >> x >> y;

            x = (x ^ lastAns) - 1;
            y = (y ^ lastAns) - 1;

            changes.emplace_back(x, y);
        } else {
            int l, r, k;
            cin >> l >> r >> k;

            l = (l ^ lastAns) - 1;
            r = (r ^ lastAns) - 1;
            k = (k ^ lastAns);

            if (sz(changes) > K) {
                for (auto elem : changes) {
                    int x = elem.first, y = elem.second;
                    swap(a[x], a[y]);
                }
                t.rebuild(a);
                changes.clear();
            }

            vector<int> inc, exc;
            for (auto elem : changes) {
                int x = elem.first, y = elem.second;
                swap(a[x], a[y]);

                if (x >= l && x <= r && y >= l && y <= r)
                    continue;

                if (x >= l && x <= r) {
                    inc.push_back(a[x]);
                    exc.push_back(a[y]);
                }

                if (y >= l && y <= r) {
                    inc.push_back(a[y]);
                    exc.push_back(a[x]);
                }
            }

            for (int i = sz(changes) - 1; i >= 0; i--) {
                int x = changes[i].first, y = changes[i].second;
                swap(a[x], a[y]);
            }

            sort(all(inc));
            sort(all(exc));

            auto ids = t.partition(l, r);

            int lVal = -1, rVal = (r - l) + k;
            while (rVal - lVal > 1) {
                int mVal = (lVal + rVal) / 2;

                int cnt = 0;
                cnt += (upper_bound(all(inc), mVal) - inc.begin());
                cnt -= (upper_bound(all(exc), mVal) - exc.begin());
                for (auto id : ids)
                    cnt += (upper_bound(all(t.t[id]), mVal) - t.t[id].begin());

                if (mVal + 1 - cnt >= k)
                    rVal = mVal;
                else
                    lVal = mVal;
            }

            cout << rVal << endl;

            lastAns = rVal;
        }
    }
}
