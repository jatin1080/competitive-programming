#include<bits/stdc++.h>
#include "../common/lib/printlib.cpp"

using namespace std;

int findsum(std::vector<int> A, int start, int end) {
    if (start>end) return -1;
    int ret=0;
    for(int i=start; i<=end; i++) ret+=A[i];
    return ret;
}

vector<int> make_seg_tree(vector<int> A) {
    // given an array of len n the length of segment tree array is
    // there should be n leaves
    // therefore the number of internal nodes is n-1 and thus length will be 2n-1 (handshaking lemma)
    // to make it a perfect tree we can add dummy nodes so that it is easier to reference
    int n = A.size();
    vector<int> seg_tree;
    if (n==0) {
        seg_tree.push_back(-1);
        return seg_tree;
    }
    if (n==1) {
        seg_tree.push_back(A[0]);
        return seg_tree;
    }
    int totalnodes = 2*n-1;
    int levels = ((int)log2(totalnodes))+1;
    // to make it a perfect tree lets fill all levels; some nodes might be dummy in this
    int length = pow(2, levels)-1;
    for (int i=0; i<length; i++) seg_tree.push_back(-1);
    int sum = 0;
    for (int x: A) sum+=x;
    seg_tree[0] = sum;
    int leftend = (n-1)/2;
    vector<int> left(A.begin(), A.begin()+leftend+1); // +1 since the last element is not included
    vector<int> right(A.begin()+leftend+1, A.end());
    vector<int> seg_tree_left = make_seg_tree(left);
    vector<int> seg_tree_right = make_seg_tree(right);
    // dont insert directly
    // seg_tree.insert(seg_tree.end(), seg_tree_left.begin(), seg_tree_left.end());
    // seg_tree.insert(seg_tree.end(), seg_tree_right.begin(), seg_tree_right.end());

    // first make right tree and left tree of same length
    if (seg_tree_left.size()>seg_tree_right.size()) seg_tree_right.insert(seg_tree_right.end(), seg_tree_left.size()-seg_tree_right.size(), -1);
    else if (seg_tree_left.size()<seg_tree_right.size()) seg_tree_left.insert(seg_tree_left.end(), seg_tree_right.size()-seg_tree_left.size(), -1);

    int exponent = 0;
    bool allfilled = false;
    int index_in_seg_tree = 1;
    while(index_in_seg_tree<length) {
        int iterations = pow(2, exponent);
        int starindex = pow(2, exponent)-1;
        int it = 0;
        while(it<iterations) {
            seg_tree[index_in_seg_tree] = seg_tree_left[starindex+it];
            index_in_seg_tree++;
            it++;
        }
        it = 0;
        while(it<iterations) {
            seg_tree[index_in_seg_tree] = seg_tree_right[starindex+it];
            index_in_seg_tree++;
            it++;
        }
        exponent++;
    }
    return seg_tree;
}

vector<int> solve(vector<int> A) {
    return make_seg_tree(A);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin>>T;
    for(int t=1; t<=T; t++) {
        int x;
        cin>>x;

        vector<int>A;
        for(int i=0; i<x; i++) {
            int val;
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