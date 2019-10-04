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

const int MOD = 1e9 + 7;

int mul(int a, int b) {
    return (a * 1LL * b) % MOD;
}

int binPow(int a, ll n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

vector<int> primeDivs(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n != 1)
        res.push_back(n);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    ll n;
    cin >> x >> n;

    auto divs = primeDivs(x);

    int ans = 1;
    for (auto d : divs) {
        ll sum = 0, t = n;
        while (t) {
            sum += t / d;
            t /= d;
        }
        ans = mul(ans, binPow(d, sum));
    }

    cout << ans << endl;
}
