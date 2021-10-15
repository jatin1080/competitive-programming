def algo(A):
    n = len(A)
    oddsum = 0
    evensum = A[0]
    oddsumuntil = [0] * n
    evensumuntil = [0] * n

    evensumuntil[0] = A[0]

    for i in range(1, n):
        if i%2==0:
            evensum += A[i]
            evensumuntil[i] = evensumuntil[i-1] + A[i]
            oddsumuntil[i] = oddsumuntil[i-1]
        else:
            oddsum += A[i]
            evensumuntil[i] = evensumuntil[i-1]
            oddsumuntil[i] = oddsumuntil[i-1] + A[i]

    special = 0
    # print(A)
    # print(oddsum)
    # print(evensum)
    # print(oddsumuntil)
    # print(evensumuntil)
    for i in range(n):
        if i%2 == 0:
            newoddsum = (oddsumuntil[i]) + (evensum - evensumuntil[i])
            newevensum = (evensumuntil[i] - A[i]) + (oddsum - oddsumuntil[i])
        else:
            newoddsum = (oddsumuntil[i] - A[i]) + (evensum - evensumuntil[i])
            newevensum = (evensumuntil[i]) + (oddsum - oddsumuntil[i])
        # print('newoddsum', newoddsum, 'newevensum', newevensum)
        if newoddsum == newevensum: special +=1

    return special

class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        ans = algo(A)
        return ans


A = [2, 1, 6, 4]
# A = [5, 5, 2, 5, 8]
solution = Solution()
print(solution.solve(A))