#include<iostream>
#include<bits/stdc++.h>

using namespace std;



vector<vector<vector<string>>> solutions;

void foundASolution(vector<vector<string>> &sol) {
    solutions.push_back(sol);
}

void findSolution(vector<vector<string>> &currentState, int index, int n) {
    if(index >= n) {
        vector<vector<string>> sol(currentState.begin(), currentState.end());
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(sol[i][j]=="_") sol[i][j] = ".";
            }
        }
        foundASolution(sol);
        return;
    }

    // find all the places to put the queen in this row
    vector<int> placesAvailble;
    for(int x=0; x<n; x++) {
        if(currentState[index][x]=="_") placesAvailble.push_back(x);
    }

    if(!placesAvailble.size()) return;  

    //put the queen at each place one by one
    for(int x=0; x<placesAvailble.size(); x++) {
        int i = placesAvailble[x];
        vector<vector<string>> solvingState(currentState.begin(), currentState.end());
        solvingState[index][i] = "Q";
        for(int j=i+1; j<n; j++) {
            solvingState[index][j] = ".";
        }
        for(int k=index+1; k<n; k++) {
            solvingState[k][i] = ".";
        }
        for(int l=1; l<n; l++) {
            if(i+l<n && index+l<n) solvingState[index+l][i+l] = ".";
            else break;
        }
        for(int m=1; m<n; m++) {
            if(i-m>=0 && index+m<n) solvingState[index+m][i-m] = ".";
            else break;
        }
        findSolution(solvingState, index+1, n);
    }

    return;    
}

void nQueens(int n) {
    vector<string> A(n, "_");
    vector<vector<string>> V(n,A);
    findSolution(V, 0, n);
    return;
}


int main() {
    int n = 4;
    cout<<" give the 'n' of nQueens problem: ";
    cin>>n;

    solutions.clear();

    nQueens(n);

    for(vector<vector<string>> vec: solutions) {
        cout<<"solution:  "<<endl;
        for(vector<string> v: vec) {
            cout<<"[ ";
            for(string i: v) {
                cout<<i<<", ";
            }
            cout<<"]"<<endl;
        }
        cout<<endl<<"solution end"<<endl<<endl;
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