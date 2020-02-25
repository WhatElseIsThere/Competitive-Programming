#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX_V = 1e8;
const int MAX_POS = 2 * MAX_V;

void modify(unordered_map<int, ll>& f, int pos, ll val) {
    for (; pos <= MAX_POS; pos |= (pos + 1)) {
        f[pos] += val;
    }
}

ll rsq(unordered_map<int, ll>& f, int r) {
    ll res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
        auto it = f.find(r);
        if (it != f.end()) {
            res += it->second;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<pair<int, int>> elems;
    for (int i = 0; i < n; ++i) {
        elems.emplace_back(x[i], v[i] + MAX_V);
    }
    sort(elems.begin(), elems.end());

    ll ans = 0;
    unordered_map<int, ll> prefix_sum, prefix_cnt;
    for (auto [ex, ev] : elems) {
        ll sum = rsq(prefix_sum, ev);
        ll cnt = rsq(prefix_cnt, ev);
        ans += cnt * ex - sum;
        modify(prefix_sum, ev, ex);
        modify(prefix_cnt, ev, 1);
    }

    cout << ans << endl;
}
