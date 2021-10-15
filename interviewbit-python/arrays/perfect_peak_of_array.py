def algo(A):
    n = len(A)
    max_prefix = [None]*n
    min_suffix = [None]*n
    max_prefix[0] = -1
    min_suffix[n-1] = 10**9+1
    for i in range(1, n):
        max_prefix[i] = max(max_prefix[i-1], A[i-1])
        min_suffix[-1-i] = min(min_suffix[0-i], A[0-i])
    min_suffix[n-1] = -1
    # print(max_prefix)
    # print(A)
    # print(min_suffix)
    for i in range(1, n-1):
        if A[i] > max_prefix[i] and A[i] < min_suffix[i]: return 1
    return 0

class Solution:
    # @param A : list of integers
    # @return an integer
    def perfectPeak(self, A):
        ans = algo(A)
        return ans


# A = [5, 1, 4, 3, 6, 8, 10, 7, 9]
A = [5, 1, 4, 4]
solution = Solution()
print(solution.perfectPeak(A))