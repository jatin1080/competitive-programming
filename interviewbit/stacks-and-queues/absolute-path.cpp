#include <bits/stdc++.h>

using namespace std;

string absolutePath(string path) {
    stringstream streamPath(path);
    char delimiter = '/';
    string str = "";
    stack<string> directories;
    while(getline(streamPath, str, delimiter)) {
        if(str[0]!='.') { 
            if(str.length()) directories.push(str);
        }
        else {
            for(int i=1; i<=str.length()-1; i++) if(directories.size()) directories.pop();
        }

        // debug 
        // cout<<" debug: printing stack top-> ";
        // if(directories.size()) cout<<":::: "<<directories.top();
        // cout<<endl;
    }

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

int main() {
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    
    string A;
    cin>>A;

    string ans = absolutePath(A);

    cout<<ans;

    return 0;
}