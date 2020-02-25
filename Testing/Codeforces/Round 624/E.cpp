#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5000;

int lb[MAX_N + 1], ub[MAX_N + 1];

int main() {
    for (int tn = 1; tn <= MAX_N; ++tn) {
        lb[tn] = INT_MAX;
        for (int tn_left = 0; tn_left < tn; ++tn_left) {
            int tn_right = tn - 1 - tn_left;
            int cur_depth = lb[tn_left] + lb[tn_right] + tn - 1;
            lb[tn] = min(lb[tn], cur_depth);
        }
    }

    for (int n = 1; n <= MAX_N; ++n) {
        ub[n] = n * (n - 1) / 2;
    }

    int tests;
    cin >> tests;
    while (tests--) {
        int n, d;
        cin >> n >> d;
        vector<int> p(n, -1);

        if (d < lb[n] || d > ub[n]) {
            cout << "NO" << endl;
            continue;
        }

        int v = 0;
        function<void(int, int, int)> dfs = [&] (int par, int tn, int td) {
            if (tn == 0) {
                return;
            }
            p[v++] = par;
            if (tn == 1) {
                return;
            }
            for (int tn_left = 0; tn_left < tn; ++tn_left) {
                int tn_right = tn - 1 - tn_left;
                int cur_lb = lb[tn_left] + lb[tn_right] + tn - 1;
                int cur_ub = ub[tn_left] + ub[tn_right] + tn - 1;
                if (td >= cur_lb && td <= cur_ub) {
                    int td_left = min(td - (tn - 1) - lb[tn_right], ub[tn_left]);
                    int td_right = td - (tn - 1) - td_left;
                    int cur_v = v - 1;
                    dfs(cur_v, tn_left, td_left);
                    dfs(cur_v, tn_right, td_right);
                    break;
                }
            }
        };
        dfs(-1, n, d);

        cout << "YES" << endl;
        for (int i = 1; i < n; i++) {
            cout << (p[i] + 1) << ' ';
        }
        cout << endl;
    }
}
