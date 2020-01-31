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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
    vector<ll> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<ll> sl(n - 1), sr(n - 1);
    for (int i = 0; i < n - 1; i++) {
        sl[i] = l[i + 1] - r[i];
        sr[i] = r[i + 1] - l[i];
    }

    vector<array<ll, 3>> events;
    for (int i = 0; i < n - 1; i++) {
        events.push_back({sl[i], 0, i});
    }
    for (int i = 0; i < m; i++) {
        events.push_back({a[i], 1, i});
    }
    sort(all(events));

    vector<int> ans(n - 1);
    set<pair<ll, int>> st;
    for (auto [pos, type, i] : events) {
        if (type == 0) {
            st.insert({sr[i], i});
        } else {
            if (st.empty()) {
                continue;
            }
            auto it = st.begin();
            int j = it->second;
            if (sr[j] < a[i]) {
                continue;
            }
            ans[j] = i;
            st.erase(it);
        }
    }

    if (!st.empty()) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << (ans[i] + 1) << ' ';
        }
        cout << endl;
    }
}
