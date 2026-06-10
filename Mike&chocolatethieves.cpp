#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cnt(ll n) {
    ll res = 0;
    for (ll i = 2; i * i * i <= n; i++) {
        res += n / (i * i * i);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll m;
    cin >> m;

    ll l = 1, r = 8000000000000000000LL;
    
    while (l < r) {
        ll mid = l + (r - l) / 2;

        if (cnt(mid) >= m)
            r = mid;
        else
            l = mid + 1;
    }

    if (cnt(l) == m)
        cout << l << '\n';
    else
        cout << -1 << '\n';

    return 0;
}
