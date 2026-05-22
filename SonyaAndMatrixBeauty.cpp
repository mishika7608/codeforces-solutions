#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 255;
const ull BASE = 911382323ull;

int n, m;
string s[N];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }

    ll ans = 0;

    // Fix left column
    for (int L = 1; L <= m; L++) {

        vector<array<int,26>> freq(n + 1);

        // Extend right column
        for (int R = L; R <= m; R++) {

            vector<ull> h(n + 1);
            vector<int> good(n + 1);

            // Build hashes
            for (int i = 1; i <= n; i++) {

                freq[i][s[i][R] - 'a']++;

                int odd = 0;
                ull cur = 0;

                for (int c = 0; c < 26; c++) {

                    odd += (freq[i][c] & 1);

                    cur = cur * BASE + (ull)(freq[i][c] + 1);
                }

                h[i] = cur;

                good[i] = (odd <= 1);
            }

            // ---------- ODD PALINDROMES ----------

            vector<int> d1(n + 1);

            int l = 1, r = 0;

            for (int i = 1; i <= n; i++) {

                int k;

                if (i > r)
                    k = 1;
                else
                    k = min(d1[l + r - i], r - i + 1);

                while (
                    i - k >= 1 &&
                    i + k <= n &&
                    good[i - k] &&
                    good[i + k] &&
                    h[i - k] == h[i + k]
                ) {
                    k++;
                }

                d1[i] = k;

                if (!good[i])
                    d1[i] = 0;

                if (i + k - 1 > r) {
                    l = i - k + 1;
                    r = i + k - 1;
                }

                ans += d1[i];
            }

            // ---------- EVEN PALINDROMES ----------

            vector<int> d2(n + 1);

            l = 1;
            r = 0;

            for (int i = 1; i <= n; i++) {

                int k;

                if (i > r)
                    k = 0;
                else
                    k = min(d2[l + r - i + 1], r - i + 1);

                while (
                    i - k - 1 >= 1 &&
                    i + k <= n &&
                    good[i - k - 1] &&
                    good[i + k] &&
                    h[i - k - 1] == h[i + k]
                ) {
                    k++;
                }

                d2[i] = k;

                if (i + k - 1 > r) {
                    l = i - k;
                    r = i + k - 1;
                }

                ans += d2[i];
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
