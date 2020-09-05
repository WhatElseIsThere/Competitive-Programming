#include <bits/stdc++.h>

using namespace std;

int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        int n;
        cin >> n;
        string in, out;
        cin >> in >> out;

        function<void(int, string&)> dfs = [&](int v, string& res) {
            res[v] = 'Y';
            if (out[v] == 'N') return;
            for (auto u : {v - 1, v + 1}) {
                if (u < 0 || u >= n) continue;
                if (in[u] == 'Y' && res[u] == 'N') {
                    dfs(u, res);
                }
            }
        };

        vector<string> ans(n, string(n, 'N'));
        for (int i = 0; i < n; ++i) {
            dfs(i, ans[i]);
        }

        cout << "Case #" << tc << ":" << endl;
        for (auto res : ans) {
            cout << res << endl;
        }
    }
}
