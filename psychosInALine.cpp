#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    stack<pair<int,int>> st;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int days = 0;

        while (!st.empty() && a[i] > st.top().first) {
            days = max(days, st.top().second);
            st.pop();
        }

        if (st.empty()) {
            days = 0;
        } else {
            days += 1;
        }

        ans = max(ans, days);

        st.push({a[i], days});
    }

    cout << ans << '\n';

    return 0;
}
