#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> A) {
    int n = A.size();
    if(n<=1) return n;

    vector<int> B(A.begin(), A.end());
    vector<int> answer(n, 0);

    // find minimum and add that to every val
    int min = INT_MAX;
    for(int x: B) if(x<min) min = x;
    // cout<<endl<<"min: "<<min<<endl;
    if(min<0) min--;
    else min = 0;
    for(int i=0; i<n; i++) {
        B[i]+=abs(min);
    }

    // cout<<endl<<"vector B: "<<endl;
    // for(int y: B) {
    //     cout<<"\t"<<y;
    // }
    // cout<<endl;

    int peopleRemaining = n;
    int ans = 0;

    while (peopleRemaining>0)
    {
        vector<int> C(B.begin(), B.end());
        for(int i=0; i<n; i++) {
            
            // cout<<endl;
            // for(int y: B) {
            //     cout<<"\t"<<y;
            // }
            // cout<<endl;

            int rating = B[i];            
            int left = (i!=0) ? B[i-1] : -1;            
            int right = (i!=n-1) ? B[i+1] : -1;

            // cout<<endl<<"rating: "<<rating<<endl;
            // cout<<endl<<"left: "<<left<<endl;
            // cout<<endl<<"right: "<<right<<endl;

            if(rating>0) {
                bool remove = false;
                ans++;
                answer[i]++;
                if(left==-1) {
                    if(right==-1 || right>=rating) remove = true;
                }
                else if(right==-1) {
                    if(left==-1 || left>=rating) remove = true;
                }
                else {
                    if(rating<=left && rating<=right) remove = true;
                }

                if(remove) {
                    // cout<<endl<<"remve: "<<remove<<endl;
                    C[i] = -1;
                    peopleRemaining--;
                }
            }
        }

        B.clear();
        B = C;
        // cout<<endl<<"ending iteration"<<endl;
        // for(int y: B) {
        //     cout<<"\t"<<y;
        // }
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