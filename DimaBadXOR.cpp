#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> ans(n, 1); // choose first column initially
    int xr = 0;

    for (int i = 0; i < n; i++) {
        xr ^= a[i][0];
    }

    if (xr != 0) {
        cout << "TAK\n";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (a[i][j] != a[i][0]) {
                ans[i] = j + 1; // switch this row
                cout << "TAK\n";
                for (int k = 0; k < n; k++) {
                    cout << ans[k] << ' ';
                }
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "NIE\n";
    return 0;
}
