#include<bits/stdc++.h>
#include "../../common/lib/printlib.cpp"

using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B) {
    map<int, vector<int>> M; // infront value to heights
    int n = A.size();
    for (int i=0; i<n; i++) {
        int infront = B[i];
        int height = A[i];
        if (M.find(infront)==M.end()) {
            vector<int> temp;
            temp.push_back(height);
            M[infront] = temp;
        }
        else M[infront].push_back(height);
    }
    // go through the map and sort all vector?
    for (map<int, vector<int>>::iterator it = M.begin(); it!=M.end(); it++) sort(it->second.begin(), it->second.end());
    // go through the map, find the position of element to be inserted and insert
    vector<int> ret;
    for (map<int, vector<int>>::iterator it = M.begin(); it!=M.end(); it++) {
        int curr_infront = it->first;
        vector<int> curr_heights = it->second;
        if (curr_infront==0) {
            for (auto x: curr_heights) ret.push_back(x);
        }
        else {
            for (int i=0; i<curr_heights.size(); i++) {
                // find the position in ret for insertion of curr_heights[i]
                // for finding the index go through ret
                int index=0;
                int curr_element = curr_heights[i];
                int number_of_elements_greater_than_curr_element = 0;
                for (int j=0; j<ret.size(); j++) {
                    if (number_of_elements_greater_than_curr_element==curr_infront)
                }
            }
        }
    }


    return ret;
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