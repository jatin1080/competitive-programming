def algo(A):
    p_row = [1]
    row = [1, 1]
    if A == 0: return p_row
    if A == 1: return row
    for i in range(2, A+1):
        p_row = row
        row = []
        row.append(1)
        for j in range(1, i):
            row.append(p_row[j] + p_row[j-1])
        row.append(1)

    return row

class Solution:
    # @param A : integer
    # @return a list of integers
    def getRow(self, A):
        ans = algo(A)
        return ans

A = 3
solution = Solution()
print(solution.getRow(A))