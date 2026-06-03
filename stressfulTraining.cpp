#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, k;
vector<ll> a;
vector<ll> b;

bool check(ll x) {
    priority_queue<pair<ll,int>,
                   vector<pair<ll,int>>,
                   greater<pair<ll,int>>> pq;

    vector<ll> cur = a;

    for (int i = 0; i < n; i++) {
        ll d = cur[i] / b[i] + 1;

        if (d < k) {
            pq.push({d, i});
        }
    }

    for (int t = 0; t < k; t++) {
        if (pq.empty()) return true;

        auto [d, id] = pq.top();
        pq.pop();

        if (d <= t) return false;

        cur[id] += x;

        ll nd = cur[id] / b[id] + 1;

        if (nd < k) {
            pq.push({nd, id});
        }
    }

    return pq.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll lo = 0, hi = 10000000000000LL;
    ll ans = -1;

    while (lo <= hi) {
        ll mid = (lo + hi) >> 1;

        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
