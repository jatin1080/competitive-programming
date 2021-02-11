#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> combinationSum(vector<int> &A, int B) {
    
    vector<vector<int>> E ;
    
    if(B<=0 || B<A[0]) return E;
    
    for(int i: A) {
        if(B==i) {
            vector<int> F{i};
            E.push_back(F);
        }
        else {
            vector<vector<int>> G = combinationSum(A, B-i);

            for(int g=0; g<G.size(); g++) {
                if(i<=G[g][0]) {
                    G[g].insert(G[g].begin(), i);
                    E.push_back(G[g]);
                }
            }
        }
    }

    return E;

}


int main() {
    vector<int> A{1, 2, 3};
    int B = 5;

    vector<vector<int>> ans = combinationSum(A, B);

    for(vector<int> v: ans) {
        cout<<"[ ";
        for(int i: v) {
            cout<<i<<", ";
        }
        cout<<"]"<<endl;
    }

}