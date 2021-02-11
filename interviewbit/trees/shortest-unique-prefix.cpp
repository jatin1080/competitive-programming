#include<bits/stdc++.h>
#include "../../common/lib/printlib.cpp"

using namespace std;

struct TrieNode {
    struct TrieNode* child[26];
    bool isLeaf;
    TrieNode () {
        isLeaf = false;
        for(int i=0; i<26; i++) child[i] = NULL;
    }
};

void insert(TrieNode* root, string key) {
    TrieNode* curr = root;
    for(char c: key) {
        int index = c - 'a';
        if(!curr->child[index]) curr->child[index] = new TrieNode();
        curr = curr->child[index];
    }
    curr->isLeaf = true;
}

TrieNode* maketrie(vector<string> &A) {
    TrieNode* root = new TrieNode();
    // create string keys and insert in trie
    for (string x: A) insert(root, x);
    return root;
}

vector<string> algo(vector<string> &A) {
    TrieNode* root = maketrie(A);
    vector<string> ret;
    for(string a: A) {
        TrieNode* curr = root;
        string ans = "";
        // find last splitting point
        // all child are 1 until the very end
        // for the leaf the child should be zero
        vector<int> children;
        for (char ch: a) {
            int index = ch - 'a';
            curr = curr->child[index];
            int nochild = 0;
            for (int i=0; i<26; i++) if(curr->child[i]) nochild++;
            children.push_back(nochild);
        }
        if(children[children.size()-1]>=1) ret.push_back(a); // complete string is required for unique prefix
        else {
            // find the index after which only 1 children are there
            int endindex = 0;
            for (int i=0; i<children.size()-1; i++) {
                if (children[i]>1) endindex = i+1;
            }
            ans = a.substr(0, endindex+1);
            ret.push_back(ans);
        }
    }
    return ret;
}

vector<string> solve(vector<string> &A) {
    auto ans = algo(A);
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin>>T;
    for(int t=1; t<=T; t++) {
        int a;
        cin>>a;
        vector<string>A;
        for(int i=0; i<a; i++) {
            string val;
            cin>>val;
            A.push_back(val);
        }

        auto ans = solve(A);
        cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
    }

    return 0;
}