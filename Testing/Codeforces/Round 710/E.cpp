#include <bits/stdc++.h>

using namespace std;

int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        int n;
        cin >> n;
        vector<int> q(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> q[i];
        }

        vector<int> ans_min, ans_max;
        deque<int> deq_min, deq_max;
        for (int i = 1; i <= n; ++i) {
            if (q[i - 1] < q[i]) {
                ans_min.push_back(q[i]);
                ans_max.push_back(q[i]);
                for (int j = q[i - 1] + 1; j < q[i]; ++j) {
                    deq_min.push_back(j);
                    deq_max.push_back(j);
                }
                continue;
            }
            ans_min.push_back(deq_min.front());
            deq_min.pop_front();
            ans_max.push_back(deq_max.back());
            deq_max.pop_back();
        }

        for (auto x : ans_min) {
            cout << x << " ";
        }
        cout << endl;

        for (auto x : ans_max) {
            cout << x << " ";
        }
        cout << endl;
    }
}
