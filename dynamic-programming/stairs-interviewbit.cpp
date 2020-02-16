#include <bits/stdc++.h>

using namespace std;

long int climbStairs(int A, std::vector<long int> v)
{
    int len = v.size();
    if(A<len) return v[A];
    else return climbStairs(A-1, v) + climbStairs(A-2, v);
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int A;
    cin>>A;

    std::vector<long int> fibo{0, 1, 2};
    std::vector<int> inputs;
    for(int i=1; i<=A; i++) {
        inputs.push_back(i);
    }

    // int ans = climbStairs(A, fibo);

    for(int i: inputs) {
        cout<<i<<" -> "<<climbStairs(i,fibo)<<endl;
    }

    // cout<<"hi there";
    // cout<<ans;

    return 0;
}