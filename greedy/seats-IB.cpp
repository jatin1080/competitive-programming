#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(string A) {
    int n = A.length();
    if(n<=1) return 0;
    long long ans = -1;

    int p=0;
    for(char ch: A) {
        if(ch == 'x') p++;        
    }
    
    int m = p/2 + 1;
    // cout<<endl<<"m: "<<m<<endl;
    int midpos = -1;
    for(int i=0; i<n; i++) {
        if(A[i]=='x') m--;
        if(m==0) {
            midpos = i;
            break;
        }
    }

    int start = midpos - p/2;
    int end = midpos + p/2 - 1;

    ans = 0;
    int person=0;
    for(int j=0; j<n; j++) {
        char c = A[j];
        if(c=='x') {
            person++;
            int seat = start + person - 1;
            int diff = abs(j-seat);
            ans += diff;
        }
    }

    return ans%10000003;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int T;
	cin>>T;
	for(int t=1; t<=T; t++) {
		int x;
		cin>>x;

		string A;
		for(int i=0; i<x; i++) {
			char val;
			cin>>val;
			A+=val;
		}
		
		cout<<solve(A);
	}
    
    return 0;
}