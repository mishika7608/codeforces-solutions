#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {

        int n, m, x;
        cin >> n >> m >> x;

        vector<int> h(n);

        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }

        // {current height, tower index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // initially all towers height = 0
        for (int i = 1; i <= m; i++) {
            pq.push({0, i});
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            auto [height, idx] = pq.top();
            pq.pop();

            ans[i] = idx;

            height += h[i];

            pq.push({height, idx});
        }

        cout << "YES\n";

        for (int x : ans) {
            cout << x << " ";
        }

        cout << '\n';
    }

    return 0;
}
