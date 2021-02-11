#include <bits/stdc++.h>

using namespace std;

int solve(std::vector<int>);

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    // int N;
    // cin>>N;

    std::vector<int> A{2,1,5,6,2,3};

    // for(int i=1; i<=N; i++) {
    //     int x;
    //     cin>>x;
    //     A.push_back(x);
    // }

    int ans = solve(A);

    cout<<"ans -> "<<ans;

    return 0;
}

solve(std::vector<int> A) {
    
    int len = A.size();

    if(len==0) return 0;
    else if(len==1) return A[0];

    int lastIndex = A.size()-1;

    stack<int> left_shorter_index;
    queue<int> right_shorter_index;

    left_shorter_index.push(0);
    for(int i=1; i<=lastIndex; i++) {
        if(A[i]>A[i-1]) left_shorter_index.push(i-1);
        else left_shorter_index.push(left_shorter_index.top());
    }

    right_shorter_index.push(lastIndex);
    for(int i=lastIndex-1; i>=0; i--) {
        if(A[i]>A[i+1]) right_shorter_index.push(i+1);
        else right_shorter_index.push(right_shorter_index.front());
    }

    int maxArea = 0;

    for(int i=0; i<=lastIndex; i++) {
        cout<<right_shorter_index.front()<<" "<<left_shorter_index.top()<<endl;
        int currArea = (right_shorter_index.front() - left_shorter_index.top() + 1) * A[i];
        right_shorter_index.pop();
        left_shorter_index.pop();
        if(currArea>maxArea) maxArea = currArea;
    }

    return maxArea;
}