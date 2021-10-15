def algo(A, B):
    n = len(A)
    if B<=A[0]: return 0
    if B>A[n-1]: return n
    start = 0
    end = n-1
    while start<=end:
        mid = int((start+end)/2)
        if A[mid]==B or (B<A[mid] and B>A[mid-1]):
            return mid
        elif B>A[mid]:
            start = mid+1
        else:
            end = mid-1
    return n


class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def searchInsert(self, A, B):
        ans = algo(A, B)
        return ans

A = [1, 3, 5, 6]
B = 2
A = [1, 3, 5, 6]
B = 5
A = [1, 3, 5, 6]
B = 7
solution = Solution()
print(solution.searchInsert(A, B))