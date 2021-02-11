#include<bits/stdc++.h>
#include "../../common/lib/printlib.cpp"

using namespace std;

string solve(int a, int b) {
    long long int lla = stoll(to_string(a));
    long long int llb = stoll(to_string(b));
    long long A = abs(lla);
    long long B = abs(llb);
    long long int x = A/B;
    long long int f = A%B;
    if (f==0) return to_string(x);

    // process fraction part
    string ret = to_string(x);
    ret.append(".");
    unordered_map<int, int> F; // to save modulus of f with B and its index in ret

    while(f) {
        if (F.find(f) != F.end()) { // repeating part found
            int startindex = F[f];
            int endindex = ret.length();
            ret.insert(startindex, "(");
            ret.append(")");
            break;
        }
        else {
            int nextdecimal = (f*10)/B;
            ret.append(to_string(nextdecimal));
            F[f] = ret.length()-1;
            f = (f*10)%B;
        }
    }
    if ((lla<0 && llb>0) || (lla>0 && llb<0)) ret.insert(0, "-");
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	int T;
	cin>>T;
	for(int t=1; t<=T; t++) {
		long long int A;
		cin>>A;

        long long int B;
        cin>>B;

        auto ans = solve(A, B);
		cout<<"answer "<<t<<": ";
        print(ans);
        cout<<endl;
	}

    return 0;
}