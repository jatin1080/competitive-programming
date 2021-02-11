#include<bits/stdc++.h>
#include "../../common/lib/printlib.cpp"

using namespace std;

int solve(vector<int> &A, vector<int> &B) {
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin>>T;
    for(int t=1; t<=T; t++) {
        int a;
        cin>>a;
        vector<int>A;
        for(int i=0; i<a; i++) {
            int val;
            cin>>val;
            A.push_back(val);
        }

        int b;
        cin>>b;
        vector<int>B;
        for(int i=0; i<b; i++) {
            int val;
            cin>>val;
            B.push_back(val);
        }

        auto ans = solve(A, B);
        cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
    }

    return 0;
}