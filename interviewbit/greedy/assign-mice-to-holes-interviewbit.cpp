#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> A, vector<int>B) {
    int n = A.size();
    if(n==0) return 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int ans=abs(B[0]-A[0]);
    for(int i=0; i<n; i++) {
       if(ans<abs(B[i]-A[i])) ans = abs(B[i]-A[i]);
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
		
		cout<<solve(A, B)<<endl;
	}
    
    return 0;
}