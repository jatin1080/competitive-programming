def algo(n):
    ret = [[None]*n for x in range(n)]
    x,y = 0,0
    llimit, rlimit, tlimit, blimit = 0, n-1, 1, n-1
    direction = 0
    for i in range(1, n**2+1):
        # print(x,y)
        # print(llimit, rlimit, tlimit, blimit)
        ret[x][y] = i
        # print(ret)
        if (direction==2 and y==llimit):
            direction = (direction+1)%4
            llimit +=1
        elif (direction==0 and y==rlimit):
            direction = (direction+1)%4
            rlimit -=1
        elif (direction==3 and x==tlimit):
            direction = (direction+1)%4
            tlimit+=1
        elif (direction==1 and x==blimit):
            blimit-=1
            direction = (direction+1)%4

        if direction == 0:
            y+=1
        elif direction == 1:
            x+=1
        elif direction == 2:
            y-=1
        elif direction == 3:
            x-=1
    return ret

class Solution:
	# @param A : integer
	# @return a list of list of integers
	def generateMatrix(self, A):
        ans = algo(A)
        return ans

A = 7
solution = Solution()
print(solution.generateMatrix(A))