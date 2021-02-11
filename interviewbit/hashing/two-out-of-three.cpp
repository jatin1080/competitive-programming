#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, vector<int> &C) {
  vector<int> ret;
  unordered_map<int, int> fa;
  unordered_map<int, int> fb;
  unordered_map<int, int> fc;
  unordered_map<int, int> fret;
  // cout<<endl<<"A: ";
  for (int x: A) {
    // cout<<x<<" ";
    if (fa[x]) fa[x]++;
    else fa[x]=1;
  }
  // cout<<endl<<"B: ";
  for (int x: B) {
    // cout<<x<<" ";
    if (fb[x]) fb[x]++;
    else fb[x]=1;
  }
  // cout<<endl<<"C: ";
  for (int x: C) {
    // cout<<x<<" ";
    if (fc[x]) fc[x]++;
    else fc[x]=1;
  }

  for (pair<int, int> p: fa) {
    if (!fret[p.first] && ((fa[p.first] && fb[p.first]) || (fb[p.first] && fc[p.first]) || (fc[p.first] && fa[p.first]))) {
      ret.push_back(p.first);
      fret[p.first] = 1;
    }
  }
  for (pair<int, int> p: fb) {
    // cout<<"hey"<<p.first<<"  ";
    if (!fret[p.first] && ((fa[p.first] && fb[p.first]) || (fb[p.first] && fc[p.first]) || (fc[p.first] && fa[p.first]))) {
      // cout<<"bey"<<p.first<<"  ";
      ret.push_back(p.first);
      fret[p.first] = 1;
    }
  }
  for (pair<int, int> p: fc) {
    if (!fret[p.first] && ((fa[p.first] && fb[p.first]) || (fb[p.first] && fc[p.first]) || (fc[p.first] && fa[p.first]))) {
      ret.push_back(p.first);
      fret[p.first] = 1;
    }
  }
  sort(ret.begin(), ret.end());
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

    int c;
    cin>>c;
    vector<int>C;
    for(int i=0; i<c; i++) {
      int val;
      cin>>val;
      C.push_back(val);
    }

		std::vector<int> ans = solve(A, B, C);
    cout<<"answer "<<t<<": ";
    for (int x: ans) {
      cout<<x<<" ";
    }
    cout<<'\n';
	}
  return 0;
}