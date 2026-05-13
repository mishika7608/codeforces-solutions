#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    vector<int> pi(n);

    // KMP prefix function
    for (int i = 1; i < n; i++) {

        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;

        pi[i] = j;
    }

    // cnt[len] = how many times prefix of length len appears
    vector<int> cnt(n + 1, 0);

    // every pi[i] contributes one occurrence
    for (int i = 0; i < n; i++) {
        cnt[pi[i]]++;
    }

    // propagate counts upwards
    for (int i = n; i > 0; i--) {
        cnt[pi[i - 1]] += cnt[i];
    }

    // every prefix appears at least once (itself)
    for (int i = 1; i <= n; i++) {
        cnt[i]++;
    }

    vector<pair<int,int>> ans;

    int cur = n;

    // collect all borders
    while (cur > 0) {

        ans.push_back({cur, cnt[cur]});

        cur = pi[cur - 1];
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';

    for (auto &[len, freq] : ans) {
        cout << len << " " << freq << '\n';
    }
}
