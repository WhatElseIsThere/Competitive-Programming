#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int x, y, n;
        cin >> x >> y >> n;
        int ans = (n / x) * x + y;
        if (ans > n) ans -= x;
        cout << ans << endl;
    }
}
