#include <bits/stdc++.h>

using namespace std;

int trailingZeros(int number) {
	int ans = 0;
	// int powerOfFive = 5;
	int addToAns = number/5;

	while(addToAns) {
		ans += addToAns;
		// powerOfFive *=5;
		addToAns /= 5;
	}

	return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
	int T, N;
	cin>>T;

	for(int t=1; t<=T; t++) {
		cin>>N;
		cout<<trailingZeros(N)<<endl;
	}

	return 0;

}