#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// unordered_map<int, int> umap;
// int sum = 0, maxLen = 0;
// umap.insert({0,-1});
// for (int i=0; i<A.size(); i++) {
//     sum += A[i] ? A[i] : -1;
//     if (umap.find(sum - 1) != umap.end())
//     maxLen = max(maxLen, i-umap[sum-1]);
//     if(umap.find(sum) == umap.end())
//     umap[sum] = i;
// }
// return maxLen;
int solve(vector<int> &A) {
    int n = A.size();
    int maxlen = 0;
    unordered_map<int, int> M; // mapping of number of ones to len of subarray
    for (int i=0; i<n; i++) {
        int ones = 0;
        int zeroes = 0;
        for (int j=i; j<n; j++) {
            if (A[j]==1) ones++;
            else zeroes++;
            if (ones>zeroes) {
               if (M.find(j-i+1)!=M.end() && M[j-i+1]<ones) M[j-i+1] = ones;
               else M[j-i+1] = ones;
            }
        }
    }

    for (auto p: M) {
        std::cout<< "p:"<<p.first<<" "<<p.second<<'\n';
        if (p.first > maxlen) maxlen = p.first;
    }
    return maxlen;
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