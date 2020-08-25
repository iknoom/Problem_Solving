import sys
input = sys.stdin.readline
INF = 10

def solution():
    s = list(map(int, input().rstrip()))
    x = int(input())

    N = len(s)

    ans = [-1] * N
    flag = True
    for i in range(N):
        if i - x < 0: L = INF
        else: L = ans[i - x]
        if i + x >= N: R = INF
        else: R = ans[i + x]

        if s[i] == 1:
            if L == 1 or R == 1:
                continue
            elif L == -1:
                ans[i - x] = 1
            elif R == -1:
                ans[i + x] = 1
            else:
                flag = False

        if s[i] == 0:
            if L == 0 and R == 0:
                continue
            elif L != 1 and R != 1:
                if L == -1: ans[i - x] = 0
                if R == -1: ans[i + x] = 0
            else:
                flag = False
    if not flag:
        print(-1)
    else:
        for i in range(N):
            if ans[i] == -1:
                ans[i] = 1
        print(''.join(map(str, ans)))

if __name__ == "__main__":
     T = int(input())
     for _ in range(T):
         solution()