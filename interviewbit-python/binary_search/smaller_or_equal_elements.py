def algo(A, B):
    n = len(A)
    start = 0
    end = n-1
    while(start<=end):
        mid = int((start+end)/2)
        if A[mid]>B and A[mid-1]<=B:
            return mid
        elif A[mid]>B and A[mid-1]>B:
            end = mid-1
        elif A[mid]<=B:
            start = mid+1
    return -1


class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        ans = algo(A, B)
        if ans == -1 and B>=A[-1]: ans = len(A)
        return ans

A = [1, 3, 4, 4, 6]
B = 4
A = [1, 2, 5, 5]
B = 3
# B = 5
solution = Solution()
print(solution.solve(A, B))