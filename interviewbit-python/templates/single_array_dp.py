def algo(A, dp):
    return dp

class Solution:
    def solve(self, A):
        # sys.setrecursionlimit(2500)
        # dp1 = [None]*len(A)
        dp2 = [[None]*len(A) for x in range(len(A))]
        ans = algo(A, dp2)
        return ans


A = []
solution = Solution()
print(solution.solve(A))