#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
	int T, X, Y;
	cin>>T;

	for(int t=1; t<=T; t++) {
		cin>>X;
		cin>>Y;

		int x = X;
		int y = Y;
		int number = -1;
		if(x==y) {
			if(x%2==0) number = 4 * (x/2);
			else number = 4 * (x/2) + 1; 

			cout<<number<<endl;
		}
		else if(x==y+2) {
			if(x%2==0) number = 4 * ((x/2) - 1) + 2;
			else number = 4 * ((x/2) - 1) + 3; 			
			cout<<number<<endl;
		}
		else cout<<"No Number"<<endl;
	}

	return 0;

}