#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> ReadVector(int n, int k) {
    vector<int> res(n);
    for (int i = 0; i < k ; ++i) {
        cin >> res[i];
    }
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = k; i < n; ++i) {
        res[i] = (a * res[i - 2] + b * res[i - 1] + c) % d;
    }
    return res;
}

int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        int n, k;
        cin >> n >> k;
        auto s = ReadVector(n, k);
        auto x = ReadVector(n, k);
        auto y = ReadVector(n, k);

        ll a = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            y[i] += x[i];
            if (s[i] > y[i]) {
                a += s[i] - y[i];
            } else if (s[i] < x[i]) {
                b += x[i] - s[i];
            }
        }

        ll val = accumulate(s.begin(), s.end(), 0LL);
        ll lb = accumulate(x.begin(), x.end(), 0LL);
        ll ub = accumulate(y.begin(), y.end(), 0LL);

        ll ans = (val >= lb && val <= ub) ? max(a, b) : -1;

        cout << "Case #" << tc << ": " << ans << endl;
    }
}
