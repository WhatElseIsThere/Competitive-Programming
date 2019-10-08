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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e3;

int x[N], y[N];
ll d[N][N];

ll sq(int x) {
    return (x * 1LL * x);
}

ll dist(int i, int j) {
    return (sq(x[i] - x[j]) + sq(y[i] - y[j]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, g;
    cin >> n >> g;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = dist(i, j);

    int k = n / g;

    ll ans = LLONG_MAX;
    vector<vector<int>> ansClusters;

    while (double(clock()) / CLOCKS_PER_SEC < 4.9) {
        vector<int> p(n);
        iota(all(p), 0);
        shuffle(all(p), rng);

        vector<int> centers(p.begin(), p.begin() + k);
        vector<vector<int>> clusters(k);

        bool bad = false;

        for (int i = 0; i < n; i++) {
            int closest = 0;
            for (int j = 1; j < k; j++) {
                if (d[i][centers[j]] < d[i][centers[closest]])
                    closest = j;
            }
            clusters[closest].push_back(i);

            if (d[i][centers[closest]] > ans) {
                bad = true;
                break;
            }
        }

        if (bad)
            continue;

        for (int i = 0; i < k; i++) {
            if (sz(clusters[i]) >= g)
                continue;

            for (auto id : clusters[i]) {
                int closest = -1;
                for (int j = 0; j < k; j++) {
                    if (j == i || clusters[j].empty())
                        continue;
                    if (closest == -1 || (d[id][centers[j]] < d[id][centers[closest]]))
                        closest = j;
                }
                clusters[closest].push_back(id);

                if (d[id][centers[closest]] > ans) {
                    bad = true;
                    break;
                }
            }
            clusters[i].clear();

            if (bad)
                break;
        }

        if (bad)
            continue;

        ll val = 0;
        for (int i = 0; i < k; i++) {
            for (auto id : clusters[i])
                val = max(val, d[id][centers[i]]);
        }

        if (val < ans) {
            ans = val;
            ansClusters = clusters;
        }
    }

    ansClusters.erase(remove_if(all(ansClusters), [&] (vector<int> cl) {
        return cl.empty();
    }), ansClusters.end());

    cout << sz(ansClusters) << endl;
    for (auto cl : ansClusters) {
        cout << sz(cl) << endl;
        for (auto id : cl)
            cout << (id + 1) << ' ';
        cout << endl;
    }
}
