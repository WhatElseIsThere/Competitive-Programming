#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        ll n, m, x;
        cin >> n >> m >> x;
        --x;

        ll c = x / n, r = x % n;
        cout << (r * m + c + 1) << endl;
    }
}
