#include <bits/stdc++.h>

using namespace std;

std::vector<int> solve(std::vector<int>);

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int N;
    cin>>N;

    std::vector<int> A;

    for(int i=1; i<=N; i++) {
        int x;
        cin>>x;
        A.push_back(x);
    }

    std::vector<int> ans = solve(A);

    return 0;
}

// PROBLEMS FIXED

std::vector<int> solve(std::vector<int> A) {
    std::vector<int> B;
    if(A.size()==0) return B;

    int lastIndex = A.size() - 1;
    int currMin = A[0];
    B.push_back(currMin);

    for(int i=1; i<=lastIndex; i++) {
        int x  = A[i];
        if(x<=currMin) {
            currMin = x;
            B.push_back(currMin);
        }
        else
        {
            
        }
    }

}