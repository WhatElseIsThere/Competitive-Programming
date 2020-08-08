#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> k;
    vector<int> t(n), a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i] >> a[i] >> b[i];
    }

    vector<int> ps[2][2];
    for (int i = 0; i < n; ++i) {
        ps[a[i]][b[i]].push_back(t[i]);
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            auto& v = ps[i][j];
            sort(v.begin(), v.end());
            partial_sum(v.begin(), v.end(), v.begin());
            v.insert(v.begin(), 0);
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < ps[1][1].size(); ++i) {
        if (k - i >= min(ps[0][1].size(), ps[1][0].size())) {
            continue;
        }
        ans = min(ans, ps[1][1][i] + ps[0][1][k - i] + ps[1][0][k - i]);
    }

    cout << (ans == INT_MAX ? -1 : ans) << endl;
}
