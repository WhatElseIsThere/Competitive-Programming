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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    deque<int> deq;
    set<int> s;

    for (int i = 0; i < n; i++) {
        if (s.find(a[i]) != s.end())
            continue;
        if (sz(deq) == k) {
            s.erase(deq.back());
            deq.pop_back();
        }
        deq.push_front(a[i]);
        s.insert(a[i]);
    }

    cout << sz(deq) << endl;
    for (auto x : deq)
        cout << x << ' ';
    cout << endl;
}
