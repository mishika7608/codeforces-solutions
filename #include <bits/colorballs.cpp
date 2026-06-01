#include <bits/stdc++.h>
using namespace std;

bool good(long long r, long long g, long long b, long long w) {
    int odd = (r & 1) + (g & 1) + (b & 1) + (w & 1);
    return odd <= 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long r, g, b, w;
        cin >> r >> g >> b >> w;

        bool ok = good(r, g, b, w);

        if (r > 0 && g > 0 && b > 0) {
            ok |= good(r - 1, g - 1, b - 1, w + 3);
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }

    return 0;
}
