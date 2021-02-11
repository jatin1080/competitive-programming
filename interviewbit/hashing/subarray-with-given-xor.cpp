#include<bits/stdc++.h>
#include "../../common/lib/printlib.cpp"

using namespace std;

int solve(vector<int> A, int B) {
  int n = A.size();
  int ret = 0;
  // simple approach O(n^2)
  // for (size_t i = 0; i < n; i++) {
  //   int curr_xor = 0;
  //   for (size_t j = i; j < n; j++) {
  //     curr_xor = curr_xor^A[j];
  //     if(curr_xor==B) ret++;
  //   }
  // }

  std::vector<int> X(n, 0); // prefix xor
  X[0] = A[0];
  for (size_t i = 1; i < n; i++) X[i] = A[i]^X[i-1];

  unordered_map<int, int> C; // to save frequency of X[i]

  // iterate for ret
  for (int i=0; i<n; i++) {
      int x = X[i]^B;
      if (C.find(x) != C.end()) ret += C[x];
      if (X[i]==B) ret++;
      if (C.find(X[i]) != C.end()) C[X[i]]++;
      else C[X[i]] = 1;
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