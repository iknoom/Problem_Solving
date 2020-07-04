import sys
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    D = list(map(int, input().split()))
    ans = 0
    for i in range(3):
        if D[i]:
            D[i] -= 1
            ans += 1

    D.sort(reverse=True)
    for i in range(2):
        for j in range(i+1, 3):
            if D[i] and D[j]:
                D[i] -= 1
                D[j] -= 1
                ans += 1
    if D[0] and D[1] and D[2]:
        ans += 1

    print(ans)
