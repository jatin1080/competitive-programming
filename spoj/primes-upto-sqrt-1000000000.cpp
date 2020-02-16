#include <iostream>
#include <bits/stdc++.h>

using namespace std;

std::vector<bool> sieveOfErastothenes(int number) {
	
	std::vector<bool> v(number+1, true);

	v[0] = false;
	v[1] = false;

	for(int j=2; j<=sqrt(number)+1; j++) {
	 	if(!v[j]) continue;

		else {			
	 		for(int k=j+j; k<=number; k+=j) {
	 			v[k] = false;
	 		} 			
 		}
 	}

	return v;
}


int main() {

	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int num = sqrt(1000000000) + 1;
	
	std::vector<bool> primes = sieveOfErastothenes(num);

	for(int x=0; x<=num; x++) {
		if(primes[x]) cout<<x<<",";
	}

	return 0;
}

