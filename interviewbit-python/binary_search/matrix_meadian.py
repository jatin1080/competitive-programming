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

def partition_length(A, x):
    n = len(A)
    m = len(A[0])
    # for x to be median B and C must be greater than and equal to ((n*m)+1)/2
    # B is the number of elements <= x in A
    # C is the number of elements >= x in A
    B, C = 0, 0
    for row in A:
        B += count_lesser_or_equal(row, x)
        C += count_greater_or_equal(row, x)
    # for row in A:
    #     for a in row:
    #         if a<=x: B+=1
    #         if a>=x: C+=1
    return (B, C)

def algo(A):
    n = len(A)
    m = len(A[0])
    max_median = 10**9
    min_median = 1
    # for row in A:
    #     if row[m-1]>max_median: max_median = row[m-1]
    #     if row[0]<min_median: min_median = row[0]

    while(min_median<=max_median):
        # assume a median between min to max
        mid = int((max_median+min_median)/2)
        # calculate things needed to decide if this is the actual median
        B, C = partition_length(A, mid)
        # print(mid, (B,C))
        if B>=((n*m)+1)/2 and C>=((n*m)+1)/2:
            return mid
        elif B>C:
            max_median = mid-1
        else:
            min_median = mid+1
    return -1

class Solution:
    # @param A : list of list of integers
    # @return an integer
    def findMedian(self, A):
        # print(A)
        ans = algo(A)
        return ans

A = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
A = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
A = [   [5, 17, 100]    ]
A = [
  [5],
  [4],
  [3],
  [1],
  [3],
  [1],
  [4],
  [2],
  [5],
  [3],
  [3]
]
A = [
  [1, 1, 3, 3, 3, 3, 3]
]
A = [
  [2, 3, 11, 12, 29],
  [12, 16, 20, 21, 29],
  [6, 9, 21, 27, 30]
]
solution = Solution()
print(solution.findMedian(A))