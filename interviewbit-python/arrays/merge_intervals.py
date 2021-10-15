def algo(A, B):
    n = len(A)
    bstart = B[0]
    bend = B[1]
    ret = []
    merged = False
    merging = False
    merged_start = None
    merged_end = None
    for i in range(n):
        s = A[i][0]
        e = A[i][1]
        if merged:
            ret.append(A[i])
        else:
            if merging:
                if bend < s:
                    merged_end = bend
                    ret.append([merged_start, merged_end])
                    merged = True
                else:
                    continue
            else:
                if bstart<s:
                    if bend<s:
                        ret.append(B)
                        merged = True
                    else:
                        merged_start = bstart
                        merging = True
                elif bstart>=s and bstart<=e:
                    if bend<=e:
                        ret.append(min(bstart, s), max(bend, e))
                        merged = True
                    else:
                        merged_start = min(bstart, s)
                        merging = True
                else:
                    ret.append(A[i])
    return ret

# def algo_2(A, B):
#     n = len(A)
#     ret = []
#     bstart = B[0]
#     bend = B[1]
#     merged_start = -1
#     merged_end = -1
#     previous_end = 0
#     start_found = False
#     start_ind = None
#     end_ind = None
#     for i in range(n):
#         s = A[i][0]
#         e = A[i][1]
#         if bstart <= e and bstart > previous_end:
#             start_ind = i
#             start_found = True
#
#         if start_found:
#             if bend <= e and bend > previous_end:
#                 end_ind = i
#
#         previous_end = e
#
#     for i in range(n):
#         if i>= start_ind and i<=end_ind:
#
#         else:
#             ret.append(A[i])
#
#
#     return ret

def algo_3(A, B):
    n = len(A)
    ret = []
    merged_start = -1
    merged_end = -1
    merged = False
    if B[1] < A[0][0]:
        ret.append(B)
        merged = True

    for i in range(n):
        if B[1]<A[i][0] or B[0]>A[i][1]:
            if merged_start != -1 and not merged:
                ret.append([merged_start, B[1]])
                merged = True
            if B[1]<A[i][0] and merged_start == -1:
                ret.append(B)
                merged = True
            ret.append(A[i])
        else:
            if merged_start == -1: merged_start = min(B[0], A[i][0])
            if merged_end == -1:
                if B[1] <= A[i][1]:
                    merged_end = max(B[1], A[i][1])

            if merged_start != -1 and merged_end != -1:
                ret.append([merged_start, merged_end])
                merged = True

    if not merged:
        if merged_start != -1:
            ret.append([merged_start, B[1]])
        else:
            ret.append(B)

    return ret

def algo_4(A, B):
    n = len(A)
    ret = []
    left = right = 0
    s = B[0]
    e = B[1]

    for x in A:
        if e<x[1]:
            ret.append(B)
        if s>=x[0] and s<=x[1]:


class Solution:
    # @param intervals, a list of Intervals
    # @param new_interval, a Interval
    # @return a list of Interval
    def insert(self, A, B):
        ans = algo_3(A, B)
        return ans


# A = [[1,2],[3,5],[6,7],[8,10],[12,16]]
# B = [4,9]
# A = [[1,3],[6,9]]
# B = [2,5]
A = [[1,2], [8,10]]
B = [3,6]
solution = Solution()
print(solution.insert(A, B))