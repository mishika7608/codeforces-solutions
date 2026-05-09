#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    string s, t;
    cin >> s >> t;

    vector<int> occ(n + 1, 0);

    // check all occurrences
    for (int i = 0; i + m <= n; i++) {

        bool ok = true;

        for (int j = 0; j < m; j++) {
            if (s[i + j] != t[j]) {
                ok = false;
                break;
            }
        }

        if (ok)
            occ[i + 1] = 1; // 1-based
    }

    vector<int> pref(n + 1, 0);

    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + occ[i];

    while (q--) {

        int l, r;
        cin >> l >> r;

        if (r - l + 1 < m) {
            cout << 0 << '\n';
            continue;
        }

        int right = r - m + 1;

        cout << pref[right] - pref[l - 1] << '\n';
    }

    return 0;
}
