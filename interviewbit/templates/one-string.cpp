#include<bits/stdc++.h>
#include "../../common/lib/printlib.cpp"

using namespace std;

int solve(string A) {
    return -1;
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin>>T;

    for(int t=1; t<=T; t++) {
        string A;
        cin>>A;
        // getline(cin, A); // for string with spaces

        auto ans = solve(A);
		cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
    }

    return 0;
}