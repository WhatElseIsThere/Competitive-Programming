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

    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        cin >> n;
        
        int a = -1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                a = i;
                break;
            }
        }
        n /= a;

        int b = -1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0 && i != a) {
                b = i;
                break;
            }
        }

        int c = n / b;

        if (a == -1 || b == -1 || c == b) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << a << ' ' << b << ' ' << c << endl;
        }
    }
}
