import bisect, sys

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
                ret += len(self.data[R - 1]) - bisect.bisect(self.data[R - 1], k)
            if L & 1:
                ret += len(self.data[L - 1]) - bisect.bisect(self.data[L - 1], k)
                L += 1
            L >>= 1
            R >>= 1
        return ret

if __name__ == '__main__':
    input = sys.stdin.readline
    N = int(input())
    A = list(map(int, input().split()))
    Q = int(input())
    L = 0

    ST = MergesortTree(N)
    for i, s in enumerate(A):
        ST.set(i, s)
    ST.build()
    for _ in range(Q):
        i, j, k = map(int, input().split())
        i ^= L; j ^= L; k ^= L
        L = ST.greater(i - 1, j, k)
        print(L)