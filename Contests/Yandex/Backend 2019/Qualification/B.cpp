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


void moveTo(int v) {
    cout << v << endl;
    fflush(stdout);
}

vector<int> read() {
    int k;
    cin >> k;
    vector<int> res(k);
    for (int i = 0; i < k; i++)
        cin >> res[i];
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> g(n), gr(n);
    vector<bool> used(n);
    vector<int> cnt(n);

    int v = 0;
    while (true) {
        moveTo(v);
        auto us = read();

        if (!used[v]) {
            used[v] = true;
            for (auto u : us) {
                g[v].push_back(u);
                gr[u].push_back(v);
                if (!used[u])
                    cnt[v]++;
            }

            for (auto u : gr[v])
                cnt[u]--;
        }

        bool stop = true;
        for (int i = 0; i < n; i++) {
            if (!used[i])
                stop = false;
        }

        if (stop) {
            moveTo(-1);
            break;
        }

        int nextV = -1;
        for (auto u : us) {
            if (!used[u])
                nextV = u;
        }

        if (nextV != -1) {
            v = nextV;
            continue;
        }

        queue<int> q;
        q.push(v);
        vector<int> p(n, -1);
        p[v] = v;

        while (!q.empty()) {
            int a = q.front();
            q.pop();

            if (cnt[a] > 0) {
                v = a;
                break;
            }

            for (auto b : g[a]) {
                if (p[b] == -1) {
                    q.push(b);
                    p[b] = a;
                }
            }
        }

        vector<int> path;
        int cur = p[v];
        while (p[cur] != cur) {
            path.push_back(cur);
            cur = p[cur];
        }
        reverse(all(path));

        for (auto u : path) {
            moveTo(u);
            read();
        }
    }
}
