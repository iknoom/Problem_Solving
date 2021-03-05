from sys import stdin
input = stdin.readline

class SegmentTree():
    def __init__(self, n):
        self.n = 2 ** (n - 1).bit_length()
        self.data = [0] * (2 * self.n)

    def update(self, k, a):
        k += self.n
        self.data[k] += a
        while k > 0:
            k //= 2
            self.data[k] = self.data[k * 2] + self.data[k * 2 + 1]

    def search(self, k, a):
        if k >= self.n:
            return k - self.n
        elif self.data[k * 2] >= a:
            return self.search(k * 2, a)
        else:
            return self.search(k * 2 + 1, a - self.data[k * 2])

if __name__ == '__main__':
    N = int(input())
    segment_tree = SegmentTree(1000001)
    for _ in range(N):
        query = list(map(int, input().split()))
        if query[0] == 1:
            B = query[1]
            t = segment_tree.search(1, B)
            print(t)
            segment_tree.update(t, -1)
        else:
            B, C = query[1], query[2]
            segment_tree.update(B, C)