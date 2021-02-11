#include<bits/stdc++.h>
#include "../common/lib/printlib.cpp"

using namespace std;

struct TrieNode {
    struct TrieNode* child[2];
    bool isLeaf;
    TrieNode () {
        isLeaf = false;
        child[0] = NULL;
        child[1] = NULL;
    }
};

void insert(TrieNode* root, string key) {
    TrieNode* curr = root;
    for(char c: key) {
        int index = c - '0';
        if(!curr->child[index]) curr->child[index] = new TrieNode();
        curr = curr->child[index];
    }
    curr->isLeaf = true;
}

TrieNode* maketrie(vector<int> &B) {
    TrieNode* root = new TrieNode();
    // create string keys and insert in trie
    for (int x: B) {
        bitset<8*sizeof(x)> b(x);
        insert(root, b.to_string());
    }
    return root;
}

int algo(vector<int> &A, vector<int> &B) {
    TrieNode* root = maketrie(A);
    return -1;
}

int solve(vector<int> &A, vector<int> &B) {
    int ans = algo(A, B);
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
        vector<int>A;
        for(int i=0; i<a; i++) {
            int val;
            cin>>val;
            A.push_back(val);
        }

        int b;
        cin>>b;
        vector<int>B;
        for(int i=0; i<b; i++) {
            int val;
            cin>>val;
            B.push_back(val);
        }

        auto ans = solve(A, B);
        cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
    }

    return 0;
}