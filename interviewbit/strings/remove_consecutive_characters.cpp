#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string solve(string A, int B) {
  int n = A.length();
  string ret = "";
  for (size_t i = 0; i < n; i++) {
    // get current continuous length
    char curr_ch = A[i];
    int curr_len = 1;
    char prev_ch = curr_ch;
    while (i<n) {
      i++;
      prev_ch = curr_ch;
      curr_ch = A[i];
      if (curr_ch == prev_ch) curr_len++;
      else {
        i--;
        break;
      }
    }
    if (curr_len != B) {
      for (size_t j = 0; j < curr_len; j++) ret.push_back(prev_ch);
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
    string A;
    int B;
    cin>>A;
    cin>>B;

    string ans = solve(A, B);
		cout<<"answer "<<t<<": "<<ans<<endl;
	}

  return 0;
}