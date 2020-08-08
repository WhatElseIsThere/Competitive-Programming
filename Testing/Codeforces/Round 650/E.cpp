#include <bits/stdc++.h>

using namespace std;

const int kSigma = 26;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> cnt(kSigma);
        for (auto c : s) {
            ++cnt[c - 'a'];
        }
        int ans = 0;
        for (int p_num = 1; p_num <= n; ++p_num) {
            int p_len = 0;
            for (int c = 0; c < kSigma; ++c) {
                p_len += cnt[c] / p_num;
            }
            if (p_len == 0) continue;
            while (k % p_len != 0) {
                --p_len;
            }
            ans = max(ans, p_len * p_num);
        }
        cout << ans << endl;
    }
}
