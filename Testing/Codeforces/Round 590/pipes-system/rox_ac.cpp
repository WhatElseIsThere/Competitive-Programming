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

    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++) {
                cin >> a[i][j];
                a[i][j] = (a[i][j] <= '2');
            }
        }

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 1)
                continue;
            if (a[i][j ^ 1] == 1) {
                j = 0;
                break;
            }
            j ^= 1;
        }

        cout << (j == 1 ? "YES" : "NO") << endl;
    }
}
