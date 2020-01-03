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

const int MOD = 1e9 + 7;
const int SIGMA = 26;
const int N = 1e6;

int HMOD[] = {int(1e9) + 7, int(1e9) + 9};
const int P = 31;

int ctoi(char c) {
    return (c - 'a');
}

struct Eertree {
    struct Node {
        int nxt[SIGMA], link, len, cnt, pos;
        Node(int link, int len) : link(link), len(len), cnt(0), pos(-1) {
            memset(nxt, 0, sizeof(nxt));
        }
    };

    vector<int> s;
    vector<Node> t;
    int p;

    Eertree() {
        s.push_back(-1);
        t.emplace_back(1, 0);
        t.emplace_back(0, -1);
        p = 0;
    }

    int update(int v) {
        while (s[sz(s) - t[v].len - 2] != s.back())
            v = t[v].link;
        return v;
    }

    void add(char c) {
        int i = ctoi(c);
        s.push_back(i);
        p = update(p);

        if (t[p].nxt[i] == 0) {
            t.emplace_back(t[update(t[p].link)].nxt[i], t[p].len + 2);
            t[p].nxt[i] = sz(t) - 1;
        }
        p = t[p].nxt[i];

        t[p].cnt++;
        t[p].pos = (sz(s) - 2);
    }

    void pushCnt() {
        for (int i = sz(t) - 1; i >= 2; i--)
            t[t[i].link].cnt += t[i].cnt;
    }
};

int pows[N + 1][2];

void precalc() {
    pows[0][0] = pows[0][1] = 1;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 2; j++)
            pows[i][j] = (pows[i - 1][j] * 1LL * P) % HMOD[j];
}

vector<int> hashes(const string &s, int id) {
    int n = sz(s);
    vector<int> res(n + 1);
    for (int i = n - 1; i >= 0; i--)
        res[i] = ((ctoi(s[i]) + 1) + P * 1LL * res[i + 1]) % HMOD[id];
    return res;
}

int shash(const vector<int> &hashes, int l, int r, int id) {
    int res = (hashes[l] - pows[r - l + 1][id] * 1LL * hashes[r + 1]) % HMOD[id];
    if (res < 0)
        res += HMOD[id];
    return res;
}

int binPow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = (res * 1LL * a) % MOD;
        a = (a * 1LL * a) % MOD;
        n >>= 1;
    }
    return res;
}

int inv(int x) {
    return binPow(x, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> ss(n);
    for (int i = 0; i < n; i++)
        cin >> ss[i];

    unordered_map<ll, pair<int, int>> mp;
    precalc();
    for (auto &s : ss) {
        Eertree et;
        for (auto c : s)
            et.add(c);
        et.pushCnt();

        auto hs0 = hashes(s, 0);
        auto hs1 = hashes(s, 1);
        for (int i = sz(et.t) - 1; i >= 2; i--) {
            auto v = et.t[i];
            int h0 = shash(hs0, v.pos - v.len + 1, v.pos, 0);
            int h1 = shash(hs1, v.pos - v.len + 1, v.pos, 1);
            ll h = h0 + HMOD[0] * 1LL * h1;
            int cnt = v.cnt;

            if (mp.find(h) == mp.end())
                mp[h] = {0, 1};

            mp[h].first++;
            mp[h].second = (mp[h].second * 1LL * cnt) % MOD;
        }
    }

    int p = 0;
    for (auto x : mp) {
        int cnt = x.second.first;
        int val = x.second.second;
        if (cnt == n)
            p = (p + val) % MOD;
    }

    int q = 1;
    for (auto &s : ss) {
        int m = sz(s);
        q = (q * 1LL * ((m * 1LL * (m + 1) / 2) % MOD)) % MOD;
    }

    int ans = (p * 1LL * inv(q)) % MOD;

    cout << ans << endl;
}
