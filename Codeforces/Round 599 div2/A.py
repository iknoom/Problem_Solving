import sys
input = sys.stdin.readline

for _ in range(int(input())):
    N = int(input())
    k = list(map(int, input().split()))
    k.sort(reverse=True)
    ans = 0
    for i in range(N):
        if k[i] < i + 1:
            ans = i
            break
    if k[N-1] >= N:
        ans = i+1
    print(ans)