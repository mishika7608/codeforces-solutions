#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;

    vector<ll> a(n), b(w);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < w; i++)
        cin >> b[i];

    // special case
    if (w == 1) {
        cout << n << '\n';
        return 0;
    }

    vector<ll> text, pattern;

    // difference arrays
    for (int i = 1; i < n; i++)
        text.push_back(a[i] - a[i - 1]);

    for (int i = 1; i < w; i++)
        pattern.push_back(b[i] - b[i - 1]);

    int m = pattern.size();

    // KMP prefix function
    vector<int> pi(m, 0);

    for (int i = 1; i < m; i++) {

        int j = pi[i - 1];

        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];

        if (pattern[i] == pattern[j])
            j++;

        pi[i] = j;
    }

    // KMP matching
    int ans = 0;
    int j = 0;

    for (int i = 0; i < text.size(); i++) {

        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];

        if (text[i] == pattern[j])
            j++;

        if (j == m) {
            ans++;
            j = pi[j - 1];
        }
    }

    cout << ans << '\n';
}
