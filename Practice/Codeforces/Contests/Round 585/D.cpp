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

    int n;
    cin >> n;
    string s;
    cin >> s;

    int sum[2] = {};
    int cnt[2] = {};

    for (int i = 0; i < n; i++) {
        int half = (i < n / 2);
        if (s[i] != '?') {
            sum[half] += (s[i] - '0');
        } else {
            cnt[half]++;
        }
    }

    sum[0] += (max(cnt[0] - cnt[1], 0) / 2) * 9;
    sum[1] += (max(cnt[1] - cnt[0], 0) / 2) * 9;

    bool ans = (sum[0] == sum[1]);

    cout << (ans ? "Bicarp" : "Monocarp") << endl;
}
