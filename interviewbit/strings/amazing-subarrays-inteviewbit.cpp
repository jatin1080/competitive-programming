#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(string A) {
    unsigned long int length = A.length(); 
    unsigned long int substrings = 0;
    for(int i=0; i<length; i++) {
        char ch = A[i];
        if(ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U') {
            substrings += length - i;
        }
    }

    cout<<"substrings:-->"<<substrings<<"/n";
    int ans = substrings%1003;
    return ans;
}


int main() {
    string input1 = "pGpEusuCSWEaPOJmamlFAnIBgAJGtcJaMPFTLfUfkQKXeymydQsdWCTyEFjFgbSmknAmKYFHopWceEyCSumTyAFwhrLqQXbWnXSn";
    string input2 = "ABEC";
    cout<<solve(input1)<<"\n";
    cout<<solve(input2)<<"\n";
}