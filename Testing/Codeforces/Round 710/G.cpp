#include <bits/stdc++.h>

using namespace std;

const int kSigma = 26;

int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        string s;
        cin >> s;
        int n = s.size();

        vector<vector<int>> all_pos(kSigma);
        vector<int> last_pos;
        for (int i = n - 1; i >= 0; --i) {
            int c = s[i] - 'a';
            if (all_pos[c].empty()) {
                last_pos.push_back(i);
            }
            all_pos[c].push_back(i);
        }

        string ans;
        while (!last_pos.empty()) {
            for (int i = kSigma - 1; i >= 0; --i) {
                if (all_pos[i].empty()) continue;
                if (!last_pos.empty() && all_pos[i].back() > last_pos.back()) continue;
                char c = char('a' + i);
                ans += c;
                int cur_pos = all_pos[i].back();
                for (auto& p : all_pos) {
                    while (!p.empty() && p.back() < cur_pos) {
                        p.pop_back();
                    }
                }
                all_pos[i].clear();
                for (auto it = last_pos.begin(); it != last_pos.end(); ++it) {
                    if (s[*it] == c) {
                        last_pos.erase(it);
                        break;
                    }
                }
                break;
            }
        }

        cout << ans << endl;
    }
}
