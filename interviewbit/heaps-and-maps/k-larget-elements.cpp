#include<bits/stdc++.h>
#include "../../common/lib/printlib.cpp"

using namespace std;

vector<int> solve(vector<int> A, int B) {
    int n = A.size();
    map<int, int> M;
    int sum = 0;
    for (int i=0; i<n; i++) {
        int x = A[i];
        cout<<"A[i]: "<<x<<endl;
        print(M);
        cout<<endl;
        cout<<"sum: "<<sum<<endl;
        if (sum<B) {
            if (M.find(x)!=M.end()) M[x]++;
            else M[x] = 1;
            sum++;
        }
        else {
            int y = M.begin()->first;
            if (x > y) {
                // cout<<"before ";
                // print(M);
                cout<<"x: "<<x<<" y: "<<y;
                cout<<endl;
                M.begin()->second--;
                if (M.begin()->second <=0) M.erase(y);
                if (M.find(x)!=M.end()) M[x]++;
                else M[x] = 1;
                // cout<<"after  ";
                // print(M);
                // cout<<endl;
            }
        }
    }
    vector<int> ret;
    print(M);
    cout<<endl;
    for (auto m: M) {
        for (int i=0; i<m.second; i++) ret.push_back(m.first);
    }
    return ret;
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

        int B;
        cin>>B;

        auto ans = solve(A, B);
		cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
	}

    return 0;
}
// Input that can be pasted in input.txt
// 4
// 3 11 3 4
// 2
// 4 11 3 4 6
// 3
// 10 725 479 359 963 465 706 146 282 828 962
// 2
// 42 468 335 501 170 725 479 359 963 465 706 146 282 828 962 492 996 943 828 437 392 605 903 154 293 383 422 717 719 896 448 727 772 539 870 913 668 300 36 895 704 812 323
// 10