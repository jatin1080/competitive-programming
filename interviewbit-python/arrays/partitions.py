def algo(A, B):
    n = B
    if n<=2: return 0
    if n==3:
        if A[0]==A[1]==A[2]: return 1
        else: return 0
    total = sum(A)
    if total%3 != 0: return 0
    left, mid, right = 0,0,0
    ret = 0
    for i in range(0, n-2):
        left+=A[i]
        mid = 0
        for j in range(i+1, n-1):
            mid += A[j]
            right = total-mid-left
            if(left == mid == right):
                ret +=1
    return ret

def algo_3(A, B):
    n = B
    if n<=2: return 0
    if n==3:
        if A[0]==A[1]==A[2]:
            return 1
        else:
            return 0
    total = sum(A)
    if total%3 != 0: return 0
    lind = [0]*n
    rind = [0]*n
    leftsumprefix = 0
    rightsumsuffix = total
    currleftsum = 0
    currrightsum = total
    for i in range(n):
        currleftsum += A[i]
        if i-1>=0: currrightsum -= A[i-1]
        if currleftsum == total/3: lind[i] = 1
        if currrightsum == total/3: rind[i] = 1

    # print(A)
    # print(lind)
    # print(rind)

    # ret = 0
    # rightnum = sum(rind[1:])
    # for i in range(0, n-2):
    #     if rind[i+1]==1: rightnum-=1
    #     if lind[i]==1:
    #         ret += rightnum

    ret = 0
    for i in range(n-2):
        if lind[i]==1: ret += sum(rind[i+2:])

    return ret

class Solution:
    # @param A : integer
    # @param B : list of integers
    # @return an integer
    def solve(self, A, B):
        ans = algo(A, B)
        ans_3 = algo_3(A, B)
        return (ans, ans_3)

A = [1, 2, 3, 0, 3]
# B = 5
# A = [0, 1, -1, 0]
# B = 4
# A = [0, 0, 0, 0, 0, 0, 0, 0, 0 ]
# B = 2
# A = [3, 3, -3, 3, 3]
solution = Solution()
print(solution.solve(A, len(A)))