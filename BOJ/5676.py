from sys import stdin

class SegmentTree():
    def __init__(self, n, func, init):
        self.n = 2 ** (n - 1).bit_length()
        self.init = init
        self.data = [init] * (2 * self.n)
        self.func = func

    def set(self, k, v):
        self.data[k + self.n - 1] = v

    def build(self):
        for k in reversed(range(self.n - 1)):
            self.data[k] = self.func(self.data[k * 2 + 1], self.data[k * 2 + 2])

    def update(self, k, a):
        k += self.n - 1
        self.data[k] = a

        while k > 0:
            k = (k - 1) // 2
            self.data[k] = self.func(self.data[k * 2 + 1], self.data[k * 2 + 2])

    def query(self, l, r):
        L = l + self.n
        R = r + self.n
        ret = self.init
        while L < R:
            if R & 1:
                R -= 1
                ret = self.func(ret, self.data[R - 1])
            if L & 1:
                ret = self.func(ret, self.data[L - 1])
                L += 1
            L >>= 1
            R >>= 1
        return ret

if __name__ == '__main__':
    readlines = stdin.readlines()
    readlines.reverse()
    while readlines:
        # input
        N, K = map(int, readlines.pop().split())
        arr = list(map(int, readlines.pop().split()))
        for i in range(N):
            arr[i] = 0 if arr[i] == 0 else arr[i] // abs(arr[i])

        # build segtree
        segment_tree = SegmentTree(N, int.__mul__, 1)
        for i in range(N):
            segment_tree.set(i, arr[i])
        segment_tree.build()
        # query
        for _ in range(K):
            query = readlines.pop().split()
            if query[0] == 'C':
                i, v = map(int, query[1:])
                if v:
                    v //= abs(v)
                segment_tree.update(i - 1, v)
            else:
                l, r = map(int, query[1:])
                ret = segment_tree.query(l - 1, r)
                print("-0+"[ret + 1], end='')
        print()