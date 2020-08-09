import sys
input = sys.stdin.readline
INF = 10 ** 18

class Node:
    def __init__(self):
        self.s = 0
        self.m = -INF
        self.l = -INF
        self.r = -INF

    def __add__(self, other):
        ret = Node()
        ret.s = self.s + other.s
        ret.l = max(self.l, self.s + other.l)
        ret.r = max(other.r, self.r + other.s)
        ret.m = max(self.r + other.l, max(self.m, other.m))
        return ret

class SegmentTree():
    def __init__(self, n):
        self.n = 2 ** (n - 1).bit_length()
        self.data = [Node() for _ in range(2 * self.n)]

    def update(self, k, v):
        k += self.n - 1
        self.data[k].s = self.data[k].m = self.data[k].l = self.data[k].r = v
        while k > 0:
            k = (k - 1) // 2
            l = k * 2 + 1
            r = k * 2 + 2
            self.data[k].s = self.data[l].s + self.data[r].s
            self.data[k].l = max(self.data[l].l, self.data[l].s + self.data[r].l)
            self.data[k].r = max(self.data[r].r, self.data[l].r + self.data[r].s)
            self.data[k].m = max(self.data[l].r + self.data[r].l, max(self.data[l].m, self.data[r].m))

    def query(self, l, r):
        L = l + self.n
        R = r + self.n
        ret_l = Node()
        ret_r = Node()
        while L < R:
            if R & 1:
                R -= 1
                ret_r = self.data[R - 1] + ret_r
            if L & 1:
                ret_l = ret_l + self.data[L - 1]
                L += 1
            L >>= 1
            R >>= 1
        return (ret_l + ret_r).m

if __name__ == "__main__":
    N = int(input())
    Seg = SegmentTree(N)
    arr = list(map(int, input().split()))
    for i in range(N):
        Seg.update(i, arr[i])

    Q = int(input())
    for _ in range(Q):
        l, r = map(int, input().split())
        print(Seg.query(l - 1, r))