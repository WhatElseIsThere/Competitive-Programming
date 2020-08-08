#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(a);
        sort(b.begin(), b.end());
        int ans = n - 1;
        for (int i = 0; i < n; ++i) {
            int k = 0;
            for (int j = 0; j < n && i + k < n; ++j) {
                if (a[j] == b[i + k]) {
                    ++k;
                }
            }
            ans = min(ans, n - k);
        }

        cout << ans << endl;
    }
}
