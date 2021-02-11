#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;


string zigzagString(string text, int n);

int main() {
    int n = 3;
    string text = "ABCD";
    cout<<zigzagString(text, n)<<"\n";
}

string zigzagString(string text, int n) {
    vector<string> vec(n, "");
    int index = 0;
    bool increaseIndex = true;
    for(int i=0; i<text.length(); i++) {
        vec[index] += text[i];
        
        if(increaseIndex) index++;
        else index--;

        if(index==n-1) increaseIndex = false;
        else if(index==0) increaseIndex = true;
    }

    // for(string str: vec) cout<<"string in vector:   "<<str<<endl;
    string ans = "";
    for(string str: vec) ans +=str;

    return ans;
}