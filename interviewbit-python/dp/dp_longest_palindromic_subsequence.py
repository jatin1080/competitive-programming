def lps_memoization(A, s, e, dp):
    # print((s, e), end=' ')
    if dp[s][e] == None:
        if s==e:
            dp[s][e] = 1
            return dp[s][e]

        if e == s+1:
            if A[s] == A[e]:
                dp[s][e] = 2
                return dp[s][e]
            else:
                dp[s][e] = 1
                return dp[s][e]

        if A[s] == A[e]:
            if not dp[s][e]:
                if not dp[s+1][e-1]:
                    dp[s+1][e-1] = lps_memoization(A, s+1, e-1, dp)
                dp[s][e] = 2 + dp[s+1][e-1]
            return dp[s][e]
        else:
            if not dp[s][e]:
                if not dp[s+1][e]:
                    dp[s+1][e] = lps_memoization(A, s+1, e, dp)
                if not dp[s][e-1]:
                    dp[s][e-1] = lps_memoization(A, s, e-1, dp)
                dp[s][e] = max(dp[s+1][e], dp[s][e-1])
            return dp[s][e]
    else:
        return dp[s][e]


def lps_tabulation(A):
    n = len(A)
    dp = [[None]*n for x in range(n)]

    for e in range(n):
        for s in range(n-1, -1, -1):
            if s==e:
                dp[s][e] = 1
            elif s>e:
                dp[s][e] = 0
            elif A[s] == A[e]:
                dp[s][e] = 2 + dp[s+1][e-1]
            else:
                dp[s][e] = max(dp[s+1][e], dp[s][e-1])

    return dp[0][n-1]

class Solution:
    def solve(self, A):
        # sys.setrecursionlimit(2500)
        # dp1 = [None]*len(A)
        # dp2 = [[None]*len(A) for x in range(len(A))]
        # ans = lps_memoization(A, 0, len(A)-1, dp2)
        # print(dp2)

        ans = lps_tabulation(A)

        return ans


A = 'bebeeed'
# A = 'bb'
solution = Solution()
print(solution.solve(A))
