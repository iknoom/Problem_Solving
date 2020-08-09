import sys, bisect
input = sys.stdin.readline


if __name__ == "__main__":
    N, H = map(int, input().split())
    lo = []
    hi = []
    for i in range(N):
        x = int(input())
        if i & 1: lo.append(x)
        else: hi.append(x)
    lo.sort()
    hi.sort()

    ans = float('inf')
    cnt = 1
    for h in range(1, H + 1):
        l = H - h + 1
        x = len(lo) - bisect.bisect_left(lo, l)
        y = len(hi) - bisect.bisect_left(hi, h)
        if x + y == ans:
            cnt += 1
        elif x + y < ans:
            ans = x + y
            cnt = 1
    print(ans, cnt)