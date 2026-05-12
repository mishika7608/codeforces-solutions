#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int cnt0 = 0, cnt1 = 0;

    for (char c : s) {
        if (c == '0') cnt0++;
        else cnt1++;
    }

    int need0 = 0, need1 = 0;

    for (char c : t) {
        if (c == '0') need0++;
        else need1++;
    }

    // cannot build even one t
    if (need0 > cnt0 || need1 > cnt1) {
        cout << s << '\n';
        return 0;
    }

    // KMP prefix function
    int n = t.size();

    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {

        int j = pi[i - 1];

        while (j > 0 && t[i] != t[j])
            j = pi[j - 1];

        if (t[i] == t[j])
            j++;

        pi[i] = j;
    }

    int overlap = pi[n - 1];

    string add = t.substr(overlap);

    string ans = t;

    cnt0 -= need0;
    cnt1 -= need1;

    int add0 = 0, add1 = 0;

    for (char c : add) {
        if (c == '0') add0++;
        else add1++;
    }

    // keep appending overlap suffix
    while (cnt0 >= add0 && cnt1 >= add1) {

        ans += add;

        cnt0 -= add0;
        cnt1 -= add1;
    }

    // append remaining chars
    ans += string(cnt0, '0');
    ans += string(cnt1, '1');

    cout << ans << '\n';
}
