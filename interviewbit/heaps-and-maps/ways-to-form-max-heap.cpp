#include<bits/stdc++.h>
#include "../../common/lib/printlib.cpp"

using namespace std;

// unsigned long long ncr(int n, int r, int mod) {
//     if (n<=1) return n;
//     if (r==0) return 1;
//     return (n*ncr(n-1, r-1, mod))/r;
// }

// int algo(int A) {
//     if (A<1) return 1;
//     if (A==1) return 1;
//     int mod = pow(10,9)+7;
//     int numberoflevels = log2(A)+1;
//     int num_elements_until_completely_filled = pow(2, numberoflevels - 1) - 1;
//     int num_elements_last_level = A - num_elements_until_completely_filled;
//     int num_elements_second_last_level = pow(2, numberoflevels - 2);
//     int left_in_last_level=0;
//     int right_in_last_level=0;
//     if(num_elements_last_level>num_elements_second_last_level) {
//         left_in_last_level = num_elements_second_last_level;
//         right_in_last_level = num_elements_last_level - num_elements_second_last_level;
//     }
//     else left_in_last_level = num_elements_last_level;
//     int l = left_in_last_level + (num_elements_until_completely_filled-1)/2;
//     int r = right_in_last_level + (num_elements_until_completely_filled-1)/2;
//     unsigned long long n = ncr(A-1, l, mod);
//     unsigned long long sl = algo(l);
//     unsigned long long sr = algo(r);
//     int ans = ((((n%mod)*sl)%mod)*sr)%mod;
//     return ans%mod;
// }

int algo_2(int A) {
    // Try to use bottom up DP
    long long ans[A+1] = {0};
    int mod = pow(10, 9)+7;
    // create nCr dp?
    int ncr[A+1][A+1];
    for (int i=0; i<=A; i++) {
        for (int j=0; j<=i; j++) {
            if(i==j || j==0) {
                ncr[i][j] = 1; continue;
            }
            ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%mod;
        }
    }
    // for (int i=0; i<=A; i++) {
    //     for (int j=0; j<=i; j++) cout<<ncr[i][j]<<" ";
    //     cout<<endl;
    // }
    ans[0] = 1;
    for (int i=1; i<=A; i++) {
        int numberoflevels = ((int)log2(i))+1;
        bool perfecttree = false;
        if (i==(pow(2, numberoflevels)-1)) perfecttree = true;
        // cout<<"perfecttree "<<i<<": "<<perfecttree<<endl;
        int num_elements_until_completely_filled = perfecttree ? pow(2, numberoflevels)-1 : pow(2, numberoflevels - 1) - 1 ;
        int num_elements_last_level = i - num_elements_until_completely_filled;
        int num_elements_second_last_level = perfecttree ? pow(2, numberoflevels - 1) : pow(2, numberoflevels - 2);
        int left_in_last_level=0;
        int right_in_last_level=0;
        if(num_elements_last_level>num_elements_second_last_level) {
            left_in_last_level = num_elements_second_last_level;
            right_in_last_level = num_elements_last_level - num_elements_second_last_level;
        }
        else left_in_last_level = num_elements_last_level;
        int l = left_in_last_level + (num_elements_until_completely_filled-1)/2;
        int r = right_in_last_level + (num_elements_until_completely_filled-1)/2;
        unsigned long long n = ncr[i-1][l];
        unsigned long long sl = ans[l];
        unsigned long long sr = ans[r];
        ans[i] = ((((n%mod)*sl)%mod)*sr)%mod;
    }
    // for (int i=0; i<=A; i++) cout<<"{"<<i<<": "<<ans[i]<<"} ";
    // cout<<endl;
    return ans[A]%mod;
}


int solve(int A) {
    // auto ans = algo(A);
    auto ans = algo_2(A);
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // 258365767
    int T;
    cin>>T;
    for(int t=1; t<=T; t++) {
        int A;
        cin>>A;

        auto ans = solve(A);
        cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
    }

    return 0;
}