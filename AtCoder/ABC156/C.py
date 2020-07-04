N = int(input())
X = list(map(int, input().split()))

ans = 10**18

for i in range(101):
    S = 0
    for x in X:
        S += (i - x) * (i - x)
    ans = min(ans, S)
print(ans)