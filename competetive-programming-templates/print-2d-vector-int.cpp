#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {

    vector<vector<int>> ans;

    for(vector<int> v: ans) {
        cout<<"[ ";
        for(int i: v) {
            cout<<i<<", ";
        }
        cout<<"]"<<endl;
    }
}