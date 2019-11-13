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

struct Event {
    int t, s, id;

    bool operator <(const Event &rhs) const {
        return make_pair(t, s) < make_pair(rhs.t, rhs.s);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];

    vector<Event> events;
    for (int i = 0; i < n; i++) {
        events.push_back({l[i], 0, i});
        events.push_back({r[i], 1, i});
    }
    sort(all(events));

    vector<int> ans;
    set<pair<int, int>> s;
    for (int i = 0; i < sz(events); ) {
        if (events[i].s == 1) {
            s.erase({-r[events[i].id], events[i].id});
            i++;
            continue;
        }

        int j = i;
        while (j < sz(events) && events[j].t == events[i].t && events[j].s == 0) {
            s.insert({-r[events[j].id], events[j].id});
            j++;
        }
        i = j;

        while (sz(s) > k) {
            auto e = *(s.begin());
            ans.push_back(e.second);
            s.erase(s.begin());
        }
    }
    sort(all(ans));

    cout << sz(ans) << endl;
    for (auto x : ans)
        cout << (x + 1) << ' ';
    cout << endl;
}
