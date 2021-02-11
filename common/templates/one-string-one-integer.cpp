#include<bits/stdc++.h>
#include "../common/lib/printlib.cpp"

using namespace std;

string solve(string A, int B) {
    int n = A.length();
    return A;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin>>T;

    for(int t=1; t<=T; t++) {
        string A;
        int B;
        cin>>A;
        cin>>B;

        auto ans = solve(A);
        cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
    }

    return 0;
}