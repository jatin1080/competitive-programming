#include <bits/stdc++.h>

using namespace std;

bool isRedundantBraces(string expression) {
    int numBraces = 0;
    int numOperator = 0;
    int lastIndex = expression.length()-1;

    for(int i=0; i<=lastIndex; i++) {
        char ch = expression[i];
        if(ch=='+' || ch=='-' || ch=='/' || ch=='*') numOperator++;
        else if(ch=='(') numBraces++;
    }

    if(numBraces>numOperator) return 1;

    return 0;

}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    string A;
    cin>>A;

    bool ans = isRedundantBraces(A);

    cout<<ans;

    return 0;
}