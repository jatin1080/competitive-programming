#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> A) {
    if(A.size()==0) return 0;
    int currentVal = A[0];
	int ans = 0;
    if(!currentVal) ans = 1;
    for(int x: A) {
        if(x!=currentVal) {
            ans++;
            currentVal = x;
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
		
		cout<<solve(A)<<endl;
	}
    
    return 0;
}