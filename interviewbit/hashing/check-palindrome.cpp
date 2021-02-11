#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(string A) {
  int n = A.length();
  if (n==1) return 1;
  unordered_map<char, int> M;
  int number_of_odd = 0;
  for (char ch: A) {
    if (M[ch]) {
      M[ch]++;
      if (M[ch]%2==1) number_of_odd++;
      else number_of_odd--;
    }
    else {
      M[ch] = 1;
      number_of_odd++;
    }
  }
  // std::cout << number_of_odd << '\n';
  if (number_of_odd<=1) return 1;
  return 0;
}

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

	int T;
	cin>>T;

	for(int t=1; t<=T; t++) {
    string A;
    cin>>A;

    int ans = solve(A);
		cout<<"answer "<<t<<": "<<ans<<endl;
	}

  return 0;
}