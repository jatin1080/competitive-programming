#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// string solutionString = "";


int factorial(int n) {
    vector<int> A;
    if(n==0) return 1;
    A.push_back(1);
    for(int i=2; i<=n; i++) {
        A[i-1] = i * A[i-2];
    }
    return A[n-1];    
}


void kthPerm(vector<int> &A, int k, string &solutionString) {
    int n = A.size();
    if(k==0 || n==0) return;
    if(k<=0 || k>factorial(n)) return; // no solution exist
    // if(n==1) {
    //     solutionString.append(to_string(A[0]));
    //     return;
    // }

    // if(n==2) {
    //     solutionString.append(to_string(A[k-1]));
    //     A.erase(A.begin()+k-1);
    //     if(k==2) k -=1;
    //     kthPerm(A, k);
    //     return;
    // }
    
    int fact = factorial(n-1);
    // cout<<"fact:  "<<fact;

    int index;
    if(k%fact == 0) index = (k/fact) - 1;
    else index = k/fact;
    // cout<<" index:   "<<index;

    string nextNumber = to_string(A[index]);
    // cout<<"   nextNumber:  "<<nextNumber;

    A.erase(A.begin()+index);
    // cout<<endl;
    // for(int i: A) cout<<"A:"<<i<<"  ";
    // cout<<endl;

    solutionString += nextNumber;

    k -= (fact*index);

    kthPerm(A, k, solutionString);

    return;
}

/*
string nextNumber(vector<int> &A, int k) {
    int n = A.size();
    if(k==0 || n==0) return "";
    if(k<=0 || k>factorial(n)) return ""; // no solution exist
    if(n==1) return to_string(A[0]);

    int fact = factorial(n-1);
    int index = k/fact;
    string nextNum = to_string(A[index]);
    A.erase(A.begin()+index);

}
*/

int main() {

    vector<int> A{1,2,3,4,5,6,7};
    string solutionString = "";
    int k;
    cin>>k;
    kthPerm(A, k, solutionString);
    cout<<solutionString;
}