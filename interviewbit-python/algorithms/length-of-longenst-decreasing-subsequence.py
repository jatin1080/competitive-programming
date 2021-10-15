def lds_memoization(A, s, e, dp):
    print((s,e), end=' ')
    if not dp[s][e]:
        if s == len(A)-1 and s==e:
            if not dp[s][e]:
                dp[s][e] = 1
            return dp[s][e]
        if s==e:
            if not dp[s][e]:
                dp[s][e] = 1
            return dp[s][e]
        elif s<e:
            currmax = 0
            for i in range(s+1, e+1):
                if not dp[i][e]:
                    dp[i][e] = lds_memoization(A, i, e, dp)
                if A[s]>A[i]:
                    currmax = max(currmax, 1 + dp[i][e])
                else:
                    currmax = max(currmax, dp[i][e])
            dp[s][e] = currmax
            return dp[s][e]
        else:
            dp[s][e]=0
            return dp[s][e]
    else:
        return dp[s][e]

class Solution:
    def solve(self, A):
        n = len(A)
        dp = [[None]*n for x in range(n)]

        for e in range(len(A)):
            lds_memoization(A, 0, e, dp)
        print(dp)
        return dp[0][len(A)-1]



A = [1, 11, 2, 10, 4, 5, 2, 1]
# A = [1, 11, 2, 10]
solution = Solution()
print(solution.solve(A))
