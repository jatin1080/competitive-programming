#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> removeDuplicates(vector<int> &A) {
    sort(A.begin(), A.end());

    for(int i=0; i<A.size(); i++) {
        if(i+1<A.size()) {
            if()
        }
    }
}

int main()
{
    vector<int> A{1,2,3,4,5,6,7,8,2,3,4,7,8,3,4,1,5,6,7};

    cout << "[ ";
    for (int i : A)
    {
        cout << i << ", ";
    }
    cout << "]" << endl;
}