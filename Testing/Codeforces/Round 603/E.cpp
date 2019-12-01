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

const int N = 1e6;
const int TN = 4 * N;

char a[N];
int tMin[TN], tMax[TN], tLazy[TN];

int minVal(int v) {
    return tMin[v] + tLazy[v];
}

int maxVal(int v) {
    return tMax[v] + tLazy[v];
}

void push(int v) {
    tLazy[2 * v + 1] += tLazy[v];
    tLazy[2 * v + 2] += tLazy[v];
    tMin[v] += tLazy[v];
    tMax[v] += tLazy[v];
    tLazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val) {
    if (l > r)
        return;

    if (l == tl && r == tr) {
        tLazy[v] += val;
        return;
    }

    push(v);

    int tm = (tl + tr) / 2;
    update(2 * v + 1, tl, tm, l, min(r, tm), val);
    update(2 * v + 2, tm + 1, tr, max(l, tm + 1), r, val);

    tMin[v] = min(minVal(2 * v + 1), minVal(2 * v + 2));
    tMax[v] = max(maxVal(2 * v + 1), maxVal(2 * v + 2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int pos = 0, sum = 0;
    for (auto c : s) {
        if (c == 'L') {
            pos = max(pos - 1, 0);
        } else if (c == 'R') {
            pos++;
        } else {
            int diff = 0;
            if (a[pos] == '(')
                diff--;
            else if (a[pos] == ')')
                diff++;
            a[pos] = c;
            if (a[pos] == '(')
                diff++;
            else if (a[pos] == ')')
                diff--;

            sum += diff;
            update(0, 0, N - 1, pos, N - 1, diff);
        }

        if (sum != 0 || minVal(0) < 0)
            cout << -1 << ' ';
        else
            cout << maxVal(0) << ' ';
    }
}
