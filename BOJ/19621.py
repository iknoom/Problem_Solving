from bisect import bisect
from sys import stdin
input = stdin.readline

if __name__ == "__main__":
    N = int(input())
    kaigi = [tuple(map(int, input().split())) for _ in range(N)]
    kaigi.sort(key=lambda x: x[1])

    DP = [0]
    P = [0]
    for s, e, v in kaigi:
        if P[-1] <= s:
            next_v = DP[-1] + v
        else:
            i = bisect(P, s)
            next_v = DP[i - 1] + v
        DP.append(max(DP[-1], next_v))
        P.append(e)
    print(max(DP))