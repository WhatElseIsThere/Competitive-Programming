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
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (ans[i] > 0)
                continue;

            ans[i] = 1;

            int j = p[i];
            while (j != i) {
                ans[i]++;
                j = p[j];
            }

            j = p[i];
            while (j != i) {
                ans[j] = ans[i];
                j = p[j];
            }
        }

        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
}
