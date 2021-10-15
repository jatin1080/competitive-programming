def bsearch_itr(A, n):
    s = 0
    e = len(A)-1
    while s<=e:
        print('h', end='')
        index = s + (e-s)//2
        mid = A[index]
        if mid == n:
            return index
        else:
            if mid>n:
                e = index-1
            else:
                s = index+1
    return -1

def bsearch_upperlimit(A, ul):
    s, e = 0, len(A)-1
    mid = ul
    currans = -1
    while s<=e:
        index = s + (e-s)//2
        mid = A[index]
        if mid>=ul:
            e = index-1
        else:
            currans = mid
            s = index+1
    return currans

def bsearch_upperlimit_index(A, ul):
    s, e = 0, len(A)-1
    mid = ul
    currans = -1
    while s<=e:
        index = s + (e-s)//2
        mid = A[index]
        if mid>=ul:
            e = index-1
        else:
            currans = index
            s = index+1
    return currans

def maxuntilnow(A):
    if len(A) < 2: return A
    aa = []
    aa.append(A[0])
    for i in range(1, len(A)):
        aa.append(max(A[i], aa[i-1]))

    aaa = []
    for i in range(len(A)):
        a = -1
        for j in range(i-1, -1, -1):
            if aa[j]<A[i]:
                a = aa[j]
                break
        aaa.append(a)

    print(aaa)

def maxsuffix(A):
    cc = [-1]*len(A)
    for i in range(len(A)-2, -1, -1):
        x = max(cc[i+1], A[i+1])
        if x>A[i]:
            cc[i]=x

    print(len(cc), cc)

def solve(A):
    ret = 0

    aa = [-1]*len(A)
    sortedA_indexes = []
    for i in range(1, len(A)-1):
        index = bsearch_upperlimit_index(sortedA, A[i-1])
        sortedA.insert(index+1, A[i-1])
        aa[i] = bsearch_upperlimit(sortedA, A[i])

    cc = [-1]*len(A)
    for i in range(len(A)-2, -1, -1):
        x = max(cc[i+1], A[i+1])
        if x>A[i]:
            cc[i]=x

    for i in range(1, len(A)-1):
        b = A[i]
        a = aa[i]
        c = cc[i]
        if a==-1 or c==-1: continue
        if a<b<c: ret = max(ret, a+b+c)

    return ret



A = [ 18468, 6335, 26501, 19170, 15725, 11479, 29359, 26963, 24465, 5706, 28146, 23282, 16828, 9962, 492, 2996, 11943, 4828, 5437, 32392, 14605 ]
print(len(A), A)
print(solve(A))
# print(maxuntilnow(A))