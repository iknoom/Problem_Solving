from sys import stdin
input = stdin.readline

class lottery:
    def __init__(self, w, q, i):
        self.w = w
        self.q = q
        self.i = i

    def __lt__(self, other):
        return self.w * (10000 - other.q) < other.w * (10000 - self.q)

if __name__ == '__main__':
    N = int(input())
    lotteries = []
    for i in range(N):
        w, q = map(int, input().split())
        lotteries.append(lottery(w, q, i + 1))
    lotteries.sort(reverse=True)
    answer = [l.i for l in lotteries]
    print(*answer)