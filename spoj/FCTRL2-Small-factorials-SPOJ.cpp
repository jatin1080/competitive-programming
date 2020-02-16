#include <bits/stdc++.h>

using namespace std;

std::vector<int> multiplyLargeNumber(std::vector<int> numberVector, int multiplier) {
	std::vector<int> v;
	int lastIndex = numberVector.size() - 1;
	int carry = 0;
	for(int i = 0; i<=lastIndex; i++) {
		int digit = numberVector[i];
		int multipliedValue = digit * multiplier;
		int digitToInsert = (multipliedValue + carry)%10;
		carry = (multipliedValue + carry)/10;
		v.push_back(digitToInsert);
	}

	if(carry) {
		while(carry) {
			int digitToInsert = carry%10;
			carry /=10;
			v.push_back(digitToInsert);
		}
	}

	return v;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
	int T, N;
	cin>>T;

	for(int t=1; t<=T; t++) {
		cin>>N;

		std::vector<int> number;
		number.push_back(1);

		for(int i=2; i<=N; i++) {
			number = multiplyLargeNumber(number, i);
		}

		int endIndex = number.size() - 1;

		for(int i = endIndex; i>=0; i--) {
			cout<<number[i];
		}

		cout<<endl;
	}

	return 0;

}