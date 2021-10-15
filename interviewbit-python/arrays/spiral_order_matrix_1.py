def algo(A):
    m = len(A)
    n = len(A[0])
    (right, bottom, left, top) = (n - 1, m - 1, 0, 1)
    direction = 0
    (x, y) = (0, 0)
    ret = []
    for i in range(m * n):
        ret.append(A[x][y])
        if direction == 2 and y == left:
            direction = (direction + 1) % 4
            left += 1
        elif direction == 0 and y == right:
            direction = (direction + 1) % 4
            right -= 1
        elif direction == 3 and x == top:
            direction = (direction + 1) % 4
            top += 1
        elif direction == 1 and x == bottom:
            bottom -= 1
            direction = (direction + 1) % 4

        if direction == 0:
            y+=1
        elif direction == 1:
            x+=1
        elif direction == 2:
            y-=1
        elif direction == 3:
            x-=1
    return ret

def algo_2(A):
    m = len(A)
    n = len(A[0])
    (right, bottom, left, top) = (n - 1, m - 1, 0, 0)
    direction = 0
    (x, y) = (0, 0)
    ret = []
    while left<=right and top<=bottom:
        if direction == 0:
            for y in range(left, right+1):
                ret.append(A[top][y])
            top+=1
        elif direction == 1:
            for x in range(top, bottom+1):
                ret.append(A[x][right])
            right-=1
        elif direction == 2:
            for y in range(right, left-1, -1):
                ret.append(A[bottom][y])
            bottom-=1
        elif direction == 3:
            for x in range(bottom, top-1, -1):
                ret.append(A[x][left])
            left+=1
        direction = (direction+1)%4
    return ret
class Solution:
	# @param A : tuple of list of integers
	# @return a list of integers
    def spiralOrder(self, A):
        ans = algo_2(A)
        return ans

A = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
solution = Solution()
print(solution.spiralOrder(A))