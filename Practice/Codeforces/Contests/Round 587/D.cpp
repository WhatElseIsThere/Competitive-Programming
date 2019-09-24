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

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int mx = *max_element(all(a));

    int z = 0;
    for (int i = 0; i < n; i++)
        z = gcd(z, mx - a[i]);

    ll y = 0;
    for (int i = 0; i < n; i++)
        y += (mx - a[i]) / z;

    cout << y << ' ' << z << endl;
}
