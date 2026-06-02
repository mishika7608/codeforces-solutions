#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long energy = 0;
    long long ans = 0;
    long long prev = 0;

    for (int i = 0; i < n; i++) {
        long long h;
        cin >> h;

        if (h > prev) {
            long long need = h - prev;

            if (energy >= need) {
                energy -= need;
            } else {
                ans += need - energy;
                energy = 0;
            }
        } else {
            energy += prev - h;
        }

        prev = h;
    }

    cout << ans << '\n';
    return 0;
}
