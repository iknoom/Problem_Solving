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

    def greater(self, l, r):
        L = l + self.n
        R = r + self.n
        ret = []
        while L < R:
            if R & 1:
                R -= 1
                mid = len(self.data[R - 1]) // 2
                ret.append(self.data[R - 1][mid])
            if L & 1:
                mid = len(self.data[L - 1]) // 2
                ret.append(self.data[L - 1][mid])
                L += 1
            L >>= 1
            R >>= 1
        return ret

def sol(arr, l, r):
    x = bisect.bisect_left(arr, l)
    y = bisect.bisect(arr, r)
    return y - x

if __name__ == '__main__':
    input = sys.stdin.readline
    N, C = map(int, input().split())
    A = list(map(int, input().split()))
    Color_seg = [[] for _ in range(C)]
    Q = int(input())

    ST = MergesortTree(N)
    for i, s in enumerate(A):
        ST.set(i, s - 1)
        Color_seg[s - 1].append(i)
    ST.build()

    for _ in range(Q):
        i, j = map(int, input().split())
        L = ST.greater(i - 1, j)
        ans = -1
        for s in set(L):
            if sol(Color_seg[s], i - 1, j - 1) > (j - i + 1) // 2: ans = s
        if ans < 0:
            print("no")
        else:
            print("yes", ans + 1)