#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isEqual(vector<int> &A, vector<int> &B) {
    if(A.size() != B.size()) return false;
    else {
        for(int i=0; i<A.size(); i++) {
            if(A[i]!=B[i]) return false;            
        }
        return true;
    }
    return true;
}

vector<vector<int>> subsets2(vector<int> &A) {
    vector<vector<int>> B;

    if(A.size()==0) return B;

    if(A.size()==1) {
        vector<int> D;
        vector<int> C{A[0]};
        B.push_back(D);
        B.push_back(C);
        // bool isThere = false;
        // for(int k=0; k<B.size(); k++) {
        //     isThere = isEqual(B[k],C);
        //     if(isThere) break;
        // }
        // if(!isThere) B.push_back(C);
    }
    else {

        vector<int> E(A.begin()+1, A.end());
        vector<vector<int>> F = subsets2(E);
        B.push_back(F[0]);

        for(int i=0; i<F.size(); i++) {
            vector<int> y = F[i];
            y.insert(y.begin(), A[0]);
            B.push_back(y);
            // bool isThere = false;
            // for(int k=0; k<B.size(); k++) {
            //     isThere = isEqual(B[k],y);
            //     if(isThere) break;            
            // }
            // if(!isThere) B.push_back(y);
        }

        for(vector<int> v: F) {
            if(v.size()) B.push_back(v);
            // bool isThere = false;
            // for(int k=0; k<B.size(); k++) {
            //     isThere = isEqual(B[k],v);
            //     if(isThere) break;
            // }
            // if(v.size() && !isThere) B.push_back(v);
        }
    }

    vector<vector<int>> V;
    for(int i=0; i<B.size(); i++) {
        bool isThere = false;
        for(int k=0; k<V.size(); k++) {
            isThere = isEqual(V[k], B[i]);
            if(isThere) break;
        }
        if(!isThere) V.push_back(B[i]);
    }

    return V;
}

int main() {
    vector<int> A{2,2,2,1,2,2,2};


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