#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
int solve(vector<int> &V) {
    int n = V.size();
    if(n==0 || n==1) return 0;
    int globalMax = 0;
    int currentMax = 0;
    for(int i=1; i<=n; i++) {
        currentMax = 0;
        for(int j=i; j<=n; j++) {
            int area = min(V[i-1], V[j-1]) * (j-i);
            if(area>currentMax) currentMax = area;
        }
        if(currentMax>globalMax) globalMax = currentMax;
    }

    return globalMax;

}
*/

int solve(vector<int> &A) {
    int n = A.size();
    int maxArea = 0;
    int firstIndex = 0;
    int secondIndex = n-1;

    for(int i=0; i<n; i++) {
        int minimum = min(A[firstIndex], A[secondIndex]);
        int area = (secondIndex-firstIndex) * minimum;
        if(area>maxArea) {
            maxArea = area;
        }
        if(minimum == A[firstIndex]) firstIndex++;
        else secondIndex--;
    }

    return maxArea;
}


int main() {
    vector<int> V{1, 5, 4, 3};

    int ans = solve(V);

    // cout<<ans<<" is the ans";

    return ans;
}


/*

interviewbit my unsolved ans on interview bit

int findWater(vector<int> arr, int n)
{
    // left[i] contains height of tallest bar to the
    // left of i'th bar including itself
    int left[n];
 
    // Right [i] contains height of tallest bar to
    // the right of ith bar including itself
    int right[n];
 
    // Initialize result
    int water = 0;
 
    // Fill left array
    left[0] = arr[0];
    for (int i = 1; i < n; i++) left[i] = max(left[i-1], arr[i]);

 
    // Fill right array
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)  right[i] = max(right[i+1], arr[i]);

    // Calculate the accumulated water element by element
    // consider the amount of water on i'th bar, the
    // amount of water accumulated on this particular
    // bar will be equal to min(left[i], right[i]) - arr[i] .
    for (int i = 0; i < n; i++)  water += min(left[i],right[i]) - arr[i];

    return water;
}


int Solution::maxArea(vector<int> &A) {
    return findWater(A,A.size());

}

*/