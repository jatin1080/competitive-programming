#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// two vectors of same length

int solve(vector<int> A, vector<int>B) {
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