#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--){
	    int n,m,k;
	    cin >> n >> m >> k;
	    int points=0;
	    int eachPlayer=n/k;
	    if (eachPlayer>=m){cout << m<< endl;continue;}
	    else if(m>eachPlayer){m-=eachPlayer;k--;cout << eachPlayer-(ceil((m+k-1)/k))<<endl;continue;}
	}
    return 0;
}
