#include<bits/stdc++.h>
using namespace std;

void print(vector<int> v, string separator=" ") {
    for (int x: v) cout<<x<<separator;
    return;
}

void print(vector<string> v, string separator=" ") {
    for (auto x: v) cout<<x<<separator;
    return;
}

void print(vector<vector<int>> v, string separator=" ") {
    for (vector<int> row: v) {
        print(row, separator);
        cout<<endl;
    }
}

void print(map<int, int> M, string separator=" ") {
    for (auto m: M) cout<<m.first<<"->"<<m.second<<separator;
    return;
}

void print(int a, string separator=" ") {
    cout<<a<<separator;
    return;
}

void print(long int a, string separator=" ") {
    cout<<a<<separator;
    return;
}

void print(long long int a, string separator=" ") {
    cout<<a<<separator;
    return;
}

void print(string s, string separator=" ") {
    cout<<s<<separator;
    return;
}