#include<iostream>
#include<bits/stdc++.h>

using namespace std;



vector<vector<vector<string>>> solutions;

void foundASolution(vector<vector<string>> sol) {
    solutions.push_back(sol);
}

void findSolution(vector<vector<string>> currentState, int index, int n) {
    if(index == n) {
        foundASolution(currentState);
        return;
    }
    vector<vector<string>> savedState = currentState;
    bool vacancyForQueen = false;

    // find all the places to put the queen in this row
    vector<int> placesAvailble;
    for(int x; x<n; x++) {
        if(currentState[index][x]=="_") placesAvailble.push_back(x);
    }

    if(placesAvailble.size()) vacancyForQueen = true;
    else return; // if vacancyforqueen is not there then no solution exist

    //put the queen at each place one by one

    for(int x=0; x<placesAvailble.size(); x++) {
        int i = placesAvailble[x];
        currentState[index][i] = "Q";
        for(int j=i+1; j<n; j++) {
            currentState[index][j] = ".";
        }
        for(int k=index+1; k<n; k++) {
            currentState[k][i] = ".";
        }
        for(int l=1; l<n; l++) {
            if(i+l<n && index+l<n) currentState[index+l][i+l] = ".";
            else break;
        }
    }
    

    if(vacancyForQueen)findSolution(currentState, index+1, n);

    return;    
}

vector<vector<string>> nQueens(int n) {
    vector<string> A(n, "_");
    vector<vector<string>> V(n,A);

    // V[0][1] = "Q";

    findSolution(V, 0, 2);

    return V;
}


int main() {
    int n = 2;
    // cin>>n;

    vector<vector<string>> ans;

    ans = nQueens(n);

    // for(vector<string> v: ans) {
    //     cout<<"[ ";
    //     for(string i: v) {
    //         cout<<i<<", ";
    //     }
    //     cout<<"]"<<endl;
    // }



    for(vector<vector<string>> vec: solutions) {
        for(vector<string> v: vec) {
            cout<<"[ ";
            for(string i: v) {
                cout<<i<<", ";
            }
            cout<<"]"<<endl;
        }
    }
}


// second approach 
/*
int factorial(int n) {
    return (n==0 || n==1) ? n : (n*factorial(n-1));
}

int main() {
    int n =2;

    vector<string> A(n, "_");
    vector<vector<string>> V(n, A);
    int times = factorial(n);

    for(int i=0; i<n; i++) {
        vector<vector<string>> B(V.begin(), V.end());
        for(int j=0; j<n; j++) {
            
        }
    }

}
*/