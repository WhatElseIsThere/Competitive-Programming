#include <bits/stdc++.h>

using namespace std;

int dist(int x1, int y1, int x2, int y2) {
    int res = 0;
    if (x1 == x2 && x1 % 2 == 0) {
        res += y2 - y1;
    }
    if (x1 % 2 == 0) {
        res += (x2 - x1) / 2;
    } else {
        res += (x2 - x1 + 1) / 2;
    }
    return res;
}

int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        int n;
        cin >> n;
        vector<int> r(n), c(n);
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }

        vector<pair<int, int>> points = {{0, 0}};
        for (int i = 0; i < n; ++i) {
            points.push_back({r[i] - c[i], c[i] - 1});
        }
        sort(points.begin(), points.end());

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            auto p1 = points[i], p2 = points[i + 1];
            ans += dist(p1.first, p1.second, p2.first, p2.second);
        }

        cout << ans << endl;
    }
}
