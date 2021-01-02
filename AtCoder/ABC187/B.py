from sys import stdin

input = stdin.readline

if __name__ == "__main__":
    N = int(input())
    P = [tuple(map(int, input().split())) for _ in range(N)]
    ans = 0
    for i in range(N - 1):
        for j in range(i + 1, N):
            x1, y1 = P[i]
            x2, y2 = P[j]
            if x1 == x2:
                continue
            if y1 == y2:
                ans += 1
                continue
            dx = x1 - x2
            dy = y1 - y2
            if -1 <= dy/dx <= 1:
                ans += 1
    print(ans)