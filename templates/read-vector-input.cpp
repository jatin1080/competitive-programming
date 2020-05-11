#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> A) {
	return A.size();
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
    
    return 0;
}