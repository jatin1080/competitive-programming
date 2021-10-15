def lcs_not_working(A, B, sa, sb):
    ret = 0
    if sa>=len(A) or sb>=len(B):
        return 0

    if sa==len(A)-1:
        if A[sa] in B[sb:]:
            return 1
        else:
            return 0

    if sb==len(B)-1:
        if B[sb] in A[sa:]:
            return 1
        else:
            return 0

    if A[sa]==B[sb]:
        if dp[sa+1][sb+1] == -1:
            dp[sa+1][sb+1] = lcs(A, B, sa+1, sb+1)
        ret = 1 + dp[sa+1][sb+1]
    else:
        if dp[sa][sb+1] == -1:
            dp[sa][sb+1] = lcs(A, B, sa, sb+1)
        if dp[sa+1][sb] == -1:
            dp[sa+1][sb] = lcs(A, B, sa+1, sb)
        ret = max(dp[sa][sb+1], dp[sa+1][sb])

    return ret

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

# A = input("Input first string for LCS: ")
# B = input("Input second string for LCS: ")

A, B = 'ABCDGH', 'AEDFHR' # Ans 3
# A, B = "AGGTAB", "GXTXAYB" # Ans 4
# A, B = 'aaadabaaebce', 'cbbcacdcdadc' # Ans 4
# A, B = 'bebdeeedaddecebbbbbabebedc', 'abaaddaabbedeedeacbcdcaaed'  # Ans 12
dp = [[None]*len(B) for x in range(len(A))]
print(lcs(A, B, len(A)-1, len(B)-1, dp))
print(dp)
