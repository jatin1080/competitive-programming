def lcs(A, B, ea, eb, dp):
    # print((ea, eb), end=' ')
    if dp[ea][eb] == None:
        if ea==0:
            if A[ea] in B[:eb+1]:
                dp[ea][eb] = 1
            else:
                dp[ea][eb] = 0
            return dp[ea][eb]

        if eb==0:
            if B[eb] in A[:ea+1]:
                dp[ea][eb] = 1
            else:
                dp[ea][eb] = 0
            return dp[ea][eb]

        if A[ea] == B[eb]:
                if dp[ea-1][eb-1] == None:
                    dp[ea-1][eb-1] = lcs(A, B, ea-1, eb-1, dp)
                dp[ea][eb] = 1 + dp[ea-1][eb-1]
                return dp[ea][eb]
        else:
            if dp[ea][eb-1] == None:
                dp[ea][eb-1] = lcs(A, B, ea, eb-1, dp)
            if dp[ea-1][eb] == None:
                dp[ea-1][eb] = lcs(A, B, ea-1, eb, dp)

            dp[ea][eb] = max(dp[ea][eb-1], dp[ea-1][eb])
            return dp[ea][eb]
    else:
        return dp[ea][eb]

def algo_memoization(A, B, sa, sb, dp):
    if not dp[sa][sb]:
        if sa >= len(A):
            return len(B) - sb
        if sb >= len(B):
            return len(A) - sa

        if sa == len(A)-1:
            if not dp[sa][sb]:
                if A[sa] in B[sb:]:
                    dp[sa][sb] = len(B) - sb - 1
                else:
                    dp[sa][sb] = len(B) - sb
            return dp[sa][sb]

        if sb == len(B)-1:
            if not dp[sa][sb]:
                if B[sb] in A[sa:]:
                    dp[sa][sb] =  len(A) - sa - 1
                else:
                    dp[sa][sb] = len(A) - sa
            return dp[sa][sb]

        if A[sa] == B[sb]:
            if not dp[sa][sb]:
                dp[sa][sb] = 1 + algo_memoization(A, B, sa+1, sb+1, dp)
            return dp[sa][sb]
        else:
            if not dp[sa+1][sb+1]:
                dp[sa+1][sb+1] = algo_memoization(A, B, sa+1, sb+1, dp)
            if not dp[sa+1][sb]:
                dp[sa+1][sb] = algo_memoization(A, B, sa+1, sb, dp)

            dp[sa][sb] = 1 + min(dp[sa+1][sb+1], dp[sa+1][sb])
            return dp[sa][sb]
    else:
        return dp[sa][sb]

def algo_tabulation(A, B):
    dp = [[None]*len(B) for x in range(len(A))]

    return dp

class Solution:
    def solve(self, A, B):
        # sys.setrecursionlimit(2500)
        # dp1 = [None]*len(A)
        print(A, len(A))
        print(B, len(B))
        print([x for x in enumerate(A)])
        print([x for x in enumerate(B)])
        dp2 = [[None]*len(B) for x in range(len(A))]
        ans = algo_memoization(A, B, 0, 0, dp2)

        # lcs_length = lcs(A, B, len(A)-1, len(B)-1, dp2)
        # ans = insertions + deletions + replace
        # if len(A)==len(B): # only replace
        #     ans = len(B) - lcs_length
        # elif len(A)>len(B): # replace and deletions
        #     ans = len(B) - lcs_length + len(A) - len(B)
        # else: # insertions and replace
        #     lcs_length = lcs_length + len(B) - len(A) # lcs_length increased by the number of insertions made
        #     ans = len(B) - lcs_length # now ans is only replace
        # print(len(A), len(B), lcs_length)

        return ans


A = 'first string'
B = 'second string'
# A = 'abad'
# B = 'abac'
solution = Solution()
print(solution.solve(A, B))

