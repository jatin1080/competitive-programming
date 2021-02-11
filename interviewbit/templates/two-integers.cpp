#include<bits/stdc++.h>
#include "../common/lib/printlib.cpp"

using namespace std;

string solve(int A, int B) {
    return "ret"
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

        auto ans = solve(A, B);
        cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
    }

    return 0;
}