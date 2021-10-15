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
import sys
class Solution:
    # @param A : string
    # @param B : string
    # @return an integer
    def solve(self, A, B):
        sys.setrecursionlimit(2500)
        print(sys.getrecursionlimit())
        dp = [[None]*len(B) for x in range(len(A))]
        ans = lcs(A, B, len(A)-1, len(B)-1, dp)
        return ans


# A = input("Input first string for LCS: ")
# B = input("Input second string for LCS: ")

# A, B = 'aaadabaaebce', 'cbbcacdcdadc'
# A, B = 'ABCDGH', 'AEDFHR'
A, B = 'bebdeeedaddecebbbbbabebedc', 'abaaddaabbedeedeacbcdcaaed'
dp = [[-1]*len(B)]*len(A)
solution = Solution()
print(solution.solve(A,B))

