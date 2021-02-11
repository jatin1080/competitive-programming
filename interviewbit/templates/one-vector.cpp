#include<bits/stdc++.h>
#include "../common/lib/printlib.cpp"

using namespace std;

int solve(vector<int> A) {
    return -1;
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

        auto ans = solve(A);
        cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
    }

    return 0;
}