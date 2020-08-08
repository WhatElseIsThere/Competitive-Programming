#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        string s;
        cin >> s;
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }

        unordered_map<char, int> cnt;
        for (auto c : s) {
            ++cnt[c];
        }

        string ans = string(m, ' ');

        char c = 'z';
        vector<int> used;
        while (used.size() < m) {
            vector<int> to_add;
            for (int i = 0; i < m; ++i) {
                if (find(used.begin(), used.end(), i) != used.end()) {
                    continue;
                }
                int val = 0;
                for (auto j : used) {
                    val += abs(j - i);
                }
                if (val == b[i]) {
                    to_add.push_back(i);
                }
            }
            while (c >= 'a' && cnt[c] < to_add.size()) {
                --c;
            }
            for (auto i : to_add) {
                ans[i] = c;
                used.push_back(i);
            }
            --c;
        }

        cout << ans << endl;
    }
}
