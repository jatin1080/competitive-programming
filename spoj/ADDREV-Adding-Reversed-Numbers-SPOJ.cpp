#include <bits/stdc++.h>

using namespace std;


int reverseInt(int number);

int main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

	int T, N, M;
	cin>>T;

	for(int t=1; t<=T; t++) {
		cin>>N;
		cin>>M;

		int reverseSum = reverseInt(N) + reverseInt(M);

		cout<<reverseInt(reverseSum)<<endl;
	}

	return 0;
}

int reverseInt(int number) {
	std::vector<int> reversedNumArray;

	int numberOfDigits = log10(number) + 1;    // number should not be 0
	bool firstNonZeroDigitEncountered = false;

	for (int i = 0; i < numberOfDigits; i++)
	{
		int digit = number%10;
		if(digit!=0) firstNonZeroDigitEncountered = true;
		if(firstNonZeroDigitEncountered) reversedNumArray.push_back(digit);
		number/=10;
	}

	// construct the number from array of digits
	int reversedNumber = 0;
	int len = reversedNumArray.size();
	int onesTensHundreds = 1;

	for(int x=0; x < len; x++) {
		reversedNumber += reversedNumArray[len-1-x] * onesTensHundreds;
		onesTensHundreds *= 10;
	}

	// cout<<"printing number "<<reversedNumber<<endl;

	return reversedNumber;
}