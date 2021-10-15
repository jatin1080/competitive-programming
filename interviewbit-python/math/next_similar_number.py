class Solution:
    def solve(self, A):
        ret = ''
        n = len(A)
        index = None
        for i in range(n-2, -1, -1):
            ch = A[i]
            if A[i] < A[i+1]:
                index = i
                break

        if index == None: return -1
        # find minimum number greater than A[index]
        curr_max = A[index+1]
        max_index = index+1
        for j in range(index+1, n):
            if A[j] > A[index] and A[j] < curr_max:
                curr_max = A[j]
                max_index = j

        B = A[:index+1]
        C = A[max_index]
        

        return index


A = '1344'
solution = Solution()
print(solution.solve(A))

