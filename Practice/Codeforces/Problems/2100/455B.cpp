#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

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

const int K = 26;

struct Node {
    int nxt[K];
    Node() {
        fill(all(nxt), -1);
    }
};

vector<Node> nodes = {Node()};

bool calc1(int v) {
    bool res = false;
    for (int c = 0; c < K; c++) {
        int u = nodes[v].nxt[c];
        if (u != -1 && !calc1(u))
            res = true;
    }
    return res;
}

bool calc2(int v) {
    bool res = (accumulate(all(nodes[v].nxt), 0) == -K);
    for (int c = 0; c < K; c++) {
        int u = nodes[v].nxt[c];
        if (u != -1 && !calc2(u))
            res = true;
    }
    return res;
}

void add(string s) {
    int v = 0;
    for (auto c : s) {
        c -= 'a';
        if (nodes[v].nxt[c] == -1) {
            nodes.push_back(Node());
            nodes[v].nxt[c] = sz(nodes) - 1;
        }
        v = nodes[v].nxt[c];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        add(s);
    }

    bool ans = calc1(0);

    if (!ans) {
        cout << "Second" << endl;
    } else {
        if ((k & 1) || calc2(0)) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }
}
