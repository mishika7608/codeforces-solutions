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

    int len = pi[n - 1];

    while (len > 0) {

        bool found = false;

        // check middle occurrence
        for (int i = 0; i < n - 1; i++) {
            if (pi[i] == len) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << s.substr(0, len) << '\n';
            return 0;
        }

        len = pi[len - 1];
    }

    cout << "Just a legend\n";
}
