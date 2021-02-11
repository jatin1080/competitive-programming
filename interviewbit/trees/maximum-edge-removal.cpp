#include<bits/stdc++.h>
#include "../../common/lib/printlib.cpp"

using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int x): val(x) {}
};

int algo(TreeNode* root) {
    int ret = 0;
    return -1;
}

int solve(int A, vector<vector<int>> &B) {
    // first construct the tree
    // create A TreeNodes
    vector<TreeNode*> M; // references to TreeNode from integer indexes
    M.push_back(NULL); // so that index really start from 1
    for (int i=1; i<=A; i++) {
        TreeNode* t = new TreeNode(i);
        M.push_back(t);
    }
    // update children for each node
    for (vector<int> edge: B) {
        int from = edge[0];
        int to = edge[1];
        TreeNode* t = M[from];
        t->children.push_back(M[to]);
    }

    // try printing M // works!!!!!!
    // for (TreeNode* x: M) {
    //     if(x) {
    //         cout<<x->val<<": ";
    //         for (TreeNode* c: x->children) {
    //             cout<<c->val<<", ";
    //         }
    //     }
    //     cout<<endl;
    // }
    int ans = algo(M[1]);
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int T;
	cin>>T;
	for(int t=1; t<=T; t++) {
        int A;
        cin>>A;

        int rows = A-1;
		// cin>>rows;
        int columns = 2;
        // cin>>columns;
		vector<vector<int>>B;
		for(int i=0; i<rows; i++) {
            vector<int> C;
            for (int j=0; j<columns; j++) {
                int val;
                cin>>val;
                C.push_back(val);
            }
            B.push_back(C);
		}

        auto ans = solve(A, B);
		cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
	}

    return 0;
}