#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

string pathFromStack(stack<string> directories) {
    if(!directories.size()) return "";
    string simplePath = "";
    while(directories.size()) { 
        string str = directories.top();       
        simplePath.insert(0, str);
        directories.pop();
        simplePath.insert(0, "/");
    }

    return simplePath;
}


string simplify(string path) {
    stack<string> directoryStructure;
    string simplePath = "";
    string directoryName = "";
    string cdots = "";
    for(char ch: path) {
        switch (ch) {
            case '/': {
                if(directoryName.size()>0) {
                    directoryStructure.push(directoryName);
                    directoryName.clear();
                }
                if(cdots.size()>0) {
                    for(int i=1; i<=cdots.size()-1; i++) if(directoryStructure.size())directoryStructure.pop();
                    cdots.clear();
                }
                break;
            }
            case '.': {
                cdots += ch;
                break;
            }
            default: {
                directoryName += ch;
                break;
            }
        }
    }
    
    
    if(directoryName.size()>0) {
        directoryStructure.push(directoryName);
        directoryName.clear();
    }
    if(cdots.size()>0) {
        for(int i=1; i<=cdots.size()-1; i++) if(directoryStructure.size())directoryStructure.pop();
        cdots.clear();
    }
    
    simplePath = pathFromStack(directoryStructure);
    
    if(!simplePath.size()) simplePath = "/";

    return simplePath;
}

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    string A;
    cin>>A;

    string ans = simplify(A);

    cout<<ans;

    return 0;
}