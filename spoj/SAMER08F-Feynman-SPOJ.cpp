#include <bits/stdc++.h>

using namespace std;

int summationSquares(int n, std::vector<int> summation) {
	if(n<summation.size()) return summation[n];
	else {
		int lastIndex = summation.size()-1;
		for(int i = lastIndex+1; i<=n; i++) summation.push_back(summation[i-1] + (i*i));
	}
	
	return summation[n];
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    std::vector<int> summation{0,1};
    int N;
    cin>>N;

    while(N) {
    	cout<<summationSquares(N, summation)<<endl;
    	cin>>N;
    }

	return 0;

}