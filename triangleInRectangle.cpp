#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long w, h;
        cin >> w >> h;

        long long ans = 0;

        for (int side = 0; side < 2; side++) {
            int k;
            cin >> k;

            vector<long long> x(k);
            for (int i = 0; i < k; i++) cin >> x[i];

            ans = max(ans, (x.back() - x.front()) * h);
        }

        for (int side = 0; side < 2; side++) {
            int k;
            cin >> k;

            vector<long long> y(k);
            for (int i = 0; i < k; i++) cin >> y[i];

            ans = max(ans, (y.back() - y.front()) * w);
        }

        cout << ans << '\n';
    }

    return 0;
}
