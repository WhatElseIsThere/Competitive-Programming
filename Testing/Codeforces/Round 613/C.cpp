#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

#ifdef LOCAL
    #define eprint(x) cerr << #x << " = " << (x) << endl
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprint(x)
    #define eprintf(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x;
    cin >> x;
    ll t = x;

    vector<pair<ll, int>> primes;
    for (ll d = 2; d * d <= x; d++) {
        int cnt = 0;
        while (x % d == 0) {
            x /= d;
            cnt++;
        }
        if (cnt) {
            primes.emplace_back(d, cnt);
        }
    }
    if (x > 1) {
        primes.emplace_back(x, 1);
    }

    ll ansVal = LLONG_MAX, ansP = -1, ansQ = -1;

    int k = sz(primes);
    for (int mask = 0; mask < (1 << k); mask++) {
        ll p = 1;
        for (int i = 0; i < k; i++) {
            if ((mask >> i) & 1) {
                for (int j = 0; j < primes[i].second; j++)
                    p *= primes[i].first;
            }
        }
        ll q = t / p;

        if (max(p, q) < ansVal) {
            ansVal = max(p, q);
            ansP = p;
            ansQ = q;
        }
    }

    cout << ansP << ' ' << ansQ << endl;
}
