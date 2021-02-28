from sys import stdin
input = stdin.readline

class SegmentTree():
    def __init__(self, n, func, init):
        self.n = 2 ** (n - 1).bit_length()
        self.init = init
        self.data = [init] * (2 * self.n)
        self.func = func

    def get(self, k):
        k += self.n - 1
        ret = self.data[k]
        while k > 0:
            k = (k - 1) // 2
            ret = self.func(ret, self.data[k])
        return ret

    def update(self, l, r, k):
        L = l + self.n
        R = r + self.n
        while L < R:
            if R & 1:
                R -= 1
                self.data[R - 1] = self.func(self.data[R - 1], k)
            if L & 1:
                self.data[L - 1] = self.func(self.data[L - 1], k)
                L += 1
            L >>= 1
            R >>= 1

if __name__ == "__main__":
    # input
    N = int(input())
    A = list(map(int, input().split()))

    # solution
    segmentTree = SegmentTree(N, int.__add__, 0)
    Q = int(input())
    for _ in range(Q):
        query = list(map(int, input().split()))
        if query[0] == 1:
            a, b, c = query[1:]
            segmentTree.update(a - 1, b, c)
        else:
            a = query[1] - 1
            print(segmentTree.get(a) + A[a])