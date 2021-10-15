class Solution:
    def solve(self, A, B):
        n = len(A)
        continuous_zeros = 0
        can_be_lit = True
        l = 0
        r = 0
        for i in range(B):
            if A[i] == 0: l +=1
            else: l = 0
            if A[-1-i] == 0: r +=1
            else: r = 0
        if l>=B or r>=B: can_be_lit = False

        if(can_be_lit):
            for i in range(n):
                if A[i] == 0:
                    continuous_zeros +=1
                else:
                    continuous_zeros = 0
            if continuous_zeros >= 2*(B-1)+1: can_be_lit = False

        # if not can_be_lit: return -1
        #
        # corridor_lit = [0]*n
        # for i in range(B-1, n):
        #     all_lit_in_range = False
        #     for j in range(B):
        #         if corridor_lit
        #

        return can_be_lit


A = [0, 0, 1, 1, 0, 0, 0, 1]
B = 3
solution = Solution()
print(solution.solve(A, B))