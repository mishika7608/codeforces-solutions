#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    long long x, y;
    cin >> x >> y;

    vector<long long> px(n + 1, 0), py(n + 1, 0);

    for (int i = 0; i < n; i++) {
        px[i + 1] = px[i];
        py[i + 1] = py[i];

        if (s[i] == 'U') py[i + 1]++;
        else if (s[i] == 'D') py[i + 1]--;
        else if (s[i] == 'L') px[i + 1]--;
        else px[i + 1]++;
    }

    auto can = [&](int len) -> bool {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len;

            long long curX =
                px[n] - (px[r] - px[l]);

            long long curY =
                py[n] - (py[r] - py[l]);

            long long d =
                llabs(x - curX) +
                llabs(y - curY);

            if (d <= len && ((len - d) % 2 == 0))
                return true;
        }
        return false;
    };

    long long totalDist = llabs(x) + llabs(y);

    if (totalDist > n) {
        cout << -1 << '\n';
        return 0;
    }

    int lo = 0, hi = n;
    int ans = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (can(mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
