#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// two vectors of same length

int solve(vector<int> A, vector<int>B) {
    int n = A.size();
	// cout<<endl<<"n: "<<n<<endl;
	if(n==0) return -1;
	if(n==1) return 0;
	
	int available = 0;
	int required = 0;
	for(int k=0; k<n; k++) {
		available +=A[k];
		required += B[k];
	}
	if(available<required) return -1;

	int ans = -1;
	for(int i=0; i<n; i++) {
		// cout<<endl<<"i: "<<i<<endl;
		int fuel=0;
		bool circuit = true;
		for(int j=0; j<n; j++) {
			int index = (i+j)%n;
			// cout<<endl<<"index: "<<index<<endl;
			fuel += A[index];
			int req = B[index];
			// cout<<endl<<"fuel: "<<fuel<<endl;
			// cout<<endl<<"req: "<<req<<endl;

			if(req>fuel) {
				circuit = false;
				i = index;
				break;
			}
			else fuel-=req;

			// cout<<endl<<"fuel: "<<fuel<<endl;

		}

		// cout<<endl<<"circuit: "<<circuit<<endl;
		if(circuit) {
			ans = i;
			break;
		}
	}

	return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int T;
	cin>>T;
	for(int t=1; t<=T; t++) {
		int x;
		cin>>x;

		vector<int>A;
		for(int i=0; i<x; i++) {
			int val;
			cin>>val;
			A.push_back(val);
		}

		vector<int>B;
		for(int i=0; i<x; i++) {
			int val;
			cin>>val;
			B.push_back(val);
		}
		
		cout<<solve(A, B);
	}
    
    return 0;
}