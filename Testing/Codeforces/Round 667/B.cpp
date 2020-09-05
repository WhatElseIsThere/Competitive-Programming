#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int tcs;
    cin >> tcs;

    while (tcs--) {
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        int d1 = min(a - x, n);
        int d2 = min(b - y, n);
        ll res1 = (a - d1) * 1LL * max(b - (n - d1), y);
        ll res2 = (b - d2) * 1LL * max(a - (n - d2), x);
        cout << min(res1, res2) << endl;
    }
}
