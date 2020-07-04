import sys
input = sys.stdin.readline

T = int(input())
INF = 10**100

for _ in range(T):
    n, k = map(int, input().split())
    ans = INF
    for i in range(0, 10):
        S = 0
        over = 0
        for j in range(k + 1):
            S += (i + j) % 10
            if i + j >= 10:
                over += 1
        stack = [i]
        for R in range(100):
            flag = False
            for x in range(0, 9):
                if S + x * (k + 1) + over == n:
                    flag = True
                    stack.append(x)
                    FINAL = ''.join(map(str, stack[::-1]))
                    ans = min(ans, int(FINAL))
                    break
            if flag: break
            stack.append(9)
            S += 9 * (k + 1 - over)
    if ans == INF:
        print(-1)
    else:
        print(ans)

