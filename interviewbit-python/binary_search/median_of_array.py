def count_greater_or_equal(R, x):
    m = len(R)
    # basically find the element index which is just lesser than x
    start = 0
    end = m-1
    if R[0]>=x: return m
    if R[m-1]<x: return 0
    while(start<=end):
        mid = int((start+end)/2)
        if R[mid]>=x and R[mid-1]<x:
            return (m-1)-mid+1
        elif R[mid]>=x and R[mid-1]>=x:
            end = mid - 1
        else:
            start = mid+1
    return 0

def count_lesser_or_equal(R, x):
    m = len(R)
    # basically find the element index which is just lesser than x
    start = 0
    end = m-1
    if R[0]>x: return 0
    if R[m-1]<=x: return m
    while(start<=end):
        mid = int((start+end)/2)
        if R[mid]<=x and R[mid+1]>x:
            return mid+1
        elif R[mid]<=x and R[mid+1]<=x:
            start = mid+1
        else:
            end = mid - 1
    return 0

def partition_length(A, B, x):
    n = len(A)
    m = len(B)
    # for x to be median B and C must be greater than and equal to ((n*m)+1)/2
    # B is the number of elements <= x in A
    # C is the number of elements >= x in A
    C, D = 0, 0
    C += count_lesser_or_equal(A, x)
    C += count_lesser_or_equal(B, x)
    D += count_greater_or_equal(A, x)
    D += count_greater_or_equal(B, x)
    # for row in A:
    #     for a in row:
    #         if a<=x: B+=1
    #         if a>=x: C+=1
    return (C, D)

def algo(A, B):
    n = len(A)
    m = len(B)
    if n==1 and m==0:
        return A[0]
    elif n==0 and m==1:
        return B[0]
    elif n==1 and m==1:
        return (A[0]+B[0])/2

    max_median = max(A[n-1], B[m-1])
    min_median = min(A[0], B[0])
    while min_median<=max_median:
        # assume a median between min to max
        mid = int((max_median+min_median)/2)
        # calculate things needed to decide if this is the actual median
        C, D = partition_length(A, B, mid)
        print(min_median, mid, max_median, (C,D))
        # if (n+m)%2==0 and C>=((n+m))/2 and D>=((n+m))/2:
        #     # if C>=((n+m))/2 and D>=((n+m))/2:
        #     return mid # change this
        # elif (n+m)%2==1 and C>=((n+m)+1)/2 and D>=((n+m)+1)/2:
        if C>=((n+m)+1)/2 and D>=((n+m)+1)/2:
            return mid
        elif C>D:
            max_median = mid-1
        else:
            min_median = mid+1
    return -1

# def algo_2(A, B):
#     n = len(A)
#     m = len(B)
#     if n==1 and m==0:
#         return A[0]
#     elif n==0 and m==1:
#         return B[0]
#     elif n==1 and m==1:
#         return (A[0]+B[0])/2
#
#     # merge the two arrays and return mid?
#
#
#     return -1

class Solution:
    def solve(self, A, B):
        ans = algo(A, B)
        return ans

A = [1, 4, 5]
B = [2, 3, 6, 7, 7, 7, 7, 7]
solution = Solution()
print(solution.solve(A, B))