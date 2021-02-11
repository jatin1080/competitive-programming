#include<bits/stdc++.h>
#include "../common/lib/printlib.cpp"

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
    return {};
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