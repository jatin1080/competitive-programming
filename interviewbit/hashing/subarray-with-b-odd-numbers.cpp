#include<bits/stdc++.h>
#include "../../common/lib/printlib.cpp"

using namespace std;

bool isOdd(int x) {
    return x%2==1;
}

int solve(vector<int> A, int B) {
  int n = A.size();
  int ret = 0;

  std::vector<int> X(n, 0); // prefix number of odd elements
  if (isOdd(A[0])) X[0]=1;
  else X[0]=0;
  for (size_t i = 1; i < n; i++) {
      if (isOdd(A[i])) X[i] = X[i-1]+1;
      else X[i]=X[i-1];
  }

  unordered_map<int, int> C; // to save frequency of X[i]

  // iterate for ret
  for (int i=0; i<n; i++) {
      int x = X[i]-B;
      if (C.find(x) != C.end()) ret += C[x];
      if (X[i]==B) ret++;
      if (C.find(X[i]) != C.end()) C[X[i]]++;
      else C[X[i]] = 1;
  }
  cout<<"X: ";
  print(X);
  cout<<endl;
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