#include<bits/stdc++.h>
#include "../../common/lib/printlib.cpp"

using namespace std;

int algo(vector<int> &A, int start, int end) {
    // cout<<"start: "<<start<<" end: "<<end<<endl;
    if (start>=end) return 1;
    int first = A[start];
    int index = start;
    for (int i = start+1; i<=end; i++) {
        if (A[i]>first) { index = i; break; }
    }
    // cout<<"first: "<<first<<" index: "<<index<<" A[index]:"<<A[index]<<endl;

    if (index==start) index = end+1; // since there is no right subtree
    int validBST = 1;
    for (int i = index; i<=end; i++) {
        if (A[i]<=first) validBST = 0;
    }
    if (validBST==0) return 0;
    int left = algo(A, start+1, index-1);
    int right = algo(A, index, end);
    // cout<<"start: "<<start<<" end: "<<end<<" left: "<<left<<" right:"<<right<<endl;
    if (left && right) return 1;
    else return 0;
}

// psedocode
// for any root, once you start on the right side of it the element cannot be lesser than the root itself
// this root is the root when there is no right subtree of the immediate subtree of the root
int algo_2(vector<int> &A) {
    stack<int>s;
    int root=INT_MIN;
    for(int i=0;i<A.size();i++){
        if(A[i]<root)   return false;
        while(!s.empty()&&A[i]>s.top()){
            root=s.top();
            s.pop();
        }
        s.push(A[i]);
    }
    return true;
}

int solve(vector<int> &A) {
    // int ans = algo(A, 0, A.size()-1);
    int ans = algo_2(A);
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

        auto ans = solve(A);
		cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
	}

    return 0;
}