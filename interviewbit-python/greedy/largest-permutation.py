def algo(A, B):
    ret = A[:]
    n = len(A)
    index = 0
    indexes = [-1]*(n+1)
    for x in range(n):
        v = A[x]
        indexes[v] = x
    print(A)
    print(indexes)
    while index < n and B>=1:
        print(A)
        value = n - index
        if A[index] == value:
            index +=1
        else:
            # swap
            # i = A.index(value)
            curr = A[index]
            i = indexes[value]
            print(value, curr, i)
            A[i] = curr
            A[index] = value

            # update indexes
            indexes[value] = index
            indexes[curr] = i

            B-=1
            index+=1
    return A

def algo_1(A, B):
    print(A, B)
    N = len(A)
    if N == 1 or B == 0:
        return A[:]

    if A[0] == N:
        r = algo(A[1:], B)
        print('r', r)
        ret = [A[0]] + r
    else:
        r = algo(A[1:], B-1)
        print('r', r)
        ret = [A[0]] + r
    return ret

class Solution:
    def solve(self, A, B):
        ans = algo(A, B)
        return ans

A = [1, 2, 3, 4]
B = 1
# A = [ 1, 2 ]
# B = 2
# A = [ 3, 2, 4, 1, 5 ]
# B = 3
solution = Solution()
print(solution.solve(A, B))