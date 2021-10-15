def algo(A, B):
    n = len(A)
    if n==1: return B
    maximum_height = max(A)
    # search for minimum h in 1 to max
    start = 1
    end = maximum_height
    dp = [0]*n #stores the woodsum
    while start<=end:
        mid = int((start+end)/2)
        woodsum = 0
        reduced_woodsum = 0
        for x in A:
            if x-mid>0: woodsum += x-mid
            if x-mid-1>0: reduced_woodsum += x-mid-1

        if woodsum>=B and reduced_woodsum<B:
            return mid
        elif woodsum>=B and reduced_woodsum>=B:
            start = mid+1
        elif woodsum<B:
            end = mid-1

    return -1


class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        ans = algo(A, B)
        return ans

A = [20, 15, 10, 17]
B = 7
A = [4, 42, 40, 26, 46]
B = 20
solution = Solution()
print(solution.solve(A, B))