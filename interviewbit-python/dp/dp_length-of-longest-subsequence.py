# def lis_memoization(A, s, e, dp):
#     # print((s,e), end=' ')
#     if not dp[s][e]:
#         if s == len(A)-1 and s==e:
#             if not dp[s][e]:
#                 dp[s][e] = 1
#             return dp[s][e]
#         if s==e:
#             if not dp[s][e]:
#                 dp[s][e] = 1
#             return dp[s][e]
#         elif s<e:
#             currmax = 0
#             for i in range(s+1, e+1):
#                 if not dp[i][e]:
#                     dp[i][e] = lis_memoization(A, i, e, dp)
#                 if A[s]<A[i]:
#                     currmax = max(currmax, 1 + dp[i][e])
#                 else:
#                     currmax = max(currmax, dp[i][e])
#             dp[s][e] = currmax
#             return dp[s][e]
#         else:
#             dp[s][e]=0
#             return dp[s][e]
#     else:
#         return dp[s][e]
#
# def lds_memoization(A, s, e, dp):
#     # print((s,e), end=' ')
#     if not dp[s][e]:
#         if s == len(A)-1 and s==e:
#             if not dp[s][e]:
#                 dp[s][e] = 1
#             return dp[s][e]
#         if s==e:
#             if not dp[s][e]:
#                 dp[s][e] = 1
#             return dp[s][e]
#         elif s<e:
#             currmax = 0
#             for i in range(s+1, e+1):
#                 if not dp[i][e]:
#                     dp[i][e] = lds_memoization(A, i, e, dp)
#                 if A[s]>A[i]:
#                     currmax = max(currmax, 1 + dp[i][e])
#                 else:
#                     currmax = max(currmax, dp[i][e])
#             dp[s][e] = currmax
#             return dp[s][e]
#         else:
#             dp[s][e]=0
#             return dp[s][e]
#     else:
#         return dp[s][e]

class Solution:
    def solve(self, A):
        n = len(A)
        # dpi = [[None]*n for x in range(n)]
        # dpd = [[None]*n for x in range(n)]
        #
        # for e in range(len(A)):
        #     lis_memoization(A, 0, e, dpi)
        # for e in range(len(A)):
        #     lds_memoization(A, 0, e, dpd)
        #
        # ans = 0
        # for i in range(len(A)-1):
        #     a = dpi[0][i]
        #     b = dpd[i][len(A)-1]
        #     ans = max(ans, a+b-1)
        #
        #     if ans <=2: ans =0

        inc = [1]*(n)
        dec = [1]*(n)

        for i in range(n):
            currinc = inc[i]
            for j in range(0, i+1):
                if A[i]>A[j]:
                    inc[i] = max(inc[j]+1, inc[i])

        for i in range(n-1, -1, -1):
            currdec = dec[i]
            for j in range(i+1, n):
                if A[i]>A[j]:
                    dec[i] = max(dec[j] + 1, dec[i])

        # print(inc)
        # print(dec)

        sum = [inc[i] + dec[i] - 1 for i in range(n)]
        ans = max(sum)


        return ans



A = [1, 11, 2, 10, 4, 5, 2, 1]
# A = [1, 11, 2, 10]
# A = [1, 1, 2, 2, 3, 4]
# A = [ 263, 202, 191, 333, -10, 362, 328, 74, 66, 60, 267, 342, 140, 237, 386, 151, 18, 201, 319, 277, 180, 4, 410, 444, 206, 406, 179, 113, 193, 130, 370, 221, 499, 53, 322, 1, 339, 487, 151, 76, 209, 148, 267, 380, 464, -8, 444, 190, 16, 322, 458, 440, 295, 394, 417, 108, 315, 143, 436, 65, 402, 439, 331, 494, 164, 312, 410, 492, 171, 308, 3, 407, 40, 361, 25, 235, 274, 452, 315, 468, 309, 486, 21, 468, -8, 450, 131, 19, 151, 463, -2, 464, 401, 29, 179, 180, 261, 350, 451, 62, 155, 189, 266, 174, 64, -3, 106, 225, 78, 417, 13, 221, 106, 327, 455, -2, 149, 267, 274, 345, 112, 320, 277, 325 ]
solution = Solution()
print(solution.solve(A))
