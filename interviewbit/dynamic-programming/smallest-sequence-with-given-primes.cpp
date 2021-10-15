#include<bits/stdc++.h>
#include "../../common/lib/printlib.cpp"

using namespace std;

int solve(int A, int B, int C, int D) {
    
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin>>T;
    for(int t=1; t<=T; t++) {
        int A;
        cin>>A;
        int B;
        cin>>B;
        int C;
        cin>>C;
        int D;
        cin>>D;

        auto ans = solve(A, B, C, D);
        cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
    }

    return 0;
}