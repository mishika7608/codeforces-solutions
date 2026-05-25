#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {
    long long n;
    cin >> n;

    // If n is prime
    if (isPrime(n)) {
        cout << 1 << endl;
    }
    // If n is even OR n-2 is prime
    else if (n % 2 == 0 || isPrime(n - 2)) {
        cout << 2 << endl;
    }
    // Otherwise answer is 3
    else {
        cout << 3 << endl;
    }

    return 0;
}
