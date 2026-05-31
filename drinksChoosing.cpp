#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> cnt(k + 1, 0);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int m = (n + 1) / 2;

    vector<int> dp(m + 1, -1000000);
    dp[0] = 0;

    for (int drink = 1; drink <= k; drink++) {
        vector<int> ndp(m + 1, -1000000);

        for (int used = 0; used <= m; used++) {
            if (dp[used] < 0) continue;

            for (int sets = 0; used + sets <= m; sets++) {
                ndp[used + sets] =
                    max(
                        ndp[used + sets],
                        dp[used] + min(cnt[drink], 2 * sets)
                    );
            }
        }

        dp.swap(ndp);
    }

    cout << dp[m] << '\n';
    return 0;
}
