#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> A) {
    int n = A.size();

    if(n==0) return -1;
    if(n==1) return A[0];

    int ans = A[0];
    int count=1;

    for(int i=1; i<n; i++) {
        if(A[i]==ans) count++;
        else {
            count--;
            if(count==0) {
                ans = A[i];
                count=1;
            }
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