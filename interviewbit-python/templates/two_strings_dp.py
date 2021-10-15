def algo_memoization(A, B, dp):
    return dp

def algo_tabulation(A, B):
    dp = [[None]*len(B) for x in range(len(A))]
    return dp

class Solution:
    def solve(self, A, B):
        # sys.setrecursionlimit(2500)
        # dp1 = [None]*len(A)
        dp2 = [[None]*len(B) for x in range(len(A))]
        ans = algo_memoization(A, B, dp2)

        return ans


A = 'first string'
B = 'second string'
solution = Solution()
print(solution.solve(A, B))

