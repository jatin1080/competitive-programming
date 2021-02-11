#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &A) {
    int n = A.size();
    unordered_map<int, int> B;
    int minIndex = INT_MAX;
    for (int i=0; i<n; i++) {
        if (B.find(A[i])!=B.end()) {
            if (minIndex > B[A[i]]) minIndex = B[A[i]];
        }
        else B[A[i]] = i;
    }
    if (minIndex != INT_MAX) return A[minIndex];
    return -1;
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

        int ans = solve(A);
		cout<<"answer "<<t<<": "<<ans<<endl;
	}

    return 0;
}