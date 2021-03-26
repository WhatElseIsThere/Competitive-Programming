#include <bits/stdc++.h>

using namespace std;

int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> pos;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                pos.push_back(i);
            }
        }

        if (pos.size() == 1) {
            cout << 1 << endl;
            continue;
        }

        int ans = 2, i = 0;
        while (pos[i] < pos.back() - k) {
            int nxt = -1;
            for (int j = i + 1; j < pos.size(); ++j) {
                if (pos[j] - pos[i] <= k) {
                    nxt = j;
                }
            }
            ++ans;
            i = nxt;
        }

        cout << ans << endl;
    }
}
