#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int>A) {
	int n = A.size();
	if (n<3) return -1;

	int highest;

	sort(A.begin(), A.end());

	if(A[n-1]<0) // if we only have negatives and zero
	{
		highest = A[n-1]*A[n-2]*A[n-3];
	}
	else {
		if(A[0]*A[1]>A[n-2]*A[n-3]) highest = A[n-1]*A[0]*A[1];
		else highest = A[n-1]*A[n-2]*A[n-3];
	}

	return highest;
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
		
		cout<<solve(A)<<endl;
	}
	
	// vector<int> A{1, 2, 3, 4, 5, 6, 7};
	// vector<int> B{1, 2, -1};
	// vector<int> C{1, 2, 3, 4, 5, -1, -2};
	// vector<int> D{1, 2, 3, 4, 5, 6, 7, -1, -2, -3, -40, 0};
	
	// cout<<solve(A)<<endl;    
	// cout<<solve(B)<<endl;    
	// cout<<solve(C)<<endl;    
	// cout<<solve(D)<<endl;    
    return 0;
}