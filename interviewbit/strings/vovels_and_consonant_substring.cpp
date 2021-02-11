#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(string A) {
  int n = A.length();
  if (n==1) return 0;

  int number_of_vowels = 0;
  int number_of_consonants = 0;
  int modulo = pow(10, 9)+7;

  for (int i=0; i<n; i++) {
    char ch = A[i];
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
      number_of_vowels++;
    }
    else number_of_consonants++;
  }

  if (!number_of_vowels || !number_of_consonants) return 0;
  int ret = 0;
  for (int i=0; i<n; i++) {
    char ch = A[i];
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
      ret += number_of_consonants;
      ret %= modulo;
      number_of_vowels--;
    }
    else {
      ret += number_of_vowels;
      ret %= modulo;
      number_of_consonants--;
    }
  }

  return ret%modulo;
}

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

	int T = 1;
	// cin>>T;

	for(int t=1; t<=T; t++) {
    string A;
    cin>>A;

    int ans = solve(A);
		cout<<"answer "<<T<<": "<<ans<<endl;
	}

  return 0;
}