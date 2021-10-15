def algo(A):
    n = len(A)
    G = [-1]*n
    for i in range(1, n):
        print()
        print('i', i)
        if A[i-1] < A[i]:
            G[i] = A[i-1]
            continue
        for j in range(i-1, -1, -1):
            print('j')
            if G[j] < A[i]:
                G[i] = G[j]
                break
    return G

def algo_2(A):
    n = len(A)
    s = []
    G = [-1]*n
    for i in range(n):
        print()
        print('i', i)
        while s and s[-1] >= A[i]:
            print('j')
            s.pop()
        if s and s[-1] < A[i]:
            G[i] = s[-1]
        s.append(A[i])

    return G

class Solution:
    def prevSmaller(self, A):
        ans = algo(A)
        # print(A)
        return ans


A = [4, 5, 2, 10, 8]
# A = [5, 4, 3, 2, 1]
# A = [34, 35, 27, 42, 5, 28, 39, 20, 28]
# G = [-1, 4, -1, 2, 2]
solution = Solution()
print(solution.prevSmaller(A))