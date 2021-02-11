#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets2(vector<int> &A) {
    vector<vector<int>> B;

    if(A.size()==0) return B;

    if(A.size()==1) {
        vector<int> D;
        vector<int> C{A[0]};
        B.push_back(D);
        B.push_back(C);
    }
    else {

        vector<int> E(A.begin()+1, A.end());
        vector<vector<int>> F = subsets2(E);
        B.push_back(F[0]);

        for(int i=0; i<F.size(); i++) {
            vector<int> y = F[i];
            y.insert(y.begin(), A[0]);
            B.push_back(y);
        }

        for(vector<int> v: F) {
            if(v.size()) B.push_back(v);
        }
    }

    return B;
}

int main() {
    vector<int> A{1,2};


    sort(A.begin(), A.end());

    vector<vector<int>> ans = subsets2(A);

    for(vector<int> v: ans) {
        cout<<"[ ";
        for(int i: v) {
            cout<<i<<", ";
        }
        cout<<"]"<<endl;
    }
}