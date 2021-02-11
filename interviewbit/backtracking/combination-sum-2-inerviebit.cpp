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

vector<vector<int>> combinationSum2(vector<int> &A, int B) {
    
    vector<vector<int>> C;

    if(B<=0 || B<A[0]) return C;

    for(int i=0; i<A.size(); i++) {
        if(B==A[i]) {
            vector<int> D{A[i]};
            C.push_back(D);
        }
        else {
            if(i>0 && A[i]==A[i-1]) continue;
            vector<int> E(A.begin(), A.end());
            E.erase(E.begin()+i);
            vector<vector<int>> F = combinationSum2(E, B-A[i]);

            for(int j=0; j<F.size(); j++) {
                if(A[i]<=F[j][0]) {
                    F[j].insert(F[j].begin(), A[i]);
                    // if(isEqual(C[C.size()-1], F[j])) continue;
                    C.push_back(F[j]);
                }
            }
        }
    }

    return C;

}


int main() {
    vector<int> A{13, 10, 15, 5, 3, 8};
    int B = 22;


    sort(A.begin(), A.end());

    vector<vector<int>> ans = combinationSum2(A, B);

    vector<vector<int>> finalAns;
    if(ans.size())finalAns.push_back(ans.front());
    for(vector<int> v: ans) {
        if(!isEqual(finalAns.back(),v)) finalAns.push_back(v);
    }

    for(vector<int> v: ans) {
        cout<<"[ ";
        for(int i: v) {
            cout<<i<<", ";
        }
        cout<<"]"<<endl;
    }

}