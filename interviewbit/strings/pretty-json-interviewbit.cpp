#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<string> prettyJson(string json) {
    vector<string> pretty;
    int indent = 0;
    bool newLine = true;
    // int lastIndex = -1;
    // char previousChar = json[0];
    for(char ch: json) {
        if(ch=='[' || ch=='{') {
            pretty.push_back("");
            //put indentation code here
            for(int i=0; i<indent; i++) {
                pretty.back() += '\t';
            }
            pretty.back() += ch;
            indent++;
            newLine = true;
        }
        else if(ch==']' || ch=='}') {
            pretty.push_back("");
            //put indentation code here
            indent--;
            for(int i=0; i<indent; i++) {
                pretty.back() += '\t';
            }
            pretty.back() += ch;
            newLine = true;
        }
        else if(ch==',') {
            pretty.back() += ch;
            newLine = true;
        }
        else if(ch==' ') {
            continue;
        }
        else {
            if(newLine) {
                pretty.push_back("");
                //put indentation code here
                for(int i=0; i<indent; i++) {
                    pretty.back() += '\t';
                }
                pretty.back() += ch;
                newLine = false;
            }
            else {
                pretty.back() += ch;
                newLine = false;
            }
        }
    }

    return pretty;
}

// " " { } [ ] , 

int main() {
    string input = "{A:\"B\",C:{D:\"E\",F:{G:\"H\",I:\"J\"}}}";
    string input2 = "[\"foo\", {\"bar\":[\"baz\",null,1.0,2]}]";
    // string input3 = "";
    // cout<<"Your Input: \n";
    // cin>>input3;
    vector<string> ans = prettyJson(input);
    for(string str: ans) cout<<"json line:-->"<<str<<endl;
    vector<string> ans2 = prettyJson(input2);
    for(string str: ans2) cout<<"json line:-->"<<str<<endl;
}