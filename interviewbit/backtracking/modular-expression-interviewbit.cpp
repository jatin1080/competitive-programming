#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int modularExpression(int A, int B, int C) {

    if(B==0) {
        return 1;
    }
    else if(B%2==0) {
        long long int y = modularExpression(A, B/2, C);
        long long int z = (y*y)%C;
        int rex = z>=0 ? (int)z : (int)(z + C); 
        return rex;
    }
    else if(B%2==1) {
        long long int z = A%C;
        z = (z * modularExpression(A, B-1, C))%C;
        int rex = z>=0 ? (int)z : (int)(z + C);
        return rex;
    }

}


int main() {

    int A = 71045970;
    int B = 41535484;
    int C = 64735492;

    // cout<<"A: ";
    // cin>>A;
    // cout<<"B: ";
    // cin>>B;
    // cout<<"C: ";
    // cin>>C;

    cout<<"A: "<<A<<endl;
    cout<<"B: "<<B<<endl;
    cout<<"C: "<<C<<endl;

    cout<<"here is the modular expression: "<<modularExpression(A,B, C);
}