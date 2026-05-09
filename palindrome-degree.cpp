#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const ll MOD = 1000000007;
const ll BASE = 911382323;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    string s;
    cin >> s;
 
    int n = s.size();
 
    vector<ll> pw(n + 1), h(n + 1), rh(n + 1);
 
    pw[0] = 1;
 
    for (int i = 1; i <= n; i++)
        pw[i] = (pw[i - 1] * BASE) % MOD;
 
    // forward hash
    for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] * BASE + s[i]) % MOD;
 
    string rev = s;
    reverse(rev.begin(), rev.end());
 
    // reverse hash
    for (int i = 0; i < n; i++)
        rh[i + 1] = (rh[i] * BASE + rev[i]) % MOD;
 
    auto getHash = [&](vector<ll> &H, int l, int r) {
        return (H[r + 1] - H[l] * pw[r - l + 1] % MOD + MOD) % MOD;
    };
 
    vector<int> dp(n);
 
    ll ans = 0;
 
    for (int i = 0; i < n; i++) {
 
        // check if prefix [0..i] is palindrome
        ll h1 = getHash(h, 0, i);
 
        // corresponding reversed segment
        ll h2 = getHash(rh, n - 1 - i, n - 1);
 
        if (h1 == h2) {
            dp[i] = 1;
 
            if (i > 0)
                dp[i] += dp[(i - 1) / 2];
        }
 
        ans += dp[i];
    }
 
    cout << ans << '\n';
 
    return 0;
}
