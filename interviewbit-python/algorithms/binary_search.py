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
    # print(A)
    s, e = 0, len(A)-1
    mid = ul
    currans = -1
    while s<=e:
        index = s + (e-s)//2
        mid = A[index]
        # print((s, e, mid), end='')
        if mid>=ul:
            e = index-1
        else:
            currans = mid
            s = index+1
    # print()
    return currans



# N = input("input N: ")
# A = [x for x in range(1, int(N)+1)]
A = [2, 5, 3, 1, 4, 9]
# A = [10, 13, 14, 15, 17, 67, 68, 70]
# A = [10]
print(A)
n = int(input("input n: "))
print(' {0}'.format(bsearch_upperlimit(A, n)))