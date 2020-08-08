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

        int cnt[2][2] = {};
        for (int i = 0; i < n; ++i) {
            ++cnt[i % 2][a[i] % 2];
        }

        int ans = (cnt[0][1] == cnt[1][0]) ? cnt[0][1] : -1;
        cout << ans << endl;
    }
}
