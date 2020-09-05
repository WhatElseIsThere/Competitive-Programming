#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int kInf = 1'000'000'000;

vector<int> ReadVector(int n, int k) {
    vector<int> res(n);
    for (int i = 0; i < k ; ++i) {
        cin >> res[i];
    }
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = k; i < n; ++i) {
        res[i] = (a * res[i - 2] + b * res[i - 1] + c) % d + 1;
    }
    return res;
}

int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        int n, m, k, s;
        cin >> n >> m >> k >> s;
        auto p = ReadVector(n, k);
        auto q = ReadVector(m, k);

        sort(p.begin(), p.end());
        sort(q.begin(), q.end());

        auto ReqT = [&] (int x, int lx, int rx) {
            if (lx >= x) return rx - x;
            if (rx <= x) return x - lx;
            return rx - lx + min(rx - x, x - lx);
        };

        auto Check = [&] (int t) {
            int j = 0;
            for (int i = 0; i < n && j < m; ++i) {
                int lx = q[j];
                for (; j < m; ++j) {
                    int rx = q[j];
                    if (ReqT(p[i], lx, rx) > t) break;
                }
            }
            return j == m;
        };

        int lb = 0, ub = kInf;
        while (ub - lb > 1) {
            int mid = (lb + ub) / 2;
            if (Check(mid)) {
                ub = mid;
            } else {
                lb = mid;
            }
        }

        cout << "Case #" << tc << ": " << ub << endl;
    }
}
