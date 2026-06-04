#include <bits/stdc++.h>
using namespace std;

long long valCalc(int n){
    long long val=1;
    while (n>0){
        val*=2;
        n--;
    }
    return val;
}

int main() {
	int n;
	cin >> n;
	cout << valCalc(n+1)-2;
    return 0;
}
