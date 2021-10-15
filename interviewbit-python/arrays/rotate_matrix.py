def algo(A):
    n = len(A)
    shitfted_origin = (n//2, n//2)

    for y in range(n//2):
        for x in range(n//2):
            nx, ny = x - shitfted_origin[0], y - shitfted_origin[1]
            nx, ny = abs(nx), abs(ny)
            # consider four points
            # x1, y1 = nx, ny
            # x2, y2 = -1*nx, ny
            # x3, y3 = nx, -1*ny
            # x4, y4 = -1*nx, -1*ny
            arr = [(nx, ny), (-1*nx, ny), (nx, -1*ny), (-1*nx, -1*ny)]
            # rotate these four points
            values = []
            for point in arr:
                px = point[0] + shitfted_origin[0]
                py = point[1] + shitfted_origin[1]
                values.append(A[px][py])

            for i in range(4):
                p = arr[i]
                px = p[0] + shitfted_origin[0]
                py = p[1] + shitfted_origin[1]
                copyfrom = (i+1)%4
                A[px][py] = values[copyfrom]
    return A

def algo_2(A, start, length):
    # base case
    # print()
    # print(length, start)
    n = length
    if n==1 or n==0:
        return A

    if n>=2:
        # select four points and rotate until the first row is all over
        for i in range(n-1):
            # select four points
            p1 = (start[0], start[1]+i)
            p2 = (start[0]+i, start[1]+n-1)
            p3 = (start[0]+n-1, start[1]+n-1-i)
            p4 = (start[0]+n-1-i, start[1])
            points = [p1, p2, p3, p4]
            # print(n, start, points)
            values = [A[p[0]][p[1]] for p in points]
            # print('values before', values)
            # print('A', A)
            # rotate values for these four points
            values = values[-1:] + values[:-1]
            # print('values after', values)
            for i,p in enumerate(points):
                A[p[0]][p[1]] = values[i]
            # print('A', A)
        algo_2(A, (start[0]+1, start[1]+1), length-2)
    return A



class Solution:
    # @param A : list of list of integers
    # @return the same list modified
    def rotate(self, A):
        ans = algo_2(A, (0,0), len(A))
        return ans

A = []
n = 4
num = 1
for x in range(n):
    B = []
    for y in range(n):
        B.append(num)
        num +=1
    A.append(B)
print(A)
solution = Solution()
print(solution.rotate(A))