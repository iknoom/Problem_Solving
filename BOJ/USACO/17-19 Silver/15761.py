N = int(input())
L = list(map(int,input().split()))
L.sort(reverse=True)
ans = N
for i in range(N):
    if L[i] < i:
        ans = i
        break
print(ans)