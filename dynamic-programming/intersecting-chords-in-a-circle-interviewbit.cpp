#include <bits/stdc++.h>

using namespace std;

// long int countChordingWays(int A, std::vector<long int> dp)
// {
//     long count = 0;

//     if (dp[A]) return dp[A];

//     for(int i=1; i<A; i++) {
//         count+= countChordingWays(i-1, dp)*countChordingWays(A-i, dp);
//     }

//     // dp.push_back(count);

//     return count;

// }

void buildDP(int A, std::vector<long long int> &dp, std::vector<long long int> dp2) {

    cout<<"in here";

    for(int i=1; i<=A; i++) {
        long long int multiplier = 0;
        long long int x=0;
        for(int j=0; j<i; j++) {         
            long long int y = ((dp[j]+100000007*dp2[j])*(dp[i-j-1]+100000007*dp2[i-j-1]));
            multiplier += y/1000000007;    
            x+=y%1000000007;
        }
        x%1000000007;            

        dp.push_back(x);
        dp2.push_back(multiplier);
    }

    return;
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    int A;
    cin>>A;

    std::vector<long long int> dp{1};
    std::vector<long long int> dp2{0};

    cout<<">>>>>>>>"<<dp[0]<<endl;

    buildDP(A, dp, dp2);

    cout<<"dp length: "<<dp.size();

    cout<<"printing DP: "<<endl;
    for(int i=0; i<=A; i++) {
        cout<<i<<" :::: "<<dp[i]<<endl;
    }

    long long int ans = dp[A];

    cout<<"Ans: "<<ans%1000000007;

    return 0;
}