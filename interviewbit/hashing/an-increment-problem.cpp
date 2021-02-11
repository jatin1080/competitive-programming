#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> A) {
    int n = A.size();
    vector<int> ret;
    unordered_map<int, int> M; //stores the index of first occurence of that element
    for (int i=0; i<n; i++) {
        int x = A[i];
        ret.push_back(x);
        if (M.find(x)!=M.end()) {
            int index = M[x];
            ret[index]++;
            int val = ret[index];
            if (M.find(val)!=M.end()) {
                int index1 = M[val];
                if(index<index1) M[val]=index;
            }
            else {
                M[val] = index;
                // M[x] has to change
            }
            for (int j=0; j<ret.size(); j++) {
                if (ret[j] == x) {
                    M[x]=j;
                    break;
                }
            }
        }
        else {
            M.insert({x,i});
        }
        // cout<<"printing ret: ";
        // for (auto r: ret) cout << r << " ";
        // cout<<"printing M: ";
        // for (auto m: M) cout << m.first << " " << m.second << ", ";
        // cout<<endl;
    }
	return ret;
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

        vector<int> ans = solve(A);

		cout<<"answer "<<t<<": ";
        for (int x: ans) {
            cout<<x<<" ";
        }
        cout<<"\n\n";
	}

    return 0;
}