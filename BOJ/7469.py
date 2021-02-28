import bisect
from sys import stdin
input = stdin.readline

class MergesortTree():

    def __init__(self, n):
        self.n = 2 ** (n - 1).bit_length()
        self.data = [[] for _ in range(2 * self.n)]

    def set(self, k, v):
        self.data[k + self.n - 1].append(v)

    def build(self):
        for k in reversed(range(self.n - 1)):
            A, B = self.data[k * 2 + 1], self.data[k * 2 + 2]
            i = j = 0
            while i < len(A) and j < len(B):
                if A[i] < B[j]: self.data[k].append(A[i]); i += 1
                else: self.data[k].append(B[j]); j += 1
            while i < len(A): self.data[k].append(A[i]); i += 1
            while j < len(B): self.data[k].append(B[j]); j += 1

    def greater(self, l, r, k):
        L = l + self.n
        R = r + self.n
        ret = 0
        while L < R:
            if R & 1:
                R -= 1
                ret += bisect.bisect(self.data[R - 1], k)
            if L & 1:
                ret += bisect.bisect(self.data[L - 1], k)
                L += 1
            L >>= 1
            R >>= 1
        return ret

if __name__ == '__main__':
    # input
    N, Q = map(int, input().split())
    A = list(map(int, input().split()))

    # construct
    mergesort_tree = MergesortTree(N)
    for i, s in enumerate(A):
        mergesort_tree.set(i, s)
    mergesort_tree.build()

    # query
    for _ in range(Q):
        i, j, k = map(int, input().split())
        # parametric search
        L = -1000000001
        R = 1000000000
        while L + 1 < R:
            mid = (L + R) // 2
            k_i = mergesort_tree.greater(i - 1, j, mid)
            if k_i >= k:
                R = mid
            else:
                L = mid
        print(R)
