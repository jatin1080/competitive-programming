import time
def solve(A):
    modulus = int(10e9+7)
    ans = 0
    length = len(A)
    if length <= 2: return 0
    if length == 3: return 0 # because the leftSpecialValue is zero
    # for each element from index 1 to length-2
    for i in range(1, length-1):
        # print('index', i)
        # find leftSpecialValue
        leftMax = 0 # since all values are greater than 1
        leftSpecialValue = 0
        for j in range(i-1, -1, -1):
            if A[j] > max(A[i], leftMax):
                leftSpecialValue = j
                break

        rightMax = 0 # since all values are greater than 1
        rightSpecialValue = 0
        for j in range(i+1, length):
            if A[j] > max(A[i], rightMax):
                rightSpecialValue = j
                break

        # print(leftSpecialValue, rightSpecialValue)

        current = ((leftSpecialValue % modulus) * (rightSpecialValue % modulus)) % modulus
        if current > ans: ans = current

    return ans

def solution(A):
    modulus = int(10e9+7)
    ans = 0
    length = len(A)
    if length <= 2: return 0
    if length == 3: return 0 # because the leftSpecialValue is zero
    # for each element from index 1 to length-2

    leftSpecialValue = [0] * length
    for i in range(1, length-1):
        if A[i-1] > A[i]:
            leftSpecialValue[i] = i-1
        else:
            index = i-1
            while(A[index]<=A[i] and index!=0):
                index = leftSpecialValue[index]
            leftSpecialValue[i] = index
    # print(leftSpecialValue)


    rightSpecialValue = [0] * length
    for i in range(length-2, 0, -1):
        if A[i+1] > A[i]:
            rightSpecialValue[i] = i+1
        else:
            index = i+1
            while(A[index]<=A[i] and index!=0):
                index = rightSpecialValue[index]
            rightSpecialValue[i] = index
    # print(rightSpecialValue)

    for i in range(1, length-1):
            current = ((leftSpecialValue[i] % modulus) * (rightSpecialValue[i] % modulus)) % modulus
            if current > ans: ans = current

    return ans


T = int(input())
for i in range(T):
    print('Test case:', i)
    A = [int(x) for x in input().split()]
    start = time.time()
    ans = solution(A)
    end = time.time()
    print('duration: ', end - start)
    print('answer:', ans, '\n')