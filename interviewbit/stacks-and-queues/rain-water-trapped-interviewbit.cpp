#include <bits/stdc++.h>

using namespace std;

int solve(std::vector<int>);

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

    int ans = solve(A);


    cout<<"ans-> "<<ans;

    return 0;
}

solve(std::vector<int> A) {
    std::vector<int> max_left;
    std::vector<int> max_right;

    int len = A.size();

    if(len==0 || len==1 || len==2) return 0;

    int lastIndex = A.size() - 1;

    max_left.push_back(-1);
    int curr_left_max = A[0]; 
    for(int i=1; i<=lastIndex; i++) {
        int x = A[i-1];
        if(x>curr_left_max) curr_left_max = x;
        max_left.push_back(curr_left_max);
    }

    max_right.push_back(-1);
    int curr_right_max = A[lastIndex]; 
    for(int i=lastIndex-1; i>=0; i--) {
        int x = A[i+1];
        if(x>curr_right_max) curr_right_max = x;
        max_right.push_back(curr_right_max);
    }

    // cout<<endl;
    // for(int x: max_left) {
    //     cout<<x<<" ";
    // }

    // cout<<endl;
    // for(int i=0; i<=lastIndex; i++) {
    //     cout<<max_right[lastIndex-i]<<" ";
    // }

    int waterTrapped = 0;

    for(int i=0; i<=lastIndex; i++) {
        int y = min(max_right[lastIndex-i], max_left[i]) - A[i];

        if(y>0) waterTrapped += y;
    }

    return waterTrapped;

}