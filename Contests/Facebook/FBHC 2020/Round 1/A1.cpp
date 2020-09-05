#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int kMaxW = 20;
const int kMod = 1'000'000'007;

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
        int n, k, w;
        cin >> n >> k >> w;
        auto l = ReadVector(n, k);
        auto h = ReadVector(n, k);

        int ans = 1, p = 0;
        for (int i = 0; i < n; ++i) {
            int x_overlap = 0, y_overlap = 0;
            if (i > 0 && l[i - 1] + w >= l[i]) {
                x_overlap = l[i - 1] + w - l[i];
                for (int j = max(i - kMaxW, 0); j < i; ++j) {
                    if (l[j] + w >= l[i]) {
                        y_overlap = max(y_overlap, h[j]);
                    }
                }
                y_overlap = min(y_overlap, h[i]);
            }
            p += 2 * (w - x_overlap + h[i] - y_overlap);  // fits
            p %= kMod;
            ans = (ans * ll(p)) % kMod;
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }
}
