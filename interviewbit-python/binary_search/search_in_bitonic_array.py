def find_bitonic(A):
    n = len(A)
    if n<=2: return -1
    start = 0
    end = n-1
    while(start<=end):
        mid = int((start+end)/2)
        if A[mid]>A[mid+1] and A[mid]>A[mid-1]:
            return mid
        elif A[mid]>A[mid-1] and A[mid]<A[mid+1]:
            start = mid+1
        else:
            end = mid-1

    return -1

def binary_search(A, B, start, end):
    while(start<=end):
        mid = int((start+end)/2)
        if A[mid]==B:
            return mid
        elif B>A[mid]:
            start = mid+1
        else:
            end = mid-1
    return -1

def binary_search_decreasing(A, B, start, end):
    while(start<=end):
        mid = int((start+end)/2)
        if A[mid]==B:
            return mid
        elif B>A[mid]:
            end = mid-1
        else:
            start = mid+1
    return -1

def algo(A, B):
    n = len(A)
    bitonic_index = find_bitonic(A)
    search_index = binary_search(A, B, 0, bitonic_index)
    if search_index == -1:
        search_index = binary_search_decreasing(A, B, bitonic_index, n-1)
    print((bitonic_index, search_index))
    return search_index


class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        ans = algo(A, B)
        return ans

A = [1, 3, 5, 7, 9, 8, 6, 4, 2]
A = [1, 3, 5, 7, 9, 8, 6, 4]
B = 1
solution = Solution()
print(solution.solve(A, B))