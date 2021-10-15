class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        n = len(A)
        max_sum = 0

        for i in range(B):
            max_sum += A[i]

        curr_sum = max_sum

        for i in range(B):
            curr_sum = curr_sum - A[B-i-1] + A[-1*i-1]
            if curr_sum > max_sum:
                max_sum = curr_sum

        return max_sum




A = [5, -2, 3 , 1, 2]
B = 3
solution = Solution()
print(solution.solve(A, B))