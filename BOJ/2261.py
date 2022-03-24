# http://people.csail.mit.edu/indyk/6.838-old/handouts/lec17.pdf
# https://www.cs.mcgill.ca/~cs251/ClosestPair/proofbox.html

from sys import stdin

input = stdin.readline
INF = float('inf')


class Point:
    __slots__ = ['x', 'y']

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def get_dist(self, p):
        return abs(self.x - p.x) ** 2 + abs(self.y - p.y) ** 2


class ClosestPair:
    __slots__ = ['n', 'points']

    def __init__(self, n, points):
        self.n = n
        self.points = points[:]
        self.points.sort(key=lambda p: p.x)

    def brute_force(self, l, r):
        ret = INF
        for i in range(l, r - 1):
            for j in range(i + 1, r):
                ret = min(ret, self.points[i].get_dist(self.points[j]))
        return ret

    def merge(self, l, mid, r):
        tmp = []
        i, j = l, mid
        while i < mid and j < r:
            if self.points[i].y < self.points[j].y:
                tmp.append(self.points[i])
                i += 1
            else:
                tmp.append(self.points[j])
                j += 1
        while i < mid:
            tmp.append(self.points[i])
            i += 1
        while j < r:
            tmp.append(self.points[j])
            j += 1
        self.points[l:r] = tmp[:]

    def divide_and_conquer(self, l, r):
        if r - l <= 16:
            self.points[l:r] = sorted(self.points[l:r], key=lambda p: p.y)
            return self.brute_force(l, r)
        # divide
        mid = (l + r) // 2
        mid_x = self.points[mid].x
        k1 = self.divide_and_conquer(l, mid)
        k2 = self.divide_and_conquer(mid, r)
        # combine
        min_dist = min(k1, k2)
        self.merge(l, mid, r)
        points_strip = [p for p in self.points[l:r] if abs(p.x - mid_x) ** 2 <= min_dist]
        for i in range(len(points_strip)):
            j = i - 1
            while j >= 0 and abs(points_strip[i].y - points_strip[j].y) ** 2 < min_dist:
                min_dist = min(min_dist, points_strip[i].get_dist(points_strip[j]))
                j -= 1
        return min_dist

    def apply(self):
        return self.divide_and_conquer(0, self.n)


if __name__ == '__main__':
    n = int(input())
    points = [Point(*map(int, input().split())) for _ in range(n)]
    closest_pair = ClosestPair(n, points)
    print(closest_pair.apply())
