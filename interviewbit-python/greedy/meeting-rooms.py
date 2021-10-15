def algo(A):
    # print(A)
    B = []
    n = len(A)
    count = 0
    for i in range(n):
        s = A[i][0]
        e = A[i][1]
        emptyconferenceroom = False
        for j in range(len(B)):
            if s >= B[j]:
                B[j] = e
                emptyconferenceroom = True
                break
        if(not emptyconferenceroom):
            B.append(e)
            count += 1
        # print(B)
    return count

def algo_2(A):
    startsorted = sorted([x[0] for x in A])
    endsorted = sorted([x[1] for x in A])
    print(startsorted)
    print(endsorted)
    n = len(startsorted)
    count = 1
    p, q = 1, 0
    while p < n and q < n:
        if startsorted[p] < endsorted[q]:
            count += 1
            p += 1
        else:
            p += 1
            q += 1

    return count

class Solution:
    def solve(self, A):
        # def sorting_function(e):
        #     return e[0]
        # ans = algo(sorted(A, key=sorting_function))
        print(A)
        ans = algo_2(A)
        return ans


# A = [[0, 30], [5, 10], [15, 20]]
A =  [[1, 18], [18, 23] ,[15, 29] ,[4, 15] ,[2, 11] ,[5, 13]]
solution = Solution()
print(solution.solve(A))