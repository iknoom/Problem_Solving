import sys
input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    L = list(map(int,input().split()))
    vst = [False] * N
    ans = 1
    for i in range(N):
        if L[i] < i+1:
            ans = 0

    if ans:
        z = []
        cnt = 0
        for i in range(N):
            if not vst[L[i]-1]:
                z.append(L[i])
                vst[L[i]-1] = True
            else:
                while vst[cnt]:
                    cnt += 1
                z.append(cnt+1)
                vst[cnt] = True
        print(*z)
    else:
        print(-1)