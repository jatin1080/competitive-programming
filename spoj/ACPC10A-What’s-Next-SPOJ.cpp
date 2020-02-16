#include <bits/stdc++.h>

using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
    int A, B, C;
    cin>>A;
    cin>>B;
    cin>>C;

    while(A || B || C) {
    	// AP or GP
    	if((B - A) == (C - B)) {
    		int n = C + (C - B);
    		cout<<"AP "<<n<<endl;
    	}
    	else {
    		int n = C*(C/B);
    		cout<<"GP "<<n<<endl;
    	}
	
	    cin>>A;
	    cin>>B;
	    cin>>C;
    }

	return 0;

}