def algo(A):
    n = len(A)
    min_val = min(A)
    max_val = max(A)
    maxofboth = max(abs(min_val), abs(max_val))
    # print(maxofboth)
    squares = [None]*((maxofboth**2)+1)
    occurence = [None]*((maxofboth**2)+1)
    for x in A:
        # print(squares)
        curr = abs(x)
        sq = curr**2
        if not squares[sq]:
            squares[sq] = sq
            occurence[sq] = 1
        else:
            occurence[sq] +=1
    ret = []
    # print(squares)
    for s in squares:
        if s != None:
            # print(s)
            for x in range(occurence[s]):
                ret.append(s)

    return ret

def algo_2(A):
    n = len(A)
    ret = []
    i, j = 0, n-1
    while i<=j:
        if abs(A[j])>abs(A[i]):
            ret.append(A[j]**2)
            j-=1
        else:
            ret.append(A[i]**2)
            i+=1
    return ret[::-1]

class Solution:
    # @param A : list of integers
    # @return a list of integers
    def solve(self, A):
        ans = algo_2(A)
        return ans


A = [4, 5, 2, 10, 8]
solution = Solution()
print(solution.solve(A))